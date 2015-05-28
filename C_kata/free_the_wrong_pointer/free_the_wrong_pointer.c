#include "free_the_wrong_pointer.h"

int main (int argc, char ** argv) {
    char * programme_name = NULL;
    char * strtol_err_ptr = NULL;
    long n = 0;
    char * p = NULL;

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

    p = malloc(n);
    if (!p) {
        ERROR_EXIT("malloc");
    }
    strcpy(p, "abcdef");
    printf("before free(), p = %p; *p = \"%s\"\n", p, p);
    free(p + 3);    /* never do this */
    printf("after free(), p = %p; *p = \"%s\"\n", p, p);

    return EXIT_SUCCESS;
}

