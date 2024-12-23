/*
 * This program copies its input to its output, replacing each string of 
 * one or more blanks with a single blank.
 * 
 * Name         : Rakesh
 * Created Date : 24-06-2024
 * Modified Date: 24-06-2024
 */

/* REQUIRED HEADER FILES */
#include <stdio.h>

#define MAX 50 // Maximum number of characters in the input string

/* MAIN PROGRAM */
/*
 * main: Accepts characters and replaces sequences of multiple blanks or tabs with a single blank.
 */
int main() {
    int istart, iend; // Index variables for iteration
    char sStr[MAX]; // Array to store the input string
    int cCharacter; // Variable for character input
    int iblanks = 0, ivalue = 0; // Counter variables

    // Read input from the user character by character until EOF is encountered
    while ((cCharacter = getchar()) != EOF) {
        sStr[ivalue++] = cCharacter; // Store each character in the string array
    }
    sStr[ivalue] = '\0'; // Null-terminate the string

    // Remove more than one blank space and replace tabs with a single blank
    for (istart = 0; sStr[istart]; istart++) {
        // Check if the current character is a blank followed by another blank or a tab
        if (((sStr[istart] == ' ') && (sStr[istart + 1] == ' ')) || sStr[istart] == '\t') {
            // Shift all subsequent characters left by one position to remove the extra blank/tab
            for (iend = istart; sStr[iend]; iend++) {
                sStr[iend] = sStr[iend + 1];
            }
            istart--; // Decrement istart to check again after shifting characters
        }
    }

    // Null-terminate the string after removing extra blanks
    sStr[istart] = '\0';

    // Print the modified string
    printf("%s\n", sStr);

    return 0; // Return 0 to indicate successful completion
}
/* End of main */

