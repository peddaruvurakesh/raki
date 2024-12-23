/*
 * This program reads input lines and prints all lines that are longer than 80 characters.
 * It collects input until the end of the file (EOF) and checks the length of each line.
 * If a line exceeds 80 characters, it is printed to the standard output.
 *
 * Name: D. Rakesh
 * Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 *
 * SAMPLE INPUT:
 *   Short line.
 *   This is a line that exceeds eighty characters in length. It is long enough to be printed out by this program.
 *   Another short line.
 *   Yet another line that is significantly longer than eighty characters, which will be included in the output of this program.
 *
 * SAMPLE OUTPUT:
 *   Lines longer than 80 characters:
 *   This is a line that exceeds eighty characters in length. It is long enough to be printed out by this program.
 *   Yet another line that is significantly longer than eighty characters, which will be included in the output of this program.
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define LINES 500  // Maximum number of characters for the input
#define COUNT 500  // Maximum number of characters for each line

/** MAIN PROGRAM */
/** main: To print lines longer than eighty characters */
int main() {
    int ivar = 0, ivar1, ich, istart = 0, icount = 0, iIndex = 0; // Variable initialization
    char slines[LINES];  // Array to hold the entire input
    char sline[COUNT];   // Array to hold each individual line
    char sStr[COUNT];    // Array to collect lines longer than 80 characters
    int istr_index = 0;  // Index for storing valid long lines

    /* Read input until EOF and store it in slines */
    while ((ich = getchar()) != EOF) {
        slines[iIndex++] = ich; // Read character by character
    }
    slines[iIndex] = '\0'; // Null-terminate the entire input

    iIndex = 0; // Reset index for processing lines
    /* Process each character in slines */
    while (slines[iIndex] != '\0') {
        if (slines[iIndex] == '\n') { // If newline is found
            sline[istart] = '\0'; // Null-terminate the current line
            /* Check if the current line has more than 80 characters */
            if (icount > 80) {
                for (ivar1 = 0; ivar1 < istart; ivar1++) {
                    sStr[istr_index++] = sline[ivar1]; // Copy the long line to sStr
                }
                sStr[istr_index++] = '\n'; // Add a newline to sStr
            }
            icount = 0; // Reset count for the new line
            istart = 0; // Reset the start index for the new line
        } else {
            sline[istart++] = slines[iIndex]; // Store character in the current line
            icount++; // Increment character count for the current line
        }
        iIndex++; // Move to the next character in slines
    }

    /* Handle the last line if it doesn't end with a newline */
    if (icount > 80) {
        sline[istart] = '\0'; // Null-terminate the last line
        for (ivar1 = 0; ivar1 < istart; ivar1++) {
            sStr[istr_index++] = sline[ivar1]; // Copy the long line to sStr
        }
        sStr[istr_index++] = '\n'; // Add a newline to sStr
    }

    sStr[istr_index] = '\0'; // Null-terminate the final string for output

    /* Print all collected lines longer than 80 characters */
    printf("Lines longer than 80 characters:\n%s", sStr);

    return 0;
}
/* End of main */

