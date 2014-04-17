#include "shellsort.h"

void shellsort (int a[], int n) {
	int i = 0;
	int j = 0;
	int gap = 0;

	/* start with gap = half of n, and chop the gap in half each time */

	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i ++) {
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
				swap(&(a[j]), &(a[j + gap]));
			}
		}
	}
}

void display (int a[], int n) {
	int i = 0;

	assert(n > 0);

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
	shellsort(array_to_sort, n);
	display(array_to_sort, n);

	return EXIT_SUCCESS;
}

