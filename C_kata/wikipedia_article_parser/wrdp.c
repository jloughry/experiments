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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { ident, number, lparen, rparen, times, slash, plus, minus,
	eql, neq, lss, leq, gtr, geq, callsym, beginsym, semicolon, endsym,
	ifsym, whilesym, becomes, thensym, dosym, constsym, comma, varsym,
	procsym, period, oddsym
} Symbol;
 
Symbol sym;	/* global variable */

void getsym (void);
void error (const char * message);
void expression (void);

void getsym (void) {
	sym = ident;
}

void error (const char * message) {
	fprintf (stderr, "Error: %s\n", message);
}
 
int accept(Symbol s) {
	if (sym == s) {
		getsym();
		return 1;
	}
	return 0;
}
 
int expect(Symbol s) {
	if (accept(s)) {
		return 1;
	}
	error("expect: unexpected symbol");
	return 0;
}
 
void factor(void) {
	if (accept(ident)) {
		;
	}
	else if (accept(number)) {
		;
	}
	else if (accept(lparen)) {
		expression();
		expect(rparen);
	}
	else {
		error("factor: syntax error");
		getsym();
	}
}
 
void term(void) {
	factor();
	while (sym == times || sym == slash) {
		getsym();
		factor();
	}
}
 
void expression(void) {
	if (sym == plus || sym == minus) {
		getsym();
	}
	term();
	while (sym == plus || sym == minus) {
		getsym();
		term();
	}
}
 
void condition(void) {
	if (accept(oddsym)) {
		expression();
	}
	else {
		expression();
		if (sym == eql || sym == neq || sym == lss || sym == leq || sym == gtr || sym == geq) {
			getsym();
			expression();
		}
		else {
			error("condition: invalid operator");
			getsym();
		}
	}
}
 
void statement(void) {
	if (accept(ident)) {
		expect(becomes);
		expression();
	}
	else if (accept(callsym)) {
		expect(ident);
	}
	else if (accept(beginsym)) {
		do {
			statement();
		} while (accept(semicolon));
		expect(endsym);
	}
	else if (accept(ifsym)) {
		condition();
		expect(thensym);
		statement();
	}
	else if (accept(whilesym)) {
		condition();
		expect(dosym);
		statement();
	}
	else {
		error("statement: syntax error");
		getsym();
	}
}
 
void block(void) {
	if (accept(constsym)) {
		do {
			expect(ident);
			expect(eql);
			expect(number);
		} while (accept(comma));
		expect(semicolon);
	}
	if (accept(varsym)) {
		do {
			expect(ident);
		} while (accept(comma));
		expect(semicolon);
	}
	while (accept(procsym)) {
		expect(ident);
		expect(semicolon);
		block();
		expect(semicolon);
	}
	statement();
}
 
void program(void) {
	getsym();
	block();
	expect(period);
}

