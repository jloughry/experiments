#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct hash_table {
	unsigned int size;			/* hash tables should know how big they are */
	struct list_node ** slots;	/* dynamically allocated array of list_node */
} hash_table;

typedef struct list_node {
    int data;
    struct list_node * next;
} list_node;

void create_hash_table (hash_table ** t, const unsigned int size);
void destroy_hash_table (hash_table ** t);
void insert (hash_table * t, int n);
int search_hash_table (hash_table * t, int n);
void search_hash_table_for (hash_table * t, int n);

void create_hash_table (hash_table ** t, const unsigned int size) {
	int i = 0;

	assert(size > 0);

	*t = malloc(sizeof(hash_table));
	assert(*t);

	(*t)->size = size;
	(*t)->slots = malloc(sizeof(list_node) * size);
	assert((*t)->slots);

	for (i = 0; i < size; i++) {
		(*t)->slots[i] = NULL;
	}
}

void destroy_hash_table (hash_table ** t) {
	int i = 0;
	list_node * p = NULL;
	list_node * q = NULL;

	assert(*t);
	assert((*t)->slots);

	for (i = 0; i < (*t)->size; i++) {
		if ((*t)->slots[i]) {
			p = (*t)->slots[i];
			while (p) {
				q = p->next;
				free(p);
				p = q;
			}
		}
	}
	free(*t);
	*t = NULL;
}

void insert (hash_table *t, int n) {
	int slot_number = 0;

	assert(t);
	assert(t->size > 0);
	assert(t->slots);

	slot_number = n % t->size;
	if (!((t->slots)[slot_number])) {
		(t->slots)[slot_number] = malloc(sizeof(list_node));
		assert((t->slots)[slot_number]);

		(t->slots)[slot_number]->data = n;
		(t->slots)[slot_number]->next = NULL;
	}
	else {
		while ((t->slots)[slot_number]) {
			if (n == (t->slots)[slot_number]->data) {
				return; /* already in the table, so do nothing */
			}
			else {
				(t->slots)[slot_number] = (t->slots)[slot_number]->next;
			}
		}
		assert(!((t->slots)[slot_number])); /* should be null at this point */

		(t->slots)[slot_number] = malloc(sizeof(list_node));
		assert((t->slots)[slot_number]);

		(t->slots)[slot_number]->data = n;
		(t->slots)[slot_number]->next = NULL;
	}
}

int search_hash_table (hash_table * t, int n) {
	int slot_number = 0;
	list_node * p = NULL;

	assert(t);
	assert(t->size > 0);
	assert(t->slots);

	slot_number = n % t->size;
	p = t->slots[slot_number];
	while (p) {
		if (n == p->data) {
			return 1;
		}
		else {
			p = p->next;
		}
	}
	return 0;
}

void search_hash_table_for (hash_table * t, int n) {
	if (search_hash_table(t, n)) {
		printf("%d is in the table\n", n);
	}
	else {
		printf("%d is not in the table\n", n);
	}
}

int main(void) {
	hash_table * table_1 = NULL;

	create_hash_table(&table_1, 100);

	insert(table_1, 89);
	insert(table_1, 12);
	insert(table_1, 12);
	insert(table_1, 12);
	insert(table_1, 12);
	insert(table_1, 177);

	search_hash_table_for(table_1, 77);
	search_hash_table_for(table_1, 177);
	search_hash_table_for(table_1, 89);
	search_hash_table_for(table_1, 12);

	destroy_hash_table(&table_1);
	assert(!table_1);

	return EXIT_SUCCESS;
}

