#include "test_stdout_and_stderr.h"

int main(void) {
	fprintf(stdout, "Firstly, this goes to stdout.\n");
	fprintf(stderr, "Secondly, this goes to stderr.\n");
	return EXIT_SUCCESS;
}

