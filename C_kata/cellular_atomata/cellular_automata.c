/*
    COMP 1571-2 Lab 3 solution
    Joe Loughry
    6th October 2016
*/

#include <stdio.h>

int main () {
    const int size = 50;
    int old_cell[size];
    int new_cell[size];

    for (int i=0; i<size; i++) { // Initialise both arrays to zero.
        old_cell[i] = 0;
        new_cell[i] = 0; // Zero means "dead".
    }

    // Make one cell (randomly chosen) different.
    old_cell[36] = 1; // One means "alive".

    for (;;) {

        for (int i=0; i<size; i++) {    // Display the old array.
            printf ("%d", old_cell[i]);
        }
        printf ("\n");

        /* Update the array: if a cell has no neighbours or one neighbour,
           then it survives to the next generation. If it has two neighbours,
           it dies of crowding. */
           
        for (int i=1; i < size - 1; i++) { // Note guard band on each end.

            int number_of_neighbours = old_cell[i-1] + old_cell[i] + old_cell[i+1];
            switch (number_of_neighbours) {
                case 0:
                case 3:
                    new_cell[i] = 0; // dead
                    break;
                case 1:
                case 2:
                    new_cell[i] = 1; // alive
                    break;
                default:
                    printf ("This should never happen!\n");
                    break;
            }
        }

        for (int i=0; i<size; i++) {    // Copy new array back into old array.
            old_cell[i] = new_cell[i];
        }
    }
    return 0;
}

