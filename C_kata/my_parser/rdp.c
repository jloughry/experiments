/*

program -> form*

form -> definition | expression

definition -> variable_definition | <syntax_definition> | (begin <definition>*)
	| (let-syntax (<syntax_binding>*) <definition>*)
	| (letrec-syntax (<syntax_binding>*) <definition>*)
	| <derived_definition>

<variable_definition> -> (define <variable> <expression>)
	| (define (<variable> <variable>*) <body>)
	| (define (<variable> <variable>* . <variable>) <body>)

<variable> -> <identifier>

<body> -> <definition>* <expression>+

<syntax_definition> -> (define-syntax <keyword> <transformer_expression>)

<keyword> -> <identifier>

<syntax binding> -> (<keyword> <transformer_expression>)

<expression> -> <constant> | <variable> | (quote <datum>) | ' <datum>
	| (lambda <formals> <body>)
	| (if <expression> <expression> <expression>) | (if <expression> <expression>)
	| (set! <variable> <expression>)
	| <application>
	| (let-syntax (<syntax_binding>*) <expression>+)
	| (letrec-syntax (<syntax_binding>*) <expression>+)
	| <derived expression>

<constant> -> <boolean> | <number> | <character> | <string>

<formals> -> <variable> | (<variable>*) | (<variable>+ . <variable>)

<application> -> (<expression> <expression>*)

<identifier> -> <initial> <subsequent>* | + | - | ...

<initial> -> <letter> | ! | $ | % | & | * | / | : | < | = | > | ? | ~ | _ | ^

<subsequent> -> <initial> | <digit> | . | + | -

<letter> -> {A-Z}

<digit> -> {0-9}

<datum> -> <boolean> | <number> | <character> | <string> | <symbol> | <list> | <vector>

<boolean> -> #t | #f
<number> -> <num_2> | <num_8> | <num_10> | <num_16>

<character> -> #\ <any character> | #\newline | #\space

<string> -> " <string_character>* "

<string_character> -> \" | \\ | <any character other than " or \>

<symbol> -> <identifier>

<list> -> (<datum>*) | (<datum>+ . <datum>) | <abbreviation>

<abbreviation> -> ' <datum> | ` <datum> | , <datum> | ,@ <datum>

<vector> -> #(<datum>*)


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

