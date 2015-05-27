#include "string_reverse.h"

int main (int argc, char ** argv) {
    char * programme_name = NULL;
    char * s = NULL;
    char * t = NULL;
    int i = 0;
    char * p = NULL;

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

    t = malloc(strlen(s) + 1);
    if (!t) {
        ERROR_EXIT("malloc");
    }

    p = s;
    i = strlen(s);

    while (*p) {
        t[i-- - 1] = *p++;  /* alternatively: t[i---i] but that's evil */
    }
    t[strlen(s)] = '\0';    /* repeatedly calculating strlen(s) is neither thread safe nor efficient */

    printf ("s = \"%s\"\n", s);
    printf ("t = \"%s\"\n", t);

    if (t) {
        free(t);
        t = NULL;
    }

    return EXIT_SUCCESS;
}

