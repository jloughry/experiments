#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "Usage: %s [file]\n"
#define MAX_LINE_LENGTH 1000

/* These are the tokens that the lexical analyser recognises. */

enum tokens { left_paren, right_paren, identifier, number, boolean, string,
	define, character, variable_definition_sym, definition_sym, expression_sym,
	constant_sym, variable_sym,
};

/* This is the data structure in which tokens are provided to the parser. */

struct token {
	enum tokens type;
	union value_holder {
		char identifier_name[MAX_LINE_LENGTH];
		char string_value[MAX_LINE_LENGTH];
		long long numeric_value;
		int	boolean_value;
	} nameval;
};

/* GET_NEXT_CHARACTER() and PUSH_BACK() are implemented as macros
and not functions because they are used all over and it's useful
for debugging to get an accurate line number in the source code
when they fail. The lexer is a complicated programme with lots of
moving parts and this helps understand it. */

#define GET_NEXT_CHARACTER(file_pointer) \
	do { \
		c = fgetc(file_pointer); \
		if (EOF == c) { \
			if (feof(file_pointer)) { \
				;	/* this is not a problem; just continue */ \
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

/* Function prototypes. */

void prompt (void);
void getsym (void);
int is_identifier_initial (char c);
int is_identifier_subsequent (char c);
void destroy_token (struct token * token);
void display_token(struct token t);
void programme (void);
void form (void);
void variable (void);
void constant (void);
void defintion (void);
void expression (void);
void variable_definition (void);
int accept (struct token t);
int expect (struct token t);

/* global variables */

struct token sym;
FILE * fp = NULL;

