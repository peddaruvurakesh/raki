/*
 * This program is designed to replace strings of blanks (spaces) with the minimum number of tabs (`\t`) and blanks 
 * to achieve the same spacing. The replacement is done using a specified number of spaces per tab (in this case, 4).
 * If a sequence of spaces is equal to or exceeds the size of a tab stop, those spaces are replaced by a tab character.
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 1 July, 2024
 * Modified : 1 July, 2024
 */

/*
 * Question Clarification:
 * - The program replaces sequences of spaces with tab characters wherever possible.
 * - If four or more spaces occur consecutively, they are replaced with a tab character.
 * - If fewer than four spaces occur, they are left as individual space characters.
 * 
 * Steps to Understand the Program:
 * 1. Read the entire input from the user.
 * 2. Replace spaces with tabs wherever possible (i.e., every four spaces).
 * 3. Print the transformed string, using tab characters when a sequence of four spaces is encountered.
 * 
 * Sample Input:
 * "    Hello,    world!"
 * 
 * Sample Output:
 * "\\tHello,\\t  world!"
 * (Explanation: Each group of four spaces is replaced with "\\t", and remaining spaces are printed as-is.)
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>
#include "error_handling.h" // Assuming this header handles errors in the program

/** MACROS DEFINITIONS **/
#define TAB 4    // Define a tab stop as 4 spaces
#define MAX 500  // Maximum size of the input buffer

/* MAIN PROGRAM */
/*
 * main: Main function that processes the input to replace sequences of spaces with tab characters.
 * - No parameters.
 * - Returns an integer (0 for success, 1 for error).
 */
int main() {
    int iCount = 0, iInput = 0, iIndex;  // Initialize variables
    int iSpaces = TAB;                   // Number of spaces equivalent to a tab
    char sStr[MAX], cCharacter;          // Input character array and character variable

    /* To get input from the user */
    while ((cCharacter = getchar()) != EOF) {
        sStr[iInput++] = cCharacter;  // Store each input character in the array
    }

    /* Null-terminate the string */
    sStr[iInput] = '\0';

    /* Check if input exceeds the maximum buffer size */
    if (iInput > MAX - 1) {
        handle_error(ERROR_OUT_OF_RANGE);  // Handle the error if input is out of range
        return 1;
    }

    /* Process the input string */
    for (iIndex = 0; sStr[iIndex]; iIndex++) {
        if (sStr[iIndex] == ' ') {
            ++iCount;  /* Increment the space count */
            if (iCount == iSpaces) {
                printf("\\t");  // Replace four spaces with a tab
                iCount = 0;     // Reset the space count
            }
        } else {
            /* Print any remaining spaces if the count is less than 4 */
            while (iCount > 0) {
                printf(" ");
                iCount--;
            }
            printf("%c", sStr[iIndex]);  // Print the non-space character

            if (sStr[iIndex] == '\n') {
                iCount = 0;  // Reset count at the start of a new line
            }
        }
    }

    return 0;
}

/* End of main() */

