#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "Usage: %s s"

#define ERROR_EXIT(error_message) do { \
    fprintf (stderr, "Error in %s at line %d; %s() returned %d: %s\n", \
        __FILE__, __LINE__, error_message, errno, strerror(errno)); \
    exit (EXIT_FAILURE); \
} while (0)

