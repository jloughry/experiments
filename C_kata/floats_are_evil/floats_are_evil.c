#include <stdio.h>

int main(void)
{
    float a = 0x7FFFFFFF;

    printf ("648 - 64 = %d\n", 648 - 64);
    printf ("648 - 65 = %d\n", 648 - 65);

    printf ("a      = %f\n", a);
    printf ("a - 64 = %f\n", a - 64);
    printf ("a - 65 = %f\n", a - 65);

    return 0;
} 

