#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "Usage: %s [file]\n"
#define MAX_LINE_LENGTH 1000

/*
GET_NEXT_CHARACTER() and PUSH_BACK() are implemented as macros and not
functions because they are used all over and it's useful for debugging
to get an accurate line number when they fail.
*/

#define GET_NEXT_CHARACTER(file_pointer) \
	do { \
		c = fgetc(file_pointer); \
		if (EOF == c) { \
			if (feof(file_pointer)) { \
				fprintf (stderr, "EOF at line %d\n", __LINE__); \
				exit(EXIT_FAILURE); \
			} \
			else if (ferror(file_pointer)) { \
				fprintf(stderr, "file error at line %d\n", __LINE__); \
				exit(EXIT_FAILURE); \
			} \
		} \
	} while (0)

#define PUSH_BACK(c, file_pointer) \
	do { \
		if (EOF == ungetc(c, fp)) { \
			fprintf(stderr, "file error in push_back() at line %d\n", __LINE__); \
			exit(EXIT_FAILURE); \
		} \
	} while (0)

enum symbols { left_paren, right_paren, identifier, number,
};

struct symbol {
	enum symbols type;
	union {
		char * name;
		int value;
	} nameval;
};

void prompt (void);
struct symbol * getsym (FILE * fp);

void prompt (void) {
	printf ("> ");
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
	else if (isalpha((unsigned)c)) {
		identifier_name[0] = c;
		identifier_name[1] = '\0';
		GET_NEXT_CHARACTER(fp);
		while(isalnum((unsigned)c)) {
			identifier_name_length = strlen(identifier_name);
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
	else {
		fprintf(stderr, "error in getsym(): unrecognised token '%c' (%d)\n", c, (int)c);
	}
	return new_symbol;
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
		assert(fp_in);
	}
	else {
		fp_in = stdin;
	}

	while ((next_symbol = getsym(fp_in))) {
		switch (next_symbol->type) {
			case left_paren:
				printf("main() found an open paren\n");
				break;
			case right_paren:
				printf("main() found a close paren\n");
				break;
			case number:
				printf("main() found a number: %d\n", next_symbol->nameval.value);
				break;
			case identifier:
				printf("main() found an identifier: \"%s\"\n", next_symbol->nameval.name);
				break;
			default:
				printf("Error: unknown symbol type %d in line %d\n", next_symbol->type, __LINE__);
				break;
		}
	}
	printf("Bye.\n");

	if (input_filename) {
		fclose(fp_in);
	}

	return EXIT_SUCCESS;
}

