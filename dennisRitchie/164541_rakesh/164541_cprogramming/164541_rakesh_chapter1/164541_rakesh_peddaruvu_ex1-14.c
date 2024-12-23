/*
 * This program prints a histogram of the frequencies of different characters in its input.
 * Each character's frequency is represented by a number of asterisks (*).
 *
 * Author: Rakesh
 * Created: 25 June, 2024
 * Modified: 25 June, 2024
 *
 * SAMPLE INPUT:
 *   Enter a string (press CTRL+D to end):
 *   hello world
 *
 * SAMPLE OUTPUT:
 *   h *
 *   e *
 *   l ***
 *   o **
 *   w *
 *   r *
 *   d *
 *
 *   Special Characters:
 *   - '\s' for spaces
 *   - '\t' for tabs
 *   - '\n' for newlines
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define MAX 100

/** MAIN PROGRAM */
/** main: Accepts user input and prints a histogram of the frequencies of different characters */
int main() {
    char sStr[MAX];  // Array to store the input string
    char cCh;        // Variable to hold each character input
    int ivar = 0;    // Counter for storing the input characters
    int istart, iend;
    int iIndex, icount = 0;

    /* User input */
    printf("Enter a string (press CTRL+D to end):\n");
    while ((cCh = getchar()) != EOF) {
        sStr[ivar++] = cCh;
    }
    sStr[ivar] = '\0'; // NULL terminate the string

    /* Loop to iterate through the input string */
    for (istart = 0; sStr[istart]; istart++) {
        /* To not count already counted characters */
        for (iend = 0; iend < istart; iend++) {
            if (sStr[istart] == sStr[iend])
                break; // If character was already counted, break out
        }

        /* To check if it is the first occurrence of the character */
        if (iend == istart) {
            /* Count occurrences of the character */
            for (iend = istart + 1, icount = 1; sStr[iend]; iend++) {
                if (sStr[istart] == sStr[iend]) {
                    icount++;
                }
            }

            /* Print character and histogram */
            if (sStr[istart] == ' ') {
                printf("\\s ");
            } else if (sStr[istart] == '\t') {
                printf("\\t ");
            } else if (sStr[istart] == '\n') {
                printf("\\n ");
            } else {
                printf("%c ", sStr[istart]);
            }

            /* Print asterisks representing the frequency of the character */
            for (iIndex = 0; iIndex < icount; iIndex++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
/* End of main() */

