#include <math.h>
#include <stdio.h>

int main(void)
{
    double x = 0.75;
    double t1 = 0.50000025;
    int i, j;
    int n8 = 93 * 100;

    for (i = 0;; i++) {
        for (j = 0; j < n8; j++) {
            x = sqrt (exp (log (x) / t1));
        }
        printf("%d %f\n", i, x);
    }
    return 0;
}

