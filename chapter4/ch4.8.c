/*
*task : Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
*Author : Rohan Vartak
*Created :
*/

/** REQUIRED HEADER FILE */
#include <stdio.h>

/** FUNCTION PROTOTYPE */
int getch(void);
void ungetch(int c);


/** GLOBAL VARIABLES */
char buf = 0;  // Buffer to hold a single character
int buf_available = 0; // Flag to indicate if a character is present in the buffer (0 - empty, 1 - contains a character)


/** MAIN PROGRAM */
int main(void) {
  int c;

  // Read and push back the first character of the input
  c = getchar();
  ungetch(c);  // Push the character back into the input stream

  while ((c = getch()) != EOF) {
    putchar(c);  // Print the retrieved character
    break;        // Exit the loop after processing the first character
  }

  return 0;
}/* end main() */

/* getch: get a pushed back character */
int getch(void) {
  int c;

  if (buf_available) {
    buf_available = 0;  // Reset the availability flag
    return buf;         // Return the character from the buffer
  } else {
    c = getchar();      // If no character in the buffer, read from standard input
    return c;           // Return the newly read character
  }
}/* end getch()*/

/* ungetch: push a character back into input */
void ungetch(int c) {
  if (buf_available) {  // Check if the buffer is already full
    printf("ungetch: too many characters\n");  // Print an error message
  } else {
    buf = c;            // Store the character in the buffer
    buf_available = 1;  // Set the availability flag
  }
}/* end ungetch */

