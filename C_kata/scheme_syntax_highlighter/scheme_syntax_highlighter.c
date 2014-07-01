#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum symbols { lparen, rparen, definesym, identsym, digitsym,
};

typedef enum symbols Symbol;
 
Symbol sym;	/* global variable */

void getsym (void);
void error (const char * message);
void expression (void);
int accept(Symbol s);
int expect(Symbol s);
void display_symbol (Symbol s);
void form(void);
void definition(void);
void variable_definition(void);
void expression(void);
void constant(void);
void variable(void);
void number(void);
void programme(void);

/*
There is an example programme encoded inside this simple version of the getsym()
function:

(define x 1)

*/

void getsym (void) {
	static int i = 0;
	Symbol symbol_list[] = {
		lparen, definesym, identsym, digitsym, rparen,
	};
	
	sym = symbol_list[i++];
}

void error (const char * message) {
	fprintf (stderr, "Error: %s\n", message);
}
 
int accept (Symbol s) {
	if (sym == s) {
		getsym();
		return 1;
	}
	return 0;
}
 
int expect (Symbol s) {
	if (accept(s)) {
		return 1;
	}
	error("expect: unexpected symbol");
	display_symbol(s);
	return 0;
}

void display_symbol (Symbol s) {
	switch (s) {
		case identsym:
			printf("identsym\n");
			break;
		case digitsym:
			printf("digitsym\n");
			break;
		case lparen:
			printf("lparen\n");
			break;
		case rparen:
			printf("rparen\n");
			break;
		case definesym:
			printf("definesym\n");
			break;
		default:
			printf("Error in display_symbol(): unknown symbol %d\n", s);
			break;
	}
}

void identifier(void) {
	if (accept(identsym)) {
		;
	}
	else {
		error("identifier: syntax error");
		getsym();
	}
}

void number(void) {
	if (accept(digitsym)) {
		;
	}
	else {
		error("number: syntax error");
		getsym();
	}
}

void constant(void) {
	number();
}

void variable(void) {
	identifier();
}
 
void expression (void) {
	if (accept(digitsym)) {
		;
	}
	else if (accept(identsym)) {
		;
	}
	else {
		error("expression: syntax error");
		getsym();
	}
}

void variable_definition (void) {
	expect(lparen);
	expect(definesym);
	expect(identsym);
	expression();
	expect(rparen);
}

void definition (void) {
	variable_definition(); /* ultimately, this will have more */
}

void form (void) {
	definition(); /* ultimately, this will be <definition>|<expression> */
}

void programme (void) {
	getsym();
	form(); /* ultimately, this will be <form>* but for now it's just <form> */
}

int main (void) {
	programme();

	return EXIT_SUCCESS;
}

