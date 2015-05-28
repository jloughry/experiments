#include "string_reverse.h"

int main (int argc, char ** argv) {
    char * programme_name = NULL;
    char * s = NULL;
    char * t = NULL;
    size_t length = 0;
    char * p = NULL;
    char * q = NULL;

    programme_name = argv[0];

    switch (argc) {
        case 2:
            s = argv[1];
            if (!s) {
                fprintf (stderr, "\"%s\" doesn't look like a string to me.\n",
                    argv[1]);
                exit (EXIT_FAILURE);
            }
            else
                break;
        default:
            fprintf (stderr, USAGE "\n", programme_name);
            exit (EXIT_FAILURE);
            break;
    }

    length = strlen(s);

    t = malloc(length + 1);
    if (!t) {
        ERROR_EXIT("malloc");
    }

    p = s;
    q = t + length;
    *q-- = '\0';

    while (*p) {
        *q-- = *p++;
    }

    printf ("s = \"%s\"\n", s);
    printf ("t = \"%s\"\n", t);

    if (t) {
        free(t);
        t = NULL;
    }

    return EXIT_SUCCESS;
}

