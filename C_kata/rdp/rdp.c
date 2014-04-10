#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "Usage: %s [file]\n"
#define MAX_LINE_LENGTH 1000

/*
;;; (length '()) is 0
;;; (length '(a b c)) is 3

(define length
  (lambda (l)
    (if (null? l)
      0
      (+ 1 (length (cdr l))))))
*/

void read (char * line, FILE * fp);
void prompt (void);

void read (char * line, FILE * fp) {
	memset(line, 0, MAX_LINE_LENGTH);
	fgets(line, MAX_LINE_LENGTH, fp);
}

void prompt (void) {
	printf ("> ");
}

int main(int argc, char ** argv) {
	char * input_filename = NULL;
	FILE * fp_in = NULL;
	char input_line[MAX_LINE_LENGTH];

	switch (argc) {
		case 1:
			break;
		case 2:
			input_filename = argv[1];
			break;
		default:
			fprintf(stderr, USAGE, argv[0]);
			exit(EXIT_FAILURE);
	}
	if (input_filename) {
		fp_in = fopen(input_filename, "r");
		assert(fp_in);
	}
	else {
		fp_in = stdin;
	}

	while (1) {
		prompt();
		read(input_line, fp_in);
		if (!strlen(input_line)) {
			break;
		}
		printf("%s", input_line);
	}
	printf("Bye.\n");

	if (input_filename) {
		fclose(fp_in);
	}

	return EXIT_SUCCESS;
}

