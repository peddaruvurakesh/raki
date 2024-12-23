/*
 * This program writes a function strindex(s, t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
 *
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 11 July, 2024
 *
 * Sample Input/Output:
 * 1.
 *   Input:
 *     Enter the main string: hello world
 *     Enter the substring to match: lo
 *   Output:
 *     Substring "lo" found in "hello world" at position: 3
 *
 * 2.
 *   Input:
 *     Enter the main string: hello world hello
 *     Enter the substring to match: hello
 *   Output:
 *     Substring "hello" found in "hello world hello" at position: 12
 *
 * 3.
 *   Input:
 *     Enter the main string: openai
 *     Enter the substring to match: test
 *   Output:
 *     Match not found in the string.
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** MACRO DEFINITIONS **/
#define RANGE 100

/** FUNCTION PROTOTYPES **/
int strindex(char[], char[]);

/** MAIN PROGRAM **/
/* main(): Finds the occurrence of a substring and prints its index */
int main() {
    char sStr[RANGE], t[RANGE];
    int ivalue, ival;
    char cCh, cCharacter;

    /* do-while loop: to repeat the loop based on condition */
    do {
        /* Initialization */
        ivalue = 0;
        ival = 0;

        /* Entering the main string s */
        printf("Enter the main string: ");
        while ((cCh = getchar()) != EOF && cCh != '\n') {
            /* Error handling: if given range is more */
            if (ivalue < RANGE - 1) {
                sStr[ivalue++] = cCh;
            } else {
                /* Handle error */
                printf("Error: Input string exceeds range.\n");
                while ((cCh = getchar()) != '\n' && cCh != EOF);
                /* Clear input buffer */
                return 0;
            }
        }
        sStr[ivalue] = '\0';  // Null-terminate the string

        /* Entering the substring t */
        printf("Enter the substring to match: ");
        while ((cCh = getchar()) != EOF && cCh != '\n') {
            if (ival < RANGE - 1) {
                t[ival++] = cCh;
            } else {
                printf("Error: Substring exceeds range.\n");
                while ((cCh = getchar()) != '\n' && cCh != EOF);
                return 0;
            }
        }
        t[ival] = '\0';  // Null-terminate the substring

        /* Calling strindex function to find the rightmost index */
        int iIndex = strindex(sStr, t);
        if (iIndex != -1) {
            printf("Substring \"%s\" found in \"%s\" at position: %d\n", t, sStr, iIndex);
        } else {
            printf("Match not found in the string.\n");
        }

        /* To check if the user wants to do another search */
        printf("Do you want to find another substring in a string? (y / n): ");
        scanf(" %c", &cCharacter);
        while ((cCh = getchar()) != '\n' && cCh != EOF);

    } while (cCharacter == 'y' || cCharacter == 'Y');
    /* End of do-while */

    return 0;
}
/* End of main() */

/* strindex function to find the rightmost occurrence of a substring in a string */
/* Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 11 July, 2024
 */
int strindex(char s[], char t[]) {
    int iIndex1, iIndex2, itemp;

    /* Get the lengths of the strings */
    int i_slen = strlen(s);
    int i_tlen = strlen(t);

    /* Loop through s to find the rightmost occurrence of t */
    for (iIndex1 = i_slen - i_tlen; iIndex1 >= 0; iIndex1--) {
        for (iIndex2 = iIndex1, itemp = 0; itemp < i_tlen && tolower(s[iIndex2]) == tolower(t[itemp]); iIndex2++, itemp++);

        if (itemp == i_tlen) {
            /* Return the index (zero-based) */
            return iIndex1+1;
        }
    }

    /* If substring is not found */
    return -1;
}
/* End of strindex() */

