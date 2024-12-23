/*
 * This program replaces tabs in the input with the proper number of spaces to align to the next tab stop. 
 * The program assumes fixed tab stops, set at every n columns (TAB).
 * Author: Rakesh
 * Created: 1 July, 2024
 * Modified: 1 July, 2024
 *
 * SAMPLE INPUT:
 *   This is an example line.\tThis line has a tab.
 *   Another line with a tab here.\tEnd of line.
 *
 * SAMPLE OUTPUT:
 *   This is an example line.    This line has a tab.
 *   Another line with a tab here.    End of line.
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>

/** MACROS DEFINITIONS **/
#define TAB 8       // Number of spaces for each tab stop
#define MAX 1000    // Maximum number of characters to read

/* MAIN PROGRAM */
/*
 * main: Reads input and replaces tabs with the appropriate number of spaces
 */
int main() {
    char cChar;          // Character variable to read input
    int iCount = 0;     // Counter for the number of characters processed
    int iInput = 0;     // Counter for the input index
    int iIndex = 0;     // Index for iterating through the input string
    char sStr[MAX];     // Array to store the input string

    /* To get input from the user until EOF (End of File) */
    while ((cChar = getchar()) != EOF) {
        sStr[iInput++] = cChar; // Store the character in the array
    }
    
    /* Null terminating the string */
    sStr[iInput] = '\0';

    // Process the string character by character
    for (iIndex = 0; sStr[iIndex] != '\0'; iIndex++) {
        /* If a tab character is detected */
        if (sStr[iIndex] == '\t') {
            // Calculate how many spaces are needed to reach the next tab stop
            int ispaces = TAB - (iCount % TAB);
            while (ispaces > 0) {
                putchar(' ');  // Print a space
                --ispaces;      // Decrease the space count
                iCount++;       // Increment character count
            }
        } else {
            /* Print the current character */
            putchar(sStr[iIndex]);
            iCount++;  // Increment character count
            // Reset character count if a newline is found
            if (sStr[iIndex] == '\n') {
                iCount = 0;
            }
        }
    }
    return 0; // Indicate that the program ended successfully
}
/* End main() */

