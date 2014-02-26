#include "skeleton.h"

/* This programme takes one required command line argument which should be an integer. */

int main(int argc, char ** argv)
{
	int n = 0;
	char * programme_name = NULL;

	programme_name = argv[0];

	switch (argc) {
		case 2:
			assert(isdigit((int)argv[1][0]) || (argv[1][0] == '-' && isdigit((int)argv[1][1])));
			n = atoi(argv[1]);
			printf ("The command line arguments were \"%s\" and %d\n", programme_name, n);
			break;
		default:
			usage(programme_name);
			exit (EXIT_FAILURE);
			break;
	}
	return EXIT_SUCCESS;
}

