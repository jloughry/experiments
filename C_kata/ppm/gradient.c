#include <stdio.h>

int main(void) {
    int x, y;

    printf( "P6 %d %d 255\n", 128, 128 );

    for (y = 0; y < 128; ++y )
        for (x = 0; x < 128; ++x )
            printf( "%c%c%c", x * 2, y * 2, 0 );

    return 0;
}
