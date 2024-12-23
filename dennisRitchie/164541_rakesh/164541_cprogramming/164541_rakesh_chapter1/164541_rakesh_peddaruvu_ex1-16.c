/*
* This program revises the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines,
* and as much of the text as possible.
* 
* Name: D. Rakesh
* Author: Rakesh
* Created: 4 July, 2024
* Modified: 4 July, 2024
*
* SAMPLE INPUT:
*   Hello world!
*   This is a long line of text that should be tracked as the longest.
*   Short line.
*
* SAMPLE OUTPUT:
*   longest line is- This is a long line of text that should be tracked as the longest.
*   with length = 59
*
* FUNCTION PARAMETERS:
*   - `to_Copy(char to[], char from[])`: This function takes two character arrays `to` and `from`.
*     It copies the contents from `from` to `to`, including the null-terminator character.
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define LINES 50  // Maximum length of an input line
#define COUNT 50  // Maximum number of characters for the longest line

/** FUNCTION PROTOTYPES */
void to_Copy(char to[], char from[]);

/** MAIN PROGRAM */
/** main: Reads multiple lines of input, tracks the longest line, and prints its length and content */
int main() {
    int ich, istart, ibig_line_length = 0, icount = 0;
    char slines[LINES];
    char slongest[COUNT];

    /* Counts characters and tracks the longest line */
    for (istart = 0; (ich = getchar()) != EOF; istart++) {
        icount++;
        slines[istart] = ich;

        /* When a newline is encountered, check if it's the longest line */
        if (ich == '\n') {
            if (icount > ibig_line_length) {
                ibig_line_length = icount;  // Update the longest line length
                to_Copy(slongest, slines);  // Copy the current line to `slongest`
            }
            icount = 0;   // Reset count for the next line
            istart = -1;  // Reset index for storing characters
        }
    }

    /* Print the longest line and its length */
    printf("longest line is- %s", slongest);
    printf("  with length = %d\n", ibig_line_length);

    return 0;
}
/* End main() */

/** to_Copy: Copies content from one string to another */
/*
* Parameters:
*   - `to[]`: Destination character array where content will be copied.
*   - `from[]`: Source character array from which content will be copied.
*/
void to_Copy(char s_to[], char s_from[]) {
    int ivar = 0;

    /* Copy each character from `s_from` to `s_to` until null-terminator */
    while ((s_to[ivar] = s_from[ivar]) != '\0') {
        ++ivar;
    }
}
/* End of to_Copy() */

