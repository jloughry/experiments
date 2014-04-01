#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100

typedef struct node node;

struct node {
    int data;
    node * next;
};

void insert (node * h, int d);

void insert (node * h, int d) {
    int slot = 0;
    node * p = NULL;

    slot_number = d % HASH_SIZE;
    if (h[slot_number]) {
        if (h[slot_number]->data == d)
            return;
        else {
            p = h[slot_number]->next;
            while(p && p->data != d) {
p = p->next;
            }
        }

        p = h[slot_number]->next;
        while (h[slot_number]->data != d && p) {

        }
    }
    else {
        h[slot] = malloc(sizeof(node));
        if (!h[slot]) {
            fprintf(stderr, "Error: in insert() at line %d, malloc() returned NULL\n",
__LINE__);
return;
        }
        h[slot]->data = d;
        h[slot]->next = NULL;
    }
}

int main(void) {
    node hash_table[HASH_SIZE];

    insert(&hash_table, "99");

    return EXIT_SUCCESS;
}

