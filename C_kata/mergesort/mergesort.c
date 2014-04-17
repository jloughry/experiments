#include "mergesort.h"

void mergesort (int a[], int n) {
	int * working_array = NULL;

	assert(working_array = malloc(sizeof(int) * n));
	split_merge(a, 0, n, working_array);
	free(working_array);
}

void split_merge (int a[], int start, int end, int b[]) {
	int mid = 0;

	printf("split_merge: a = ");display(a, end - start);

	if (end - start < 2) {
		printf("split_merge: already sorted\n");
		return;
	}
	mid = (end - start) / 2;
	split_merge(a, start, mid, b);
	split_merge(a, mid, end, b);
	merge(a, start, mid, end, b);
	copy(b, start, end, a);
}

void copy (int b[], int start, int end, int a[]) {
	int k = 0;

	for (k = start; k < end; k++) {
		a[k] = b[k];
	}
}

void merge(int a[], int beginning, int midpoint, int end, int b[]) {
	int i = 0;
	int j = 0;
	int k = 0;

	printf("merge(a = ");
	display(a, end - beginning);
	printf("  beginning = %d, midpoint = %d, end = %d, b)\n", beginning, midpoint, end);

	i = beginning;
	j = midpoint;
	for (k = beginning; k < end; k++) {
		if (i < midpoint && (j >= end || a[i] <= a[j])) {
			b[k] = a[i];
			i++;
			printf("k = %d, selected first option\n", k);
		}
		else {
			b[k] = a[j];
			j++;
			printf("k = %d, selected second option\n", k);
		}
	}
}

void display (int a[], int n) {
	int i = 0;

	if (n <= 0) {
		printf("empty\n");
		return;
	}

	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

void swap (int * a, int * b) {
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int array_to_sort[] = {1, 3, 5, 2, -11, 8, 0, 0, -1, 7, 4, 5, 100, 2, 8, 33, 1, 19};
	unsigned n = sizeof(array_to_sort) / sizeof(int);

	display(array_to_sort, n);
	mergesort(array_to_sort, n);
	display(array_to_sort, n);

	return EXIT_SUCCESS;
}

