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

	fprintf(stderr, "in evaluate() at %p: '%c'\n", line, *line);
	p = line;
	while (*p) {
		int n = 0;
		char * beginning_of_identifier = NULL;
		char * new_identifier = NULL;
		size_t length_of_identifier = 0;

		if (isspace((unsigned)*p)) {
			p++;	/* skip whitespace */
		}
		else if (isdigit((unsigned)*p)) {
			n = *p - '0';
			p++;
			while (*p && isdigit((unsigned)*p)) {
				n = 10 * n + *p - '0';
				p++;
			}
			fprintf(stderr, "found a number: n = %d\n", n);
		}
		else if (isalnum((unsigned)*p)) {
			beginning_of_identifier = p;
			while (*p && isalnum((unsigned)*p)) {
				p++;
			}
			length_of_identifier = p - beginning_of_identifier;
			assert(new_identifier = malloc(length_of_identifier + 1));
			strncpy(new_identifier, beginning_of_identifier, length_of_identifier);
			new_identifier[length_of_identifier] = '\0';
			fprintf(stderr, "found an identifier: \"%s\"\n", new_identifier);
		}
		else if ('(' == *p) {
			fprintf(stderr, "found the beginning of an s-expression at %p\n", p);
			p++;
			fprintf(stderr, "calling evaluate() at %p\n", p);
			evaluate(p);
		}
		else if (')' == *p) {
			fprintf(stderr, "found the end of an s-expression\n");
			p++;
		}
		else {
			fprintf(stderr, "skipping...\n");
			p++;
		}
	}
}

void prompt (void) {
	printf("> ");
}

