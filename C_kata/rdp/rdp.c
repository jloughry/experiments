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

void getsym(void) {
	char c;
	char identifier_name[MAX_LINE_LENGTH];
	char string_accumulator[MAX_LINE_LENGTH];
	int identifier_name_length = 0;
	int string_length = 0;
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
		sym.type = left_paren;
		return;
	}

	if (')' == c) {
		sym.type = right_paren;
		return;
	}

	if ('"' == c) {
		memset(string_accumulator, 0, MAX_LINE_LENGTH);
		string_length = 0;
		GET_NEXT_CHARACTER(fp);	/* eat the beginning quotation mark */
		while (c != '"') {
			if ('\\' == c) {
				GET_NEXT_CHARACTER(fp);	/* eat the backslash */
				switch (c) {
					case 'n':
						c = '\n';	/* turn \n into a real newline */
						break;
					default:
						break;
				}
			}
			string_accumulator[string_length] = c;
			string_accumulator[++string_length] = '\0';
			GET_NEXT_CHARACTER(fp);
		}
		GET_NEXT_CHARACTER(fp);	/* eat the ending quotation mark */
		sym.type = string;
		strncpy(sym.nameval.string_value, string_accumulator, string_length);
		sym.nameval.string_value[string_length] = '\0';	/* strncpy won't terminate it */
		return;
	}

	if ('#' == c) {
		GET_NEXT_CHARACTER(fp);
		if ('t' == c || 'f' == c) {
			sym.type = boolean;
			if ('t' == c) {
				sym.nameval.boolean_value = 1;
			}
			else {
				sym.nameval.boolean_value = 0;
			}
			return;
		}
		else {
			PUSH_BACK(c, fp);
			PUSH_BACK('#', fp);	/* WARNING: pushing back twice is not guaranteed to work */
		}
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
			sym.type = number;
			sym.nameval.numeric_value = number_value;
			return;
		}
	}

	if ('d' == c) {	/* I hate to do it this way. */
		GET_NEXT_CHARACTER(fp);
		if ('e' == c) {
			GET_NEXT_CHARACTER(fp);
			if ('f' == c) {
				GET_NEXT_CHARACTER(fp);
				if ('i' == c) {
					GET_NEXT_CHARACTER(fp);
					if ('n' == c) {
						GET_NEXT_CHARACTER(fp);
						if ('e' == c) {
							sym.type = define;
							return;
						}
					}
				}
			}
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
		sym.type = identifier;
		strncpy(sym.nameval.identifier_name, identifier_name, identifier_name_length);
		sym.nameval.identifier_name[identifier_name_length] = '\0';	/* strncpy won't terminate it */
		return;
	}

	if ('+' == c || '-' == c) {	/* special case identifier names */
		identifier_name[0] = c;
		identifier_name[1] = '\0';
		identifier_name_length = 1;
		sym.type = identifier;
		strncpy(sym.nameval.identifier_name, identifier_name, identifier_name_length);
		sym.nameval.identifier_name[identifier_name_length] = '\0';
		return;
	}

	if ('.' == c) {	/* another special case identifier name is "..." */
		GET_NEXT_CHARACTER(fp);
		if ('.' == c) {
			GET_NEXT_CHARACTER(fp);
			if ('.' == c) {
				strcpy(identifier_name, "...");
				identifier_name_length = 3;
				sym.type = identifier;
				strncpy(sym.nameval.identifier_name, identifier_name, identifier_name_length);
				sym.nameval.identifier_name[identifier_name_length] = '\0';
				return;
			}
			else {
				PUSH_BACK(c, FP);
			}
		}
		else {					/* This is tricky because ANSI C doesn't guarantee */
			PUSH_BACK(c, FP);	/* that ungetc() will work more than once, but the */
		}						/* Scheme language requires that "..." be allowed. */
	}

	/* If we haven't found a token yet, we might be at the end of the file. */

	if (EOF != c) {
		fprintf(stderr, "error in getsym(): unrecognised character '%c' (%d)\n", c, (int)c);
	}
	return;
}

void display_token(struct token t) {
	switch (t.type) {
		case left_paren:
			printf("open paren\n");
			break;
		case right_paren:
			printf("close paren\n");
			break;
		case boolean:
			printf("boolean: %s\n", 1 == t.nameval.boolean_value ? "true" : "false");
			break;
		case number:
			printf("number: %lld\n", t.nameval.numeric_value);
			break;
		case string:
			printf("string: \"%s\"\n", t.nameval.string_value);
			break;
		case identifier:
			printf("identifier: \"%s\"\n", t.nameval.identifier_name);
			break;
		case define:
			printf("define\n");
			break;
		default:
			printf("Error: unknown token type %d in line %d\n", t.type, __LINE__);
			break;
	}
}

void destroy_token (struct token * token) {
	assert(token);
	free(token);
}

void program (void) {
	getsym();
	display_token(sym);
}

int main(int argc, char ** argv) {
	char * input_filename = NULL;

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
		fp = fopen(input_filename, "r");
		if (!fp) {
			fprintf(stderr, "Error: unable to open \"%s\" for input: %s\n",
				input_filename, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else {
		fp = stdin;
		prompt();
	}

	program();

	printf("Bye.\n");

	if (input_filename) {
		fclose(fp);
	}

	return EXIT_SUCCESS;
}

