/*
 * Notes for completing this later (20121209.1023): I don't have time to finish this now;
 * I have to work on writing chapters.  Note, however, the structure in the main() function
 * below.  Obviously, the right way to do this is a recursive solution.  Note the pattern
 * evident in the control structure:
 *
 * n size of each rank
 * - -----------------
 * 1 (0) (1)
 * 2 (0) (1) (2) (1) [n is an even number]
 * 3 (0) (1) (2) (1) (2) (1) (2) (3)
 * 4 (0) (1) (2) (1) (2) (1) (2) (1) (2) (3) (2) (3) (2) (3) (4) (3) [n is an even number]
 * 
 * The `weird' slop-over-by-one ending occurs when `n' (the number of bits) is even.  That
 * should make it straightforward to write an expression to yield the next `direction' to
 * go based on the current rank, even buried deeply inside a recursive function.  Just
 * accumulate a counter or something.
 *
 * There are some useful functions already written below, particularly the twin ones for
 * determining all of the allowable states forward from a particular bit vector.  However,
 * the ultimate recursive algorithm, I think, will be more elegant, if subtle.
 *
 * The current implementation works: `make test'.  It is hard-coded to n=4 and only
 * partly completed, enough to show the pattern emerging.
 */

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

/*
 * The data structure is a tree rooted at binary 0...0 each node of which
 * contains a list of pointers to its child nodes.  The shape of the tree,
 * when fully populated, will get fatter as it grows away from the root,
 * then thinner and thinner again until it approaches either a single leaf
 * or at most (n-1) leaves coming off a single node at the far end.
 *
 * name: a null-terminated C string containing a binary number made up of
 *       '0' and '1' characters.
 *
 * next: a null-terminated list of pointers to more nodes.
 */

typedef struct node {
	char * name;
	struct node ** next;
} node;

/*
 * Usage: count_bits ('1', "00110") should return 2; count_bits ('0', 00110") should return 3.
 */

int count_bits (char one_or_zero, char * binary_number_string) {
	char * p = NULL;
	int num_found = 0;

	for (p = binary_number_string; *p; p++)
		if (one_or_zero == *p) ++num_found;
			
	return num_found;
}

/*
 * Usage: call this with a string like "00101".
 */

node * create_node (char * binary_number) {
	node * ptr_to_new_node = NULL;

	printf("creating new node %s\n", binary_number);

	if (!(ptr_to_new_node = (node *)malloc(sizeof(node))))
		ERROR_EXIT("malloc", (int)ptr_to_new_node);
	if (!(ptr_to_new_node->name = (char *)malloc(strlen(binary_number) + 1)))
		ERROR_EXIT("malloc", (int)ptr_to_new_node->name);
	strcpy(ptr_to_new_node->name, binary_number);
	ptr_to_new_node->next = NULL;
	return ptr_to_new_node;
}

void deallocate_node (node * p) {
	printf("freeing node %s\n", p->name);
	free (p->name);
	free (p);
	return;
}

/*
 * This function and the next should be combined into one.
 */

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

char flip_bit (char bit_character) {
	if ('0' == bit_character)
		return '1';
	else
		return '0';
}

int add_elements(char *);
int remove_elements(char *);
node * create_node (char *);
void deallocate_node(node *);
int count_bits (char, char *);
char flip_bit (char);

int main (int argc, char * argv[]) {
	int n = 4;
	node * root_of_tree = NULL;

	int num_0_bits = 0;
	int num_1_bits = 0;

	switch (argc) {
		case 2:
			n = atoi(argv[1]);
			break;
		default:
			fprintf (stdout, USAGE, argv[0]);
			break;
	}

	/* (0) */
	root_of_tree = create_node("0000");
	printf("rank 0 is done\n");

	/* (1) */
	/* there are four 0 bits to handle */
	num_0_bits = 4;
	root_of_tree->next = (node **)malloc(num_0_bits * sizeof(node *) + 1);
	/* march through the available 0 bits and create a new node for each */
	root_of_tree->next[0] = create_node("0001");
		num_0_bits = 3;
		root_of_tree->next[0]->next = (node **)malloc(num_0_bits * sizeof(node *) + 1);
		root_of_tree->next[0]->next[0] = create_node("0011");
			num_1_bits = 2;
			root_of_tree->next[0]->next[0]->next = (node **)malloc(num_1_bits * sizeof(node *) + 1);
			root_of_tree->next[0]->next[0]->next[0] = create_node("0010");
			root_of_tree->next[0]->next[0]->next[1] = create_node("0001");
			root_of_tree->next[0]->next[0]->next[3] = NULL;
		root_of_tree->next[0]->next[1] = create_node("0101");
			num_1_bits = 2;
			root_of_tree->next[0]->next[1]->next = (node **)malloc(num_1_bits * sizeof(node *) + 1);
			root_of_tree->next[0]->next[1]->next[0] = create_node("0100");
			root_of_tree->next[0]->next[1]->next[1] = create_node("0001");
			root_of_tree->next[0]->next[1]->next[3] = NULL;
		root_of_tree->next[0]->next[2] = create_node("1001");
			num_1_bits = 2;
			root_of_tree->next[0]->next[2]->next = (node **)malloc(num_1_bits * sizeof(node *) + 1);
			root_of_tree->next[0]->next[2]->next[0] = create_node("1000");
			root_of_tree->next[0]->next[2]->next[1] = create_node("0001");
			root_of_tree->next[0]->next[2]->next[3] = NULL;
		root_of_tree->next[0]->next[3] = NULL;
	root_of_tree->next[1] = create_node("0010");
		num_0_bits = 3;
		root_of_tree->next[1]->next = (node **)malloc(num_0_bits * sizeof(node *) + 1);
		root_of_tree->next[1]->next[0] = create_node("0011");
		root_of_tree->next[1]->next[1] = create_node("0110");
		root_of_tree->next[1]->next[2] = create_node("1010");
		root_of_tree->next[1]->next[3] = NULL;
	root_of_tree->next[2] = create_node("0100");
		num_0_bits = 3;
		root_of_tree->next[2]->next = (node **)malloc(num_0_bits * sizeof(node *) + 1);
		root_of_tree->next[2]->next[0] = create_node("0101");
		root_of_tree->next[2]->next[1] = create_node("0110");
		root_of_tree->next[2]->next[2] = create_node("1100");
		root_of_tree->next[2]->next[3] = NULL;
	root_of_tree->next[3] = create_node("1000");
		num_0_bits = 3;
		root_of_tree->next[3]->next = (node **)malloc(num_0_bits * sizeof(node *) + 1);
		root_of_tree->next[3]->next[0] = create_node("1001");
		root_of_tree->next[3]->next[1] = create_node("1010");
		root_of_tree->next[3]->next[2] = create_node("1100");
		root_of_tree->next[3]->next[3] = NULL;



	root_of_tree->next[4] = NULL;
	printf("rank 1 nodes created and hooked up\n");

	/* (2) */

	/* (1) */
	/* there are two 1-bits to handle */

	exit (EXIT_SUCCESS);
}

