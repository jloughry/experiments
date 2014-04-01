#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node {
	char * s;
	node * left;
	node * right;
};

int display_node (node * n);
node * create_node (char * s);
void destroy_node (node * n);
void destroy_tree (node ** n);
void insert (node ** n, char * s);
void inorder_traversal (node * n);

int display_node (node * n)
{
	int rc = EXIT_SUCCESS;

	if (n) {
		if (n->s) {
			printf("node %p: \"%s\"\n", n, n->s);
		}
		else {
			printf("Error: display_node(): null n->s\n");
			rc = EXIT_FAILURE;
		}
	}
	else {
		printf("Error: display_node(): null n\n");
		rc = EXIT_FAILURE;
	}
	return rc;
}

node * create_node (char * s)
{
	node * n = NULL;

	n = malloc(sizeof(node));
	if (n) {
		n->s = malloc(1 + strlen(s));
		if (n->s) {
			strncpy(n->s, s, strlen(s));
		}
		else {
			printf("Error: in create_node() at line %d: malloc returned 0\n", __LINE__);
		}
		n->left = NULL;
		n->right = NULL;
	}
	else {
		printf("Error: in create_node() at line %d, malloc returned 0\n", __LINE__);
	}
	return n;
}

void destroy_node (node * n)
{
	if (n) {
		if (n->s) {
			#ifdef DEBUG
				printf("freeing string space in node %p\n", n);
			#endif
			free (n->s);
		}
		else {
			printf("Error: in destroy_node() at line %d, null n->s\n", __LINE__);
		}
		#ifdef DEBUG
			printf("freeing node %p\n", n);
		#endif
		free(n);
	}
	else {
		printf("Error: in destroy_node() at line %d, null n\n", __LINE__);
	}
}

void destroy_tree (node ** n)
{
	if (*n) {
		destroy_tree(&((*n)->left));
		destroy_tree(&((*n)->right));
		destroy_node(*n);
		*n = NULL;
	}
}

void insert (node ** n, char * s)
{
	if (NULL == *n) {
		*n = create_node(s);
	}
	else {
		if ((*n)->s) {
			if (!strncmp((const char *)(*n)->s, s, strlen(s))) {
				return;
			}
			else if (strncmp(s, (const char *)(*n)->s, strlen(s)) < 0) {
				insert(&(*n)->left, s);
			}
			else {
				insert(&(*n)->right, s);
			}
		}
	}
}

void inorder_traversal (node * n)
{
	if (n) {
		inorder_traversal(n->left);
		display_node(n);
		inorder_traversal(n->right);
	}
}

int main(void)
{
	int rc = EXIT_SUCCESS;
	node * root = NULL;

	insert(&root, "one");
	insert(&root, "two");
	insert(&root, "three");
	insert(&root, "four");
	insert(&root, "five");
	insert(&root, "six");
	insert(&root, "seven");
	insert(&root, "eight");
	insert(&root, "nine");
	insert(&root, "");		/* empty strings won't be inserted */
	insert(&root, "");
	insert(&root, "");
	insert(&root, "");
	insert(&root, "ten");
	insert(&root, "eleven");
	insert(&root, "twelve");
	insert(&root, "thirteen");
	insert(&root, "fourteen");
	insert(&root, "fifteen");
	insert(&root, "sixteen");
	insert(&root, "seventeen");
	insert(&root, "eighteen");
	insert(&root, "nineteen");
	insert(&root, "twenty");
	insert(&root, "five");
	insert(&root, "five");
	insert(&root, "five");
	insert(&root, "five");
	insert(&root, "five");
	insert(&root, "five");
	insert(&root, "");

	inorder_traversal(root);

	destroy_tree(&root);

	#ifdef DEBUG
		printf("The pointer value of root is now %p\n", root);
	#endif

	return rc;
}

