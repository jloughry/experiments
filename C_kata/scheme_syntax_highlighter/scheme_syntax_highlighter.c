#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
	#define LOG(message) do { fprintf(stdout, "%s\n", message); } while (0)
#else
	#define LOG(message)
#endif

enum symbols { lparen, rparen, definesym, identsym, numbersym, lambdasym,
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
void formals(void);
void body(void);
void constant(void);
void variable(void);
void number(void);
void programme(void);
void emit(Symbol s);

/*
There is an example programme encoded inside this simple version of the getsym()
function:

(define x 1)

(define x
	(lambda (l)
		0))

(define length
	(lambda (l)
		(if (null? l)	; this is a comment
			0
			(+ 1 (length (cdr l))))))
*/

void getsym (void) {
	static int i = 0;
	Symbol symbol_list[] = {
		lparen, definesym, identsym,
			lparen, lambdasym, lparen, identsym, rparen,
				numbersym, rparen, rparen,
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
		case numbersym:
			printf("numbersym\n");
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
		case lambdasym:
			printf("lambdasym\n");
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
	if (accept(numbersym)) {
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

void formals(void) {
	LOG("entering formals()");
	expect(lparen);
	expect(identsym);
	expect(rparen);
	LOG("leaving formals()");
}

void body(void) {
	LOG("entering body()");
	expression();
	LOG("leaving body()");
}
 
void expression (void) {
	LOG("entering expression()");
	if (accept(lparen)) {
		expect(lambdasym);
		formals();
		body();
		expect(rparen);
	}
	else if (accept(numbersym)) {
		;
	}
	else if (accept(identsym)) {
		;
	}
	else {
		error("expression: syntax error");
		getsym();
	}
	LOG("leaving expression()");
}

void variable_definition (void) {
	LOG("entering variable_definition()");
	expect(lparen);
	expect(definesym);
	expect(identsym);
	expression();
	expect(rparen);
	LOG("leaving variable_definition()");
}

void definition (void) {
	LOG("entering definition()");
	variable_definition(); /* ultimately, this will have more */
	LOG("leaving definition()");
}

void form (void) {
	LOG("entering form()");
	definition(); /* ultimately, this will be <definition>|<expression> */
	LOG("leaving form()");
}

void programme (void) {
	LOG("entering programme()");
	getsym();
	form(); /* ultimately, this will be <form>* but for now it's just <form> */
	LOG("leaving programme()");
}

void emit (Symbol s) {
	switch (s) {
		case lparen:
			printf("<span class=\"punct\">(</span>");
			break;
		case rparen:
			printf("<span class=\"punct\">)</span>");
			break;
		case identsym:
			printf("span class=\"identifier\">identifier</span>");
			break;
		case definesym:
			printf("span class=\"keyword\">define</span>");
			break;
		case lambdasym:
			printf("span class=\"keyword\">lambda</span>");
			break;
		default:
			printf("Error in emit(): unknown symbol %d\n", s);
			break;
	}
}

int main (void) {
	programme();

	return EXIT_SUCCESS;
}

