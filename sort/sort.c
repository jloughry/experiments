#include<stdio.h>
#include<stdlib.h>

/* This is a list node. */

typedef struct node {
    int d;
    struct node * next;
} node;

/* function prototypes */

void list_append(node ** list, int value);
int length(node *list);
void display_list(node * list);
node * quicksort(node ** list);
node * list (int n);
node * concatenate (node * l1, node * l2, node * l3);
node * create_test_list(void);

/* appends value to list */

void list_append(node ** list, int value) {
	node * p = NULL;
	node * q = NULL;

	if (!*list) {
		*list = malloc(sizeof(node));
		if (!*list) {
			fprintf(stderr, "in list_append() at line %d, malloc() returned NULL\n", __LINE__);
			return;
		}
		else {
			(*list)->d = value;
			(*list)->next = NULL;
		}
	}
	else {
		p = *list;
		while(p) {
			q = p;
			p = p->next;
		}
		q->next = malloc(sizeof(node));
		if (!q->next) {
			fprintf(stderr, "in list_append() at line %d, malloc() returned NULL\n", __LINE__);
			return;
		}
		else {
			q->next->d = value;
			q->next->next = NULL;
		}
	}
}

/* displays a list */

void display_list(node * list) {
	if (!list) {
		printf("empty list");
	}
	else {
		while(list) {
			printf("%d ", list->d);
			list = list->next;
		}
	}
	printf ("\n");
}

/* returns the length of a list */

int length(node *list) {
	int n = 0;

	while (list) {
		n++;
		list = list->next;
	}
	return n;
}

/* given a list, returns another list that is sorted */

node * quicksort(node ** l) {
	int pivot = 0;
	node * p = NULL;
	node * less_than = NULL;
	node * greater_than = NULL;

	if (length(*l) <= 1) {
		return *l;
	}
	pivot = (*l)->d;

	p = (*l)->next; /* skip over the pivot */
	while (p) {
		if (p->d <= pivot) {
			list_append(&less_than, p->d);
		}
		else {
			list_append(&greater_than, p->d);
		}
		p = p->next;
	}
	return concatenate(quicksort(&less_than), list(pivot), quicksort(&greater_than));
}

/* makes a list of one element that is the given value */

node * list (int n) {
	node * l = NULL;

	list_append(&l, n);

	return l;
}

/* concatenates exactly three lists (any or all may be empty) */

node * concatenate (node * l1, node * l2, node * l3) {
	node * long_list = NULL;
	node * p = NULL;

	p = l1;
	while (p) {
		list_append(&long_list, p->d);
		p = p->next;
	}

	p = l2;
	while (p) {
		list_append(&long_list, p->d);
		p = p->next;
	}

	p = l3;
	while (p) {
		list_append(&long_list, p->d);
		p = p->next;
	}

	return long_list;
}

/* make a test list to be sorted later */

node * create_test_list(void) {
	node * list = NULL;

    list_append(&list, 10);
    list_append(&list, 9);
    list_append(&list, 8);
    list_append(&list, 7);
    list_append(&list, 6);
    list_append(&list, 5);
    list_append(&list, 4);
    list_append(&list, 3);
    list_append(&list, 2);
    list_append(&list, 1);
    list_append(&list, 0);

	return list;
}

int main(void) {
    node * list_to_sort = NULL;
	node * sorted_list = NULL;

	list_to_sort = create_test_list();
	sorted_list = quicksort(&list_to_sort);

    display_list(list_to_sort);
    display_list(sorted_list);

    return EXIT_SUCCESS;
}

