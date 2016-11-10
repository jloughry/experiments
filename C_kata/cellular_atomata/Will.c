#include <stdio.h>
#include <stdbool.h>

/* COMP 1571
 * Lab 3: Elementary Cellular Automata
 * by Will Mitchell
 *
 * Instructor's note: Pass any argument on the command line to have the output
 * displayed one row at a time to show the calculations. Hit CTRL+D (EOF) to
 * advance. Careful though, too many may close the terminal
 */

int main(int argc, const char** argv) {

  const int COLS = 65;
  const int ROWS = 32;

  bool data[ROWS][COLS];

  // Initialize values
  for (int row = 0; row < ROWS; ++row) {
    for (int col = 0; col < COLS; ++col) {
      data[row][col] = false;
    }
  }

  // Setup starting condition
  data[0][COLS/2] = true;

  // Calculate new results
  for (int row = 1; row < ROWS; ++row) {
    for (int col = 1; col < COLS - 1; ++col) {
      // Rule 90 https://en.wikipedia.org/wiki/Rule_90
      // XOR of its two neighbors above
      data[row][col] = data[row - 1][col - 1] ^ data[row - 1][col + 1];
    }
  }

  // Print everything
  for (int row = 0; row < ROWS; ++row) {
    for (int col = 0; col < COLS; ++col) {
      if (data[row][col]) {
        printf("X");
      } else {
        printf(".");
      }
    }
    printf("\n");
    // Pause stuff - Not expected in student's code
    if (argc > 1) {
      getchar();
    }
    // -- End pause stuff
  }
  printf("\n");

  return 0;
}
