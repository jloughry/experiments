#include "factorial.h"

int factorial (int n) {
    int i = 0;

    for (i=0; i<n-1; i++) printf(" "); printf("%d\n", n);

    if (1 == n) {
        return n;
    }
    else {
        return n * factorial (n-1);
    }
}

int main (void) {
    int n = 30;

    printf ("%d! = %d\n", n, factorial(n));

    return EXIT_SUCCESS;
}
