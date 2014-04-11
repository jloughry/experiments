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

/* This function needs to skip whitespace and commas, but only not inside strings. */

struct symbol * getsym(FILE * fp) {
	char c;
	struct symbol * new_symbol = NULL;
	char identifier_name[MAX_LINE_LENGTH];
	int identifier_name_length = 0;
	int number_value = 0;

	/* Scheme source code is not line-oriented, except in comments, where it is. */

	/* Skip whitespace and comments. It's tricky, because whitespace is not line-
	   oriented but comments are. */

	GET_NEXT_CHARACTER(fp);
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
		assert(new_symbol = malloc(sizeof(struct symbol)));
		new_symbol->type = left_paren;
		new_symbol->nameval.name = NULL;
	}
	else if (')' == c) {
		assert(new_symbol = malloc(sizeof(struct symbol)));
		new_symbol->type = right_paren;
		new_symbol->nameval.name = NULL;
	}
	else if (isdigit((unsigned)c)) {
		number_value = c - '0';
		GET_NEXT_CHARACTER(fp);
		while(isdigit((unsigned)c)) {
			number_value = 10 * number_value + c - '0';
			GET_NEXT_CHARACTER(fp);
		}
		PUSH_BACK(c, fp);
		assert(new_symbol = malloc(sizeof(struct symbol)));
		new_symbol->type = number;
		new_symbol->nameval.value = number_value;
	}
	else if (is_identifier_initial(c)) {
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
		assert(new_symbol = malloc(sizeof(struct symbol)));
		new_symbol->type = identifier;
		assert(new_symbol->nameval.name = malloc(identifier_name_length + 1));
		strncpy(new_symbol->nameval.name, identifier_name, identifier_name_length);
	}
	else if ('+' == c || '-' == c) {	/* special case identifier names */
		identifier_name[0] = c;
		identifier_name[1] = '\0';
		identifier_name_length = 1;
		assert(new_symbol = malloc(sizeof(struct symbol)));
		new_symbol->type = identifier;
		assert(new_symbol->nameval.name = malloc(identifier_name_length + 1));
		strncpy(new_symbol->nameval.name, identifier_name, identifier_name_length);
	}
	else if ('.' == c) {	/* another special case identifier name is "..." */
		GET_NEXT_CHARACTER(fp);
		if ('.' == c) {
			GET_NEXT_CHARACTER(fp);
			if ('.' == c) {
				strcpy(identifier_name, "...");
				identifier_name_length = 3;
				assert(new_symbol = malloc(sizeof(struct symbol)));
				new_symbol->type = identifier;
				assert(new_symbol->nameval.name = malloc(identifier_name_length + 1));
				strncpy(new_symbol->nameval.name, identifier_name, identifier_name_length);
			}
			else {
				PUSH_BACK(c, FP);
			}
		}
		else {					/* This is tricly because ANSI C doesn't guarantee */
			PUSH_BACK(c, FP);	/* that ungetc() will work more than once, but the */
		}						/* Scheme language requires that "..." be allowed. */
	}
	else if (EOF == c) {
			;	/* This is not a problem; it's how we know we've reached end of input. */
	}
	else {
		fprintf(stderr, "error in getsym(): unrecognised token '%c' (%d)\n", c, (int)c);
	}
	return new_symbol;
}

void destroy_symbol (struct symbol * symbol) {
	assert(symbol);
	if (identifier == symbol->type) {
		assert(symbol->nameval.name);
		free(symbol->nameval.name);
	}
	free(symbol);
}

int main(int argc, char ** argv) {
	char * input_filename = NULL;
	FILE * fp_in = NULL;
	struct symbol * next_symbol = NULL;

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

	while ((next_symbol = getsym(fp_in))) {
		switch (next_symbol->type) {
			case left_paren:
				printf("open paren\n");
				break;
			case right_paren:
				printf("close paren\n");
				break;
			case number:
				printf("number: %d\n", next_symbol->nameval.value);
				break;
			case identifier:
				printf("identifier: \"%s\"\n", next_symbol->nameval.name);
				break;
			default:
				printf("Error: unknown symbol type %d in line %d\n", next_symbol->type, __LINE__);
				break;
		}
		destroy_symbol(next_symbol);
	}
	printf("Bye.\n");

	if (input_filename) {
		fclose(fp_in);
	}

	return EXIT_SUCCESS;
}

