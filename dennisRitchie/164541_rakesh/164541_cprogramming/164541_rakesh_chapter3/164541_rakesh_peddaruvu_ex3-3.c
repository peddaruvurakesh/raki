/*
 * This program implements a function called `expand()` that expands shorthand notations such as `a-z`
 * into their full equivalent (`abc...xyz`). It supports:
 * - Alphabetical ranges (both uppercase and lowercase).
 * - Numerical ranges (`0-9`).
 * - Mixed cases such as `a-b-c`, `a-z0-9`, and `-a-z`.
 * - Proper handling of leading or trailing dashes (`-`).
 * 
 * Sample Input:
 * a-d f-h 1-3
 * 
 * Sample Output:
 * abcd fgh 123
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 5 July, 2024
 * Modified : 5 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>  // Provides string handling functions
#include <ctype.h>   // Provides functions like isalpha() and isdigit()

/** MACRO DEFINITIONS */
#define WORDS 100  // Maximum length for input strings

/** FUNCTION PROTOTYPES */
void expand(char[], char[]);

/** MAIN PROGRAM */
/** main: Takes input from the user, calls expand(), and prints the expanded string */
int main() {
    char sStr1[WORDS], sStr2[WORDS];  // Arrays to hold input and expanded strings
    char cstart, cend, cCh, cvar;  // Variables to track range start, end, and characters
    int istart1 = 0;  // Index for looping through the string

    /* Take input from the user until newline or EOF */
    while ((cCh = getchar()) != EOF && cCh != '\n')
        sStr1[istart1++] = cCh;

    // Null terminate the input string
    sStr1[istart1] = '\0';

    /* Call expand() to convert shorthand notations into expanded sequences */
    expand(sStr1, sStr2);
    istart1 = 0;

    /* Print expanded output */
    while (sStr2[istart1] != '\0') {
        /* Check if character is part of an alphabetical range */
        if (isalpha(sStr2[istart1])) {
            cstart = sStr2[istart1];  // Start character of the range
            while (isalpha(sStr2[istart1])) {
                cend = sStr2[istart1];  // End character of the range
                istart1++;
            }

            /* Print characters if valid alphabetical range */
            if (cstart < cend) {
                // Forward alphabetical range (e.g., 'a-z')
                for (cvar = cstart; cvar <= cend; cvar++) {
                    printf("%c", cvar);
                }
            } else {
                // Reverse alphabetical range (e.g., 'z-a')
                for (cvar = cstart; cvar >= cend; cvar--) {
                    printf("%c", cvar);
                }
            }
        }

        /* Check if character is part of a numeric range */
        if (isdigit(sStr2[istart1])) {
            cstart = sStr2[istart1];  // Start character of the range (numeric)
            while (isdigit(sStr2[istart1])) {
                cend = sStr2[istart1];  // End character of the range (numeric)
                istart1++;
            }

            // Print characters if valid numeric range (e.g., '1-5')
            for (cvar = cstart; cvar <= cend; cvar++) {
                printf("%c", cvar);
            }
        }

        /* Handle '-' character if present literally */
        if (sStr2[istart1] == '-') {
            printf("%c", sStr2[istart1]);
            istart1++;
        }

        /* Print other non-alphanumeric characters */
        if (!isalpha(sStr2[istart1]) && !isdigit(sStr2[istart1])) {
            printf("%c", sStr2[istart1]);
            istart1++;
        }
    }

    return 0;
}
/* End main() */

/* expand(): Expands shorthand notations in s1 like 'a-z' into their equivalent complete list in s2 */
void expand(char s1[], char s2[]) {
    int inum = strlen(s1);  // Length of input string
    int iIndex, ivar;  // Loop index variables

    for (iIndex = 0, ivar = 0; iIndex < inum; iIndex++, ivar++) {
        /* Skip over the dash if it forms a valid shorthand notation (e.g., 'a-z') */
        if ((isalpha(s1[iIndex - 1]) && s1[iIndex] == '-' && isalpha(s1[iIndex + 1])) ||
            (isdigit(s1[iIndex - 1]) && s1[iIndex] == '-' && isdigit(s1[iIndex + 1]))) {
            iIndex++;  // Skip the dash
        }

        s2[ivar] = s1[iIndex];  // Copy character from s1 to s2
    }

    /* Null terminate the output string */
    s2[ivar] = '\0';
}
/* End expand() */

/*
 * Explanation of Functions:
 * 
 * - `main()`:
 *   - Takes user input in `sStr1` until newline or EOF is encountered.*/
