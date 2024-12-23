/* 
 * This program counts the number of blanks, tabs, and newlines in the user input.
 * 
 * Name         : Rakesh
 * Created Date : 24-06-2024
 * Modified Date: 24-06-2024
 */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include "error_handling.h" // Custom header for error handling

/* MACRO DECLARATIONS */
#define RANGE 100 // Maximum number of characters in the input string

/* MAIN PROGRAM */
/*
 * main: Accepts characters from the user and counts the number of blanks, tabs, and newlines.
 */
int main() {
    char sStr[RANGE]; // Array to store the input string
    int iblanks = 0, itabs = 0, inewlines = 0; // Counters for blanks, tabs, and newlines
    int icount = 0, icharacter; // Counter for character input and current character
    char cCh; // Variable for user input to continue or quit

    do {
        icharacter = 0;
        icount = 0;

        // User input
        while ((icharacter = getchar()) != EOF) {
            // Store each character into the string array
            sStr[icount++] = icharacter;
            if (icount >= RANGE - 1) {
                // If character count exceeds array capacity, handle the error
                handle_error(ERROR_OUT_OF_RANGE);
                return 0; // Exit the program if input is out of range
            }
        }
        sStr[icount] = '\0'; // Null terminate the string

        // Count tabs, newlines, and spaces in the string
        int iIndex;
        for (iIndex = 0; sStr[iIndex] != '\0'; iIndex++) {
            if (sStr[iIndex] == ' ') {
                iblanks++; // Increment blank counter
            }
            if (sStr[iIndex] == '\t') {
                itabs++; // Increment tab counter
            }
            if (sStr[iIndex] == '\n') {
                inewlines++; // Increment newline counter
            }
        }

        // Display the results
        printf("Total blanks: %d | Total tabs: %d | Total new lines: %d\n", iblanks, itabs, inewlines);

        // Ask user if they want to continue
        printf("Do you want to continue (y/n)?\n");
        scanf(" %c", &cCh);

        // Clear the input buffer until newline or EOF is reached
        while ((icharacter = getchar()) != EOF && icharacter != '\n');

    } while (cCh == 'y' || cCh == 'Y'); // Continue if user enters 'y' or 'Y'

    return 0; // Return 0 to indicate successful completion
}
/* End of main() */

