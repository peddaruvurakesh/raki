/*
 * This program removes trailing blanks and tabs from each line of input, 
 * and deletes entirely blank lines. It keeps only a single space between words
 * and eliminates consecutive spaces. 
 *
 * Author: Rakesh
 * Created: 28 June, 2024
 * Modified: 4 July, 2024
 *
 * SAMPLE INPUT:
 *   This is a test input line.    
 *   This line has trailing spaces.      
 *   
 *   This line has     multiple spaces.
 *   This line has no tabs but trailing spaces.    
 *   
 * SAMPLE OUTPUT:
 *   This is a test input line.
 *   This line has trailing spaces.
 *   This line has multiple spaces.
 *   This line has no tabs but trailing spaces.
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINITIONS */
#define LENGTH 100  // Maximum length for the input string

/** FUNCTION PROTOTYPES */
/** No additional functions defined in this program */

/** MAIN PROGRAM */
/** main: Removes tabs, trims extra spaces, and removes empty lines */
int main() {
    char cCh, sStr[LENGTH];  // Character for reading input and array for storing the input string
    int icount = 0;          // Counter for the number of characters read

    // Read input until EOF
    while ((cCh = getchar()) != EOF) {
        // Remove tabs, keep single spaces
        if (cCh != '\t') {
            sStr[icount++] = cCh;  // Store non-tab characters
        }
    }

    // Null terminate the string
    sStr[icount] = '\0';

    // Remove empty lines (consecutive newlines) and trim extra spaces
    int ivar1 = 0, ivar2 = 0;  // Indices for reading and writing the string
    int iIs_space = 0;         // Flag to track consecutive spaces
    while (sStr[ivar1] != '\0') {
        if (sStr[ivar1] == ' ') {
            if (!iIs_space) {
                sStr[ivar2++] = sStr[ivar1];  // Keep only the first space
            }
            iIs_space = 1;  // Mark that space was found
        } else {
            iIs_space = 0;  // Reset when a non-space character is found
            if (sStr[ivar1] != '\n' || (sStr[ivar1] == '\n' && sStr[ivar1 + 1] != '\n')) {
                sStr[ivar2++] = sStr[ivar1];  // Keep the character if it's not a blank line
            }
        }
        ivar1++;  // Move to the next character
    }

    // Null terminate the string
    sStr[ivar2] = '\0';

    // Check if the final string is not empty (if empty, print empty string)
    if (ivar2 == 0) {
        printf("(Empty String)\n");  // Print if no content is left
    } else {
        printf("%s\n", sStr);  // Print the processed string
    }

    return 0;
}

