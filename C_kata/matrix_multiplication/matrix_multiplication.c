#include <stdio.h>

int main() {
    const int n = 3;
    const int m = 3;
    const int p = 3;

    // Number of columns (m) in A must equal number of rows (m) in B.

    double A[n][m];
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;

    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;

    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;

    double B[m][p];
    B[0][0] = 1;
    B[0][1] = 0;
    B[0][2] = 0;

    B[1][0] = 0;
    B[1][1] = 1;
    B[1][2] = 0;

    B[2][0] = 0;
    B[2][1] = 0;
    B[2][2] = 1;

    // Display matrix A.
    printf ("A = \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf ("%lf ", A[n][m]);
        }
        printf ("\n");
    }
    printf ("\n");

    // Display matrix B.
    printf ("B = \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf ("%lf ", B[m][p]);
        }
        printf ("\n");
    }
    printf ("\n");

    double C[n][p];

    // Multiply A by B giving C.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            double sum = 0;
            for (int k = 0; k < m; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    // Display matrix C.
    printf ("C = \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf ("%lf ", C[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    return 0;
}

