#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define USAGE "Usage: %s n\n"
#define ERROR_EXIT(what_failed, rc) \
	do { \
		fprintf (stderr, "A failure occurred in source code file \"%s\" at line %d: " \
			"the function %s() returned %d which resolves to \"%s\".\n", \
			__FILE__, __LINE__, what_failed, rc, strerror(errno)); \
		exit (EXIT_FAILURE); \
	} while (0);

int add_elements (char * starting_string) {
	int n, i;
	char * temp_string = NULL;
	
	n = strlen(starting_string);
	temp_string = (char *)malloc(n + 1);
	if (!temp_string)
		ERROR_EXIT("malloc", (int)temp_string);

	printf("adding elements, the allowable states from here are:\n");
	strcpy(temp_string, starting_string);
	for (i = n-1; i>=0; i--) {
		if (starting_string[i] == '0') {
			temp_string[i] = '1';
			printf("%s\n", temp_string);
		}
		strcpy(temp_string, starting_string);
	}
	
	free(temp_string);
	return 0;
}

int remove_elements (char * starting_string) {
	int n, i;
	char * temp_string = NULL;
	
	n = strlen(starting_string);
	temp_string = (char *)malloc(n + 1);
	if (!temp_string)
		ERROR_EXIT("malloc", (int)temp_string);

	printf("removing elements, the allowable states from here are:\n");
	strcpy(temp_string, starting_string);
	for (i = n-1; i>=0; i--) {
		if (starting_string[i] == '1') {
			temp_string[i] = '0';
			printf("%s\n", temp_string);
		}
		strcpy(temp_string, starting_string);
	}
	
	free(temp_string);
	return 0;
}

int add_elements(char *);
int remove_elements(char *);

int main (int argc, char * argv[]) {
	int n = 0;
	char * bit_string = NULL;
	int i = 0;

	switch (argc) {
		case 2:
			n = atoi(argv[1]);
			break;
		default:
			fprintf (stdout, USAGE, argv[0]);
			break;
	}

	bit_string = (char *)malloc(n + 1);
	if (!bit_string)
		ERROR_EXIT("malloc", (int)bit_string);

	for (i=0; i<n; i++)
		bit_string[i] = '0';
	bit_string[n] = '\0';

	bit_string[2]='1';
	bit_string[4]='1';
	printf("bit_string is \"%s\"\n", bit_string);

	add_elements(bit_string);
	remove_elements(bit_string);

	free(bit_string);

#ifdef TEST
	/* test ERROR_EXIT */
	errno=1;
	ERROR_EXIT("test",2);
#endif

	exit (EXIT_SUCCESS);
}

