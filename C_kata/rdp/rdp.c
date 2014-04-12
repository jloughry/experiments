#include "rdp.h"

void prompt (void) {
	printf ("> ");
}

/* returns true if c is allowed to start a Scheme identifier */

int is_identifier_initial (char c) {
	if (isalpha((unsigned)c) || '!' == c || '$' == c || '%' == c || '&' == c
		|| '*' == c || '/' == c || ':' == c || '<' == c || '=' == c
		|| '>' == c || '?' == c || '~' == c || '_' == c || '^' == c) {
		return 1;
	}
	return 0;
}

/* returns true if c is one of the other characters allowed in a Scheme identifier */

int is_identifier_subsequent (char c) {
	if (is_identifier_initial(c) || isdigit((unsigned)c)
		|| '.' == c || '+' == c || '-' == c) {
		return 1;
	}
	return 0;
}

struct token * getsym(FILE * fp) {
	char c;
	struct token * new_token = NULL;
	char identifier_name[MAX_LINE_LENGTH];
	int identifier_name_length = 0;
	long long number_value = 0;
	int minus_flag = 0;

	GET_NEXT_CHARACTER(fp);

	/* Skip whitespace and comments. It's tricky, because whitespace
	is not line-oriented but comments are. */

	while (isspace((unsigned)c) || ';' == c) {
		if (';' == c) {
			while (c != '\n') {
				GET_NEXT_CHARACTER(fp);
			}
			GET_NEXT_CHARACTER(fp);
		}
		while (isspace((unsigned)c)) {
			GET_NEXT_CHARACTER(fp);
		}
	}

	if ('(' == c) {
		assert(new_token = malloc(sizeof(struct token)));
		new_token->type = left_paren;
		new_token->nameval.name = NULL;
		return new_token;
	}

	if (')' == c) {
		assert(new_token = malloc(sizeof(struct token)));
		new_token->type = right_paren;
		new_token->nameval.name = NULL;
		return new_token;
	}

	if ('-' == c || '+' == c || isdigit((unsigned)c)) {
		number_value = 0;	/* defensive programming */
		switch(c) {
			case '-':
				minus_flag = 1;
				/* fall-through */
			case '+':
				GET_NEXT_CHARACTER(fp);
				if (!isdigit((unsigned)c)) {
					PUSH_BACK(c, fp);
					if (minus_flag) {	/* restore c so we can keep trying to match it */
						c = '-';
					}
					else {
						c = '+';
					}
				}
				/* fall-through */
			default:
				break;
		}
		if (isdigit((unsigned)c)) {
			number_value = c - '0';
			GET_NEXT_CHARACTER(fp);
			while(isdigit((unsigned)c)) {
				number_value = 10 * number_value + c - '0';
				GET_NEXT_CHARACTER(fp);
			}
			PUSH_BACK(c, fp);
			if (minus_flag) {
				number_value *= -1;
			}
			assert(new_token = malloc(sizeof(struct token)));
			new_token->type = number;
			new_token->nameval.value = number_value;
			return new_token;
		}
	}

	if (is_identifier_initial(c)) {
		memset(identifier_name, 0, MAX_LINE_LENGTH);	/* defensive programming */
		identifier_name[0] = c;
		identifier_name[1] = '\0';
		identifier_name_length = 1;
		GET_NEXT_CHARACTER(fp);
		while(is_identifier_subsequent(c)) {
			identifier_name[identifier_name_length] = c;
			identifier_name[++identifier_name_length] = '\0';
			GET_NEXT_CHARACTER(fp);
		}
		PUSH_BACK(c, fp);
		assert(new_token = malloc(sizeof(struct token)));
		new_token->type = identifier;
		assert(new_token->nameval.name = malloc(identifier_name_length + 1));
		strncpy(new_token->nameval.name, identifier_name, identifier_name_length);
		new_token->nameval.name[identifier_name_length] = '\0';	/* strncpy won't terminate it */
		return new_token;
	}

	if ('+' == c || '-' == c) {	/* special case identifier names */
		identifier_name[0] = c;
		identifier_name[1] = '\0';
		identifier_name_length = 1;
		assert(new_token = malloc(sizeof(struct token)));
		new_token->type = identifier;
		assert(new_token->nameval.name = malloc(identifier_name_length + 1));
		strncpy(new_token->nameval.name, identifier_name, identifier_name_length);
		new_token->nameval.name[identifier_name_length] = '\0';
		return new_token;
	}

	if ('.' == c) {	/* another special case identifier name is "..." */
		GET_NEXT_CHARACTER(fp);
		if ('.' == c) {
			GET_NEXT_CHARACTER(fp);
			if ('.' == c) {
				strcpy(identifier_name, "...");
				identifier_name_length = 3;
				assert(new_token = malloc(sizeof(struct token)));
				new_token->type = identifier;
				assert(new_token->nameval.name = malloc(identifier_name_length + 1));
				strncpy(new_token->nameval.name, identifier_name, identifier_name_length);
				new_token->nameval.name[identifier_name_length] = '\0';
				return new_token;
			}
			else {
				PUSH_BACK(c, FP);
			}
		}
		else {					/* This is tricly because ANSI C doesn't guarantee */
			PUSH_BACK(c, FP);	/* that ungetc() will work more than once, but the */
		}						/* Scheme language requires that "..." be allowed. */
	}

	/* If we haven't found a token yet, we might be at the end of the file. */

	if (EOF != c) {
		fprintf(stderr, "error in getsym(): unrecognised token '%c' (%d)\n", c, (int)c);
	}
	return NULL;
}

void destroy_token (struct token * token) {
	assert(token);
	if (identifier == token->type) {
		assert(token->nameval.name);
		free(token->nameval.name);
	}
	free(token);
}

int main(int argc, char ** argv) {
	char * input_filename = NULL;
	FILE * fp_in = NULL;
	struct token * next_token = NULL;

	switch (argc) {
		case 1:
			break;
		case 2:
			input_filename = argv[1];
			break;
		default:
			fprintf(stderr, USAGE, argv[0]);
			exit(EXIT_FAILURE);
	}
	if (input_filename) {
		fp_in = fopen(input_filename, "r");
		if (!fp_in) {
			fprintf(stderr, "Error: unable to open \"%s\" for input: %s\n",
				input_filename, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else {
		fp_in = stdin;
		prompt();
	}

	while ((next_token = getsym(fp_in))) {
		switch (next_token->type) {
			case left_paren:
				printf("open paren\n");
				break;
			case right_paren:
				printf("close paren\n");
				break;
			case number:
				printf("number: %lld\n", next_token->nameval.value);
				break;
			case identifier:
				printf("identifier: \"%s\"\n", next_token->nameval.name);
				break;
			default:
				printf("Error: unknown token type %d in line %d\n", next_token->type, __LINE__);
				break;
		}
		destroy_token(next_token);
	}
	printf("Bye.\n");

	if (input_filename) {
		fclose(fp_in);
	}

	return EXIT_SUCCESS;
}

