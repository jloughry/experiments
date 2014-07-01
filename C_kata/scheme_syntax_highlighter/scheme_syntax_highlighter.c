/*

This is the grammar from the Wikipedia article on "Recursive Descent Parser".

programme = block "." .
 
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

enum symbols { ident, number, lparen, rparen, times, slash, plus, minus,
	eql, neq, lss, leq, gtr, geq, callsym, beginsym, semicolon, endsym,
	ifsym, whilesym, becomes, thensym, dosym, constsym, comma, varsym,
	procsym, period, oddsym,
};

typedef enum symbols Symbol;
 
Symbol sym;	/* global variable */

void getsym (void);
void error (const char * message);
void expression (void);
int accept(Symbol s);
int expect(Symbol s);
void display_symbol (Symbol s);
void factor(void);
void term(void);
void expression(void);
void condition(void);
void statement(void);
void block(void);
void programme(void);

/*
There is an example programme encoded inside this simple version of the getsym()
function:

const a = 1, b=2;
var x, y;

while 1 = 1 do
	y := y - 1.

*/
void getsym (void) {
	static int i = 0;
	Symbol symbol_list[] = {
		constsym, ident, eql, number, comma, ident, eql, number, semicolon,
		varsym, ident, comma, ident, semicolon,
			whilesym, ident, eql, number, dosym,
				ident, becomes, ident, minus, number, period,
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
		case ident:
			printf("ident\n");
			break;
		case number:
			printf("number\n");
			break;
		case lparen:
			printf("lparen\n");
			break;
		case rparen:
			printf("rparen\n");
			break;
		case times:
			printf("times\n");
			break;
		case slash:
			printf("slash\n");
			break;
		case plus:
			printf("plus\n");
			break;
		case minus:
			printf("minus\n");
			break;
		case eql:
			printf("eql\n");
			break;
		case neq:
			printf("neq\n");
			break;
		case lss:
			printf("lss\n");
			break;
		case leq:
			printf("leq\n");
			break;
		case gtr:
			printf("gtr\n");
			break;
		case geq:
			printf("geq\n");
			break;
		case callsym:
			printf("callsym\n");
			break;
		case beginsym:
			printf("beginsym\n");
			break;
		case semicolon:
			printf("semicolon\n");
			break;
		case endsym:
			printf("endsym\n");
			break;
		case ifsym:
			printf("ifsym\n");
			break;
		case whilesym:
			printf("whilesym\n");
			break;
		case becomes:
			printf("becomes\n");
			break;
		case thensym:
			printf("thensym\n");
			break;
		case dosym:
			printf("dosym\n");
			break;
		case constsym:
			printf("constsym\n");
			break;
		case comma:
			printf("comma\n");
			break;
		case varsym:
			printf("varsym\n");
			break;
		case procsym:
			printf("procsym\n");
			break;
		case period:
			printf("period\n");
			break;
		case oddsym:
			printf("oddsym\n");
			break;
		default:
			printf("Error in display_symbol(): unknown symbol %d\n", s);
			break;
	}
}
 
void factor (void) {
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
 
void term (void) {
	factor();
	while (sym == times || sym == slash) {
		getsym();
		factor();
	}
}
 
void expression (void) {
	if (sym == plus || sym == minus) {
		getsym();
	}
	term();
	while (sym == plus || sym == minus) {
		getsym();
		term();
	}
}
 
void condition (void) {
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
 
void statement (void) {
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
 
void block (void) {
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
 
void programme (void) {
	getsym();
	block();
	expect(period);
}

int main (void) {
	programme();

	return EXIT_SUCCESS;
}

