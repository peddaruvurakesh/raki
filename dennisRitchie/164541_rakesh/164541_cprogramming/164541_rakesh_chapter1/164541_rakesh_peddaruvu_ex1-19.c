/*
 * This program creates a function reverse(s) that reverses the character string s. 
 * It uses this function to write a program that reverses its input line by line.
 *
 * Author: Rakesh
 * Created: 28 June, 2024
 * Modified: 28 June, 2024
 *
 * SAMPLE INPUT:
 *   Hello, World!
 *   This is a test line.
 *   Reversing strings is fun.
 *
 * SAMPLE OUTPUT:
 *   !dlroW ,olleH
 *   .enil tset a si sihT
 *   .nuf si sgniR
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define CHAR 200  // Maximum number of characters for each line

/** FUNCTION PROTOTYPES */
void reverse_String(char sStr[]);  // Function to reverse the string

/** MAIN PROGRAM */
/** main: Reads input and calls the reverse function for each line */
int main() {
    char sStr[CHAR];  // Array to store the input string
    char cCh;        // Character variable for reading input
    int ivar2 = 0;   // Counter for the current position in the input string

    /* Get input from the user until EOF (End of File) */
    while ((cCh = getchar()) != EOF) {
        sStr[ivar2++] = cCh;  // Store the character in the array

        // Check for a newline character to indicate the end of a line
        if (cCh == '\n') {
            sStr[ivar2] = '\0';  // Null-terminate the string
            /* Calling the reverse function */
            reverse_String(sStr); // Reverse the line
            ivar2 = 0;  // Reset the counter for the next line
        }
    }

    return 0; // Indicate that the program ended successfully
}
/* End main() */

/** reverse_String(): Reverses the input string and prints it */
/* Author: Rakesh
 * Created: 28 June, 2024
 * Modified: 28 June, 2024
 * 
 * Parameters:
 * - char sStr[]: An array of characters representing the string to be reversed.
 *   The string is expected to be null-terminated. 
 *   The function modifies this array in place to store the reversed string.
 */
void reverse_String(char sStr[]) {
    int ivar1, ivar2;  // Loop counters
    char ctemp;  // Temporary variable for swapping characters

    // Find the length of the string
    for (ivar2 = 0; sStr[ivar2] != '\0'; ivar2++); // Count characters until null terminator

    // Reverse the string using a temporary variable
    for (ivar1 = 0, ivar2 = ivar2 - 1; ivar1 < ivar2; ivar1++, ivar2--) {
        ctemp = sStr[ivar1];  // Store the current character
        sStr[ivar1] = sStr[ivar2];  // Swap the characters
        sStr[ivar2] = ctemp;  // Place the stored character in the reversed position
    }

    // Print the reversed string
    printf("After reversing the string: %s\n", sStr);
}
/* End reverse_String() */

