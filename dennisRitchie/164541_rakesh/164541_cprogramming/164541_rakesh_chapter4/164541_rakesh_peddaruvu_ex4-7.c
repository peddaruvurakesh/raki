/*
 * This program implements a routine ungets(s) that will push back an entire string onto the input.
 * Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 23 July, 2024
 */

/**
 * INPUT/OUTPUT EXAMPLES:
 *
 * INPUT:
 *   Hello, World!  // User types this string followed by Enter.
 *
 * OUTPUT:
 *   Hello, World!  // The program will print the string back to the output.
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h> // Includes the string handling library.

/** MACRO DEFINITIONS */
#define MAXLEN 100  // Maximum length for input strings
#define BUFFSIZE 100 // Buffer size for ungetch storage

/** FUNCTION PROTOTYPES */
int getstr(char [], int); // Function to read a string from input
void ungets(char s[]);    // Function to push an entire string back onto input

/** MAIN PROGRAM */
/** main: Accepts an entire string and demonstrates ungets functionality */
int main(void)
{
    char sline[MAXLEN];   // Array to hold the input string
    char sline2[MAXLEN];  // Array to hold the string read back
    /* getstr function to get the input string and store it in sline */
    getstr(sline, MAXLEN);

    /* Push the string into the buffer using ungets */
    ungets(sline);
    
    /* Read from the buffer into sline2 */
    getstr(sline2, MAXLEN);
    printf("%s", sline2); // Print the string read back

    return 0;
}
/* End of main() */

/* Buffer array to store pushed-back characters. */
int ibufp = 0;           // Index for the next free position in the buffer
char sbuf[BUFFSIZE];     // Buffer to hold pushed-back characters

/* getch: Function to get a character from the buffer or standard input */
/* Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 10 July, 2024
*/
int getch(void)
{
    return (ibufp > 0) ? sbuf[--ibufp] : getchar(); // Return char from buffer or stdin
}

/* ungetch: Function to push a character back into the buffer */
/* Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 10 July, 2024
*/
void ungetch(int iVar)
{
    if (ibufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n"); // Error if buffer overflow occurs
    } else {
        sbuf[ibufp++] = iVar; // Push character into buffer
    }
}

/* getstr(): To get the input string and store it in the line */
/* Author: Rakesh
 * Created: 10 July, 2024
 * Modified: 23 July, 2024
*/
int getstr(char sStr[], int ilim)
{
    int inum, ivar = 0; // Initialize numeric input and character index
    /* Get entire string line */
    while (((inum = getch()) != EOF) && (--ilim > 0))
        sStr[ivar++] = inum; // Store characters in the array

    if (inum == '\n')       // If the end of line is reached
        sStr[ivar++] = inum; // Add newline character to string

    /* Null terminate the string */
    sStr[ivar] = '\0';
    return ivar; // Return the number of characters read
}

/* ungets: Function to push back an entire string onto the input buffer. */
void ungets(char sStr[])
{
    int ilength = strlen(sStr); // Get the length of the string
    while (ilength > 0)         // Push each character back onto the buffer
        ungetch(sStr[--ilength]);
}

