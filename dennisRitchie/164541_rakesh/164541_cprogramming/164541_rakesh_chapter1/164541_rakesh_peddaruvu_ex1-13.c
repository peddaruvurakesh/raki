/*
 * This program prints a histogram of the lengths of words in its input.
 * The histogram can be drawn both horizontally and vertically.
 *
 * Author: Rakesh
 * Created: 28 June, 2024
 * Modified: 28 June, 2024
 *
 * SAMPLE INPUT:
 *   Enter text (press CTRL+D to end):
 *   hello world
 *   welcome to histogram
 * 
 * HORIZONTAL HISTOGRAM OUTPUT:
 *   horizontal histogram
 *   *****
 *   *****
 *   *******
 *   ********
 * 
 * VERTICAL HISTOGRAM OUTPUT:
 *   vertical histogram
 *           *         
 *   *       *       * 
 *   *       *       * 
 *   *   *   *   *   * 
 *   *   *   *   *   * 
 *   *   *   *   *   * 
 *   *   *   *   *   *
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define MAX 100

/** FUNCTION PROTOTYPES */
void horizontal_Histogram(char[]);
void vertical_Histogram(char[]);

/** MAIN PROGRAM */
/** main: Accepts characters and to draw histogram calls both horizontal and vertical functions */
int main() {
    char sStr[MAX];  // Array to store the input string
    char cCharacter; // Variable to hold each character input
    int icount = 0;  // Character counter

    /* Store character in string sStr */
    printf("Enter text (press CTRL+D to end input):\n");
    while ((cCharacter = getchar()) != EOF) {
        sStr[icount++] = cCharacter;
    }
    /* NULL Terminate the string */
    sStr[icount] = '\0';

    /* Calling horizontal histogram function */
    printf("horizontal histogram\n");
    horizontal_Histogram(sStr);

    /* Calling vertical histogram function */
    printf("vertical histogram\n");
    vertical_Histogram(sStr);

    return 0;
}
/* End of main() */

/* horizontal_Histogram: To print horizontal histogram */
/*
 * Author: Rakesh
 * Created: 28 June, 2024
 * Modified: 28 June, 2024
 *
 * This function takes the input string and prints a horizontal histogram
 * representing the length of each word.
 */
void horizontal_Histogram(char sStr[]) {
    int istart;
    int icount = 0; // Counter to track the number of characters in each word

    for (istart = 0; sStr[istart] != '\0'; istart++) {
        if (sStr[istart] == '\n' || sStr[istart] == '\t' || sStr[istart] == ' ') {
            if (icount > 0) {
                // Print a newline after each word
                printf("\n");
                icount = 0; // Reset the counter for the next word
            }
        } else {
            /* Print * for each character in the word */
            printf("*");
            icount++;
        }
    }

    if (icount > 0) {
        // Print a newline for the last word if not followed by a space or newline
        printf("\n");
    }
}
/* End of horizontal_Histogram() */

/* vertical_Histogram: To convert into vertical histogram */
/*
 * Author: Rakesh
 * Created: 28 June, 2024
 * Modified: 28 June, 2024
 *
 * This function takes the input string and prints a vertical histogram
 * representing the length of each word.
 */
void vertical_Histogram(char sStr[]) {
    int istart, icount = 0;
    int iword_lengths[MAX]; // Array to store the length of each word
    int iword_count = 0; // Counter for the number of words

    /* Loop through the input string */
    for (istart = 0; sStr[istart] != '\0'; istart++) {
        if (sStr[istart] == '\n' || sStr[istart] == '\t' || sStr[istart] == ' ') {
            if (icount > 0) {
                // Store the length of the word
                iword_lengths[iword_count] = icount;
                iword_count++;
                icount = 0; // Reset the character count for the next word
            }
        } else {
            icount++; // Increment the character count for the current word
        }
    }

    if (icount > 0) {
        // Store the length of the last word if it exists
        iword_lengths[iword_count] = icount;
        iword_count++;
    }

    /* Find the maximum word length */
    int ivar, imax_length = 0;
    for (ivar = 0; ivar < iword_count; ivar++) {
        if (iword_lengths[ivar] > imax_length) {
            imax_length = iword_lengths[ivar];
        }
    }

    /* Print the vertical histogram */
    int iIndex;
    for (ivar = imax_length; ivar > 0; ivar--) {
        for (iIndex = 0; iIndex < iword_count; iIndex++) {
            if (iword_lengths[iIndex] >= ivar) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
/* End of vertical_Histogram() */

