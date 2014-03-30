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

payload pop (stack * s)
{
	payload return_val = 0;

	if (0 == s->top) {
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

	if (s->top == 0) {
		printf("The stack is empty.\n");
	}
	else {
		for (i=0; i<s->top; i++)
			printf("%d ", s->contents[i]);
		printf ("\n");
	}
}

void destroy_stack (stack ** s)
{
	return;
}

int main (void)
{
	stack * s = NULL;

	s = create_stack(10);
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

