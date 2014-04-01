#include <stdio.h>
#include <stdlib.h>

typedef int payload;

struct stack {
	payload * contents;
	int top;
	size_t depth;
};

typedef struct stack stack;

void push (stack * s, payload d);
payload pop (stack * s);
void display_stack (stack s);
payload pop (stack * s);
stack * create_stack (size_t size);
int empty (stack * s);

/* implement a queue using a pair of stacks */
void enqueue(stack * s1, stack * s2, payload d);
payload dequeue(stack *s1, stack *s2);

stack * create_stack (size_t depth)
{
	stack * s = NULL;

	s = malloc(sizeof(stack));
	if (!s)
		fprintf(stderr, "in new_stack() at line %d, malloc() returned NULL\n", __LINE__);

	s->contents = malloc(depth * sizeof(payload));
	if (!s)
		fprintf(stderr, "in new_stack() at line %d, malloc() returned NULL\n", __LINE__);

	s->depth = depth;
	s->top = 0;

	return s;
}

void push (stack * s, payload d)
{
	if (s->top >= s->depth) {
		fprintf(stderr, "in push() at line %d, stack is full (%d items)\n", __LINE__, s->depth);
		return;
	}
	s->contents[s->top] = d;
	s->top++;
}

int empty (stack * s)
{
	if (0 == s->top) {
		return 1;
	}
	return 0;
}

payload pop (stack * s)
{
	payload return_val = 0;

	if (empty(s)) {
		fprintf(stderr, "in pop() at line %d, stack is empty\n", __LINE__);
	}
	else {
		s->top--;
		return_val = s->contents[s->top];
		s->contents[s->top] = 0;
	}
	return return_val;
}

void display (stack * s)
{
	int i = 0;

	if (empty(s)) {
		printf("The stack is empty.\n");
	}
	else {
		printf ("The stack contains ");
		for (i=0; i<s->top; i++) {
			printf("%d ", s->contents[i]);
		}
		printf ("\n");
	}
}

void destroy_stack (stack ** s)
{
	if (*s) {
		if ((*s)->contents) {
			free((*s)->contents);
			(*s)->depth = 0;
			(*s)->top = 0;
			*s = NULL;
		}
		else {
			printf("Error: in destroy_stack() at line %d, contents pointer was NULL\n", __LINE__);
		}
	}
	else {
		printf("Error: in destroy_stack() at line %d, *s is NULL\n", __LINE__);
	}
	return;
}

void enqueue(stack * s1, stack * s2, payload d) {
	push(s1, d);
}

payload dequeue(stack *s1, stack *s2) {
	while(!empty(s1)) {
		push(s2, pop(s1));
	}
	return pop(s2);
}

int main (void)
{
	stack * s = NULL;
	stack * q1 = NULL;
	stack * q2 = NULL;

	s = create_stack(10);

	/* implement a queue using a pair of stacks */

	q1 = create_stack(100);
	q2 = create_stack(100);

	/* enqueue some values */

	enqueue(q1, q2, 10);
	enqueue(q1, q2, 20);
	enqueue(q1, q2, 30);

	/* dequeue them in the same order */
	
	printf("dequeing %d\n", dequeue(q1, q2));
	printf("dequeing %d\n", dequeue(q1, q2));
	printf("dequeing %d\n", dequeue(q1, q2));
	printf("trying to dequeue another value %d\n", dequeue(q1, q2));

	/* push some values onto a vanilla stack and then pop them */

	push(s, 11);
	push(s, 17);
	push(s, 999);
	push(s, 0);
	push(s, 21);
	display(s);
	printf("pop %d\n", pop(s));
	printf("pop %d\n", pop(s));
	printf("pop %d\n", pop(s));
	display(s);
	printf("pop %d\n", pop(s));
	printf("pop %d\n", pop(s));
	display(s);
	destroy_stack(&s);

	return EXIT_SUCCESS;
}

