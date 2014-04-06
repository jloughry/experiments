#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH	1000

void prompt (void);
void read (char * line);
void evaluate (char * line);

int main (void) {
	char line[MAX_LINE_LENGTH];

	while (1) {
		prompt();
		read(line);
		if (!strlen(line)) {
			break;
		}
		evaluate(line);
	}
	printf("Bye.\n");

	return EXIT_SUCCESS;
}

void read (char * line) {
	/*
	 * fgets() is a little tricky. It won't overrun the buffer, but if EOF is
	 * encountered, it returns the buffer as-is with no other indication. So
	 * we fill the buffer with nulls first to defend against getting old data.
	 */
	memset(line, 0, MAX_LINE_LENGTH);
	fgets(line, MAX_LINE_LENGTH, stdin);
}

void evaluate (char * line) {
	char * p = NULL;

	p = line;
	while (*p) {
		int n = 0;

		switch(*p) {
			case ' ': case '\t': case '\n': /* skip whitespace */
				p++;
				break;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				n = *p - '0';
				p++;
				while (*p && *p >= '0' && *p <= '9') {
					n = 10 * n + *p - '0';
					p++;
				}
				fprintf(stderr, "found a number: n = %d\n", n);
				break;
			case '(':
				while (*p && *p != ')') {
					p++;
				}
				fprintf(stderr, "found an s-expression\n");
				break;
			default:
				break;
		}
		p++;
	}
}

void prompt (void) {
	printf("> ");
}

