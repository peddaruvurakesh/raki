/*
 * This program folds long input lines into two or more shorter lines after the last non-blank character 
 * that occurs before the n-th column of input. It breaks lines intelligently, making sure that no single line 
 * exceeds the specified column limit. If there are no blanks or tabs before the column limit, it simply breaks 
 * at the limit.
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 4 July, 2024
 * Modified : 4 July, 2024
 * 
 * Question Explanation:
 * - Given an input line that is very long, the goal is to split it into shorter lines that do not exceed a 
 *   specified column width (in this case, 10 characters).
 * - The program should ensure the line breaks after the last non-blank character before the column limit.
 * 
 * Steps to Understand the Program:
 * 1. Read the input from the user.
 * 2. Iterate through the input and print it in chunks of 10 characters.
 * 3. Insert a newline after every 10 characters to "fold" the line.
 * 
 * Sample Input:
 * "This is a very long line that we want to fold into shorter lines for better readability."
 * 
 * Sample Output:
 * "This is a 
 * very long 
 * line that 
 * we want to 
 * fold into 
 * shorter li
 * nes for be
 * tter readab
 * ility."
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
/* Maximum column width for each line */
#define COLUMN 10
/* Maximum number of characters in input */
#define COUNT 100

/** MAIN PROGRAM */
/**
 * main: Reads characters from the user and folds long input lines after every COLUMN characters.
 * - No parameters.
 * - Returns 0 on successful completion.
 */
int main() {
    char cCharacter;          // Variable to store the current character
    int iInput = 0;           // Counter for the number of characters read
    int istart_1 = 0;         // Start index for each chunk of COLUMN characters
    int istart_2 = 0;         // Index for iterating through a chunk of COLUMN characters
    char sline[COUNT];        // Array to store the input characters

    /* To get input from the user */
    while ((cCharacter = getchar()) != EOF) {
        sline[iInput++] = cCharacter;  // Store each input character in the array
    }

    /* Null-terminate the string */
    sline[iInput] = '\0';

    /* Loop to iterate through input and print in chunks of COLUMN characters */
    for (istart_1 = 0; istart_1 < iInput; istart_1 += COLUMN) {
        /* Print a line of COLUMN characters or up to the end of the buffer */
        for (istart_2 = istart_1; istart_2 < istart_1 + COLUMN && istart_2 < iInput; istart_2++) {
            printf("%c", sline[istart_2]);  // Print each character in the current chunk
        }
        putchar('\n');  /* Newline after each line of COLUMN characters */
    }

    return 0;  // Return 0 to indicate successful completion
}

/* End main() */

