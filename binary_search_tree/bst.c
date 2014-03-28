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
			printf("in create_node() at line %d: malloc returned 0\n", __LINE__);
		}
		n->left = NULL;
		n->right = NULL;
	}
	else {
		printf("in create_node() at line %d, malloc returned 0\n", __LINE__);
	}
	return n;
}

void destroy_node (node * n)
{
	if (n) {
		if (n->s) {
			printf("freeing string space in node %p\n", n);
			free (n->s);
		}
		else {
			printf("in destroy_node() at line %d, null n->s\n", __LINE__);
		}
		printf("freeing node %p\n", n);
		free(n);
	}
	else {
		printf("in destroy_node() at line %d, null n\n", __LINE__);
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
	return;
}

int main(void)
{
	int rc = EXIT_SUCCESS;
	node * root = NULL;

	root = create_node("This is a string");
	root->left = create_node("This the left substring");
	root->right = create_node("This the right substring");
	display_node(root);
	display_node(root->left);
	display_node(root->right);
	destroy_tree(&root);

	printf("The pointer value of root is now %p\n", root);

	return rc;
}

