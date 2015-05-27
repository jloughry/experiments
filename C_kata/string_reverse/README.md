`new_C_programme_template`
--------------------------

This is my standard template for starting a new C programme. It has command
line arguments, a USAGE message, and sensible error handling (for C).

## Header File

````c
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "Usage: %s n"

#define ERROR_EXIT(error_message) do { \
    fprintf (stderr, "Error in %s at line %d; %s() returned %d: %s\n", \
        __FILE__, __LINE__, error_message, errno, strerror(errno)); \
    exit (EXIT_FAILURE); \
} while (0)

````

## C Source

````c
#include "new_C_programme_template.h"

int main (int argc, char ** argv) {
    char * programme_name = NULL;
    char * strtol_err_ptr = NULL;
    long n = 0;

    programme_name = argv[0];

    switch (argc) {
        case 2:
            n = strtol(argv[1], &strtol_err_ptr, 10);
            if (strtol_err_ptr == argv[1]) {
                fprintf (stderr, "\"%s\" doesn't look like a number to me.\n",
                    argv[1]);
                exit (EXIT_FAILURE);
            }
            else if ( n == LONG_MAX || n == LONG_MIN) {
                ERROR_EXIT ("strtol");
            }
            else
                break;
        default:
            fprintf (stderr, USAGE "\n", programme_name);
            exit (EXIT_FAILURE);
            break;
    }

    printf ("n = %ld\n", n);

    return EXIT_SUCCESS;
}

````

