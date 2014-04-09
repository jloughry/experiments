/*

This is the grammar from the Wikipedia article on "Recursive Descent Parser".

program = block "." .
 
block =
	["const" ident "=" number {"," ident "=" number} ";"]
	["var" ident {"," ident} ";"]
	{"procedure" ident ";" block ";"} statement .
 
statement =
	ident ":=" expression
	| "call" ident
	| "begin" statement ";" {statement ";"} "end"
	| "if" condition "then" statement
	| "while" condition "do" statement .
 
condition =
	"odd" expression
	| expression ("="|"#"|"<"|"<="|">"|">=") expression .
 
expression = ["+"|"-"] term {("+"|"-") term} .
 
term = factor {("*"|"/") factor} .
 
factor =
	ident
	| number
	| "(" expression ")" .

*/

/*

This is my grammar.

program = expression

expression = lparen stuff rparen

stuff = identifier | number | expression

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum symbols { identifier, number, lparen, rparen, expr
};

typedef enum symbols Symbol;
 
Symbol sym;	/* global variable */

void getsym (void);
void error (const char * message);
int accept (Symbol s);
int expect (Symbol s);
void program (void);

void getsym (void) {
	static int i = 0;
	Symbol symbol_list[] = { lparen, identifier, number, lparen, identifier, rparen, rparen };
	
	sym = symbol_list[i++];	/* (abc 123 (abc)) */
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
	return 0;
}

void stuff (void) {
	if (accept(identifier)) {
		;
	}
	else if (accept(number)) {
		;
	}
	else if (accept(lparen)) {
		expect(expr);
		expect(rparen);
	}
	else {
		error("middle: syntax error");
		getsym();
	}
}
 
void program (void) {
	getsym();
	expect(expr);
}

int main (void) {
	program();

	return EXIT_SUCCESS;
}

