#include <stdio.h>
#include <stdlib.h>

char msg[] = {76, 101, 116, 116, 104, 101, 98, 101, 115, 116, 115, 116, 97,
    114, 116, 117, 112, 115, 97, 112, 112, 108, 121, 116, 111, 121, 111, 117, 0};

int main (void) {
    fprintf (stderr, "%s\n", msg);

    return EXIT_SUCCESS;
}

