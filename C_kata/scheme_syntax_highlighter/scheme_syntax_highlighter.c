#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
	#define LOG(message) do { fprintf(stdout, "%s\n", message); } while (0)
#else
	#define LOG(message)
#endif

enum symbols { lparen, rparen, definesym, variablesym, numbersym, lambdasym, ifsym,
};

struct symbol {
	enum symbols kind;
	char * name;
};

typedef struct symbol Symbol;
 
Symbol sym;	/* global variable */

void getsym (void);
void error (const char * message);
void expression (void);
int accept(enum symbols s);
int expect(enum symbols s);
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
void emit_html(enum symbols type, char * name);

/*
There is an example programme encoded inside this simple version of the getsym()
function:

(define length
	(lambda (l)
		(if (null? l)	; this is a comment
			0
			(+ 1 (length (cdr l))))))
*/

void getsym (void) {
	static int i = 0;
	Symbol symbol_list[] = {
		{lparen, NULL}, {definesym, NULL}, {variablesym, "length"},
			{lparen, NULL}, {lambdasym, NULL}, {lparen, NULL}, {variablesym, "l"}, {rparen, NULL},
				{lparen, NULL}, {ifsym, NULL}, {lparen, NULL}, {variablesym, "null?"},
				{variablesym, "l"}, {rparen, NULL},
				{numbersym, "0"},
				{lparen, NULL}, {variablesym, "+"}, {numbersym, "1"}, {lparen, NULL},
				{variablesym, "length"}, {lparen, NULL}, {variablesym, "cdr"}, {variablesym, "l"},
				{rparen, NULL}, {rparen, NULL}, {rparen, NULL}, {rparen, NULL}, {rparen, NULL},
				{rparen, NULL},
	};
	
	sym = symbol_list[i++];
}

void error (const char * message) {
	fprintf (stderr, "Error: %s\n", message);
}
 
int accept (enum symbols s) {
	if (sym.kind == s) {
		getsym();
		return 1;
	}
	return 0;
}
 
int expect (enum symbols s) {
	if (accept(s)) {
		return 1;
	}
	error("expect: unexpected symbol");
	display_symbol(sym);
	return 0;
}

void display_symbol (Symbol s) {
	switch (s.kind) {
		case variablesym:
			printf("variablesym: name = \"%s\"\n", s.name);
			break;
		case numbersym:
			printf("numbersym: name = \"%s\"\n", s.name);
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
		case ifsym:
			printf("ifsym\n");
			break;
		default:
			printf("Error in display_symbol(): unknown symbol %d (\"%s\")\n", s.kind, s.name);
			break;
	}
}

void identifier(void) {
	if (accept(variablesym)) {
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
	expect(variablesym);
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
		if (accept(lambdasym)) {
			formals();
			body();
		}
		else if (accept(ifsym)) {
			expression();
			expression();
			expression(); /* the third expression should really be optional here */
		}
		else while (sym.kind == variablesym || sym.kind == numbersym || sym.kind == lparen) {
			getsym();
			if (sym.kind == rparen)
				break;
			expression();
		}
		expect(rparen);
	}
	else if (accept(numbersym)) {
		;
	}
	else if (accept(variablesym)) {
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
	expect(lparen); emit_html(lparen, "(");
	expect(definesym); emit_html(definesym, "define");
	expect(variablesym);
	expression();
	expect(rparen); emit_html(rparen, ")");
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

void emit_html(enum symbols type, char * name) {
	switch (type) {
		case lparen:
		case rparen:
			printf("<span class=\"punct\">%s</span>", name);
			break;
		case variablesym:
			printf("<span class=\"identifier\">%s</span>", name);
			break;
		case numbersym:
			printf("<span class=\"constant\">%s</span>", name);
			break;
		case definesym:
		case ifsym:
		case lambdasym:
			printf("<span class=\"keyword\">%s</span>", name);
			break;
		default:
			fprintf(stderr, "emit_html() encountered an unknown type (%d) [name = \"%s\"]\n",
				type, name);
			break;
	}
}

int main (void) {
	programme();

	return EXIT_SUCCESS;
}

