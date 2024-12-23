/*
 * This program modifies the behavior of getch and ungetch to handle pushed-back EOF correctly.
 * Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 10 July, 2024
 */

/**
 * INPUT/OUTPUT EXAMPLES:
 *
 * INPUT:
 *   Hello, World!  // User types this string followed by Enter.
 *   (Press Ctrl+D to simulate EOF in Unix/Linux or Ctrl+Z in Windows)
 *
 * OUTPUT:
 *   Hello, World!
 *   EOF encountered.
 */

/** REQUIRED HEADER FILES */
#include <stdio.h> // Includes standard I/O library

/** FUNCTION PROTOTYPES */
int getch(void);      // Function to get a character from the input
void ungetch(int c);  // Function to push a character back onto input

/** MAIN PROGRAM */
/** main: Accepts input and processes it line by line */
int main()
{
    int iIndex = 0;      // Index for storing characters in the string
    char sStr[50];      // Array to hold the input string
    char cvar;          // Variable to store the current character being processed
    int inew_line = 1;  // Flag to indicate if we're at the start of a new line

    // Read characters until EOF
    while ((cvar = getch()) != EOF)
    {
        if (inew_line)
        {
            // Print the first character of the line
            sStr[iIndex++] = cvar; // Store the character
            sStr[iIndex] = '\n';    // Append a newline character
            iIndex++;               // Move to the next index
            inew_line = 0;         // Reset flag after printing the first character
        }

        // Skip the rest of the line until the next newline
        while ((cvar = getch()) != '\n' && cvar != EOF)
            ;

        if (cvar == '\n')
        {
            // If we encountered a newline, set the flag for the next iteration
            inew_line = 1;
        }
    }
    sStr[iIndex] = '\0';  // Null-terminate the string
    printf("%s\n", sStr); // Print the resulting string
    printf("EOF encountered.\n"); // Indicate EOF was encountered

    return 0;
}
/* End of main() */

/* Buffer variable for pushback character. */
int ibuf = -1; // Initialize buffer index to -1 (indicating no character in buffer)

/* getch: Function to get a character from the buffer or standard input */
/* Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 10 July, 2024
 */
int getch(void)
{
    if (ibuf != -1) // Check if there is a character in the buffer
    {
        int ctemp = ibuf; // Retrieve the buffered character
        ibuf = -1;        // Clear the buffer

        return ctemp;     // Return the buffered character
    }

    return getchar(); // Otherwise, get the next character from standard input
}

/* ungetch: Function to push a character back into the buffer */
/* Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 10 July, 2024
 */
void ungetch(int ivar)
{
    if (ivar == EOF) // Check if EOF is being pushed back
    {
        printf("ungetch: cannot push back EOF\n"); // Error message for trying to push back EOF
    }
    else if (ibuf != -1) // Check if there is already a character in the buffer
    {
        printf("ungetch: buffer full\n"); // Error message for buffer overflow
    }
    else
    {
        ibuf = ivar; // Store the character in the buffer
    }
}
/** End of ungetch */

