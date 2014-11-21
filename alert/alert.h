#include <iostream>
#include <string>
#include <windows.h>

#define ERROR_EXIT(error_message) do { \
    fprintf (stderr, "Error in %s at line %d; %s() returned %d: %s\n", \
        __FILE__, __LINE__, error_message, errno, strerror(errno)); \
    exit (EXIT_FAILURE); \
} while (0)

