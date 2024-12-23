/*Question:7.2
Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom and break long text lines. 

Explanation
The task is to write a program that reads arbitrary input from the user and prints it in a "sensible" way. This involves:

Handling Non-graphic Characters: Non-graphic characters (like control characters) should be displayed in octal or hexadecimal format. This ensures that even non-printable characters are represented in a readable way.
Line Breaking: Long lines of text should be broken to fit within a specified maximum line length. This makes the output more readable and avoids excessively long lines that can be difficult to process or display properly.*/
/*
name: rakesh peddaruvu
date: 03/12/2024
modified date : 03/12/2024
*/

// HEADDER FILES

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 100 /* maximum number of characters per line */
#define OCTLEN  6   /* length of an octal value */

/*
 *
 * Sample Input/Output:
 * ====================
 * Input:
 *   Hello World!\n\tThis is a test.
 *
 * Output:
 *   Hello World!
 *   \011This is a test.
 *
 * Explanation:
 * - 'Hello World!' contains only printable characters, so it is printed as is.
 * - '\n' (newline) moves to the next line.
 * - '\t' (tab) is a control character and is printed as its octal value (\011).
 */

/* Main function */
int main(void)
{
    int c, pos;        /* c stores the current character, pos tracks the position in the current line */
    int inc(int pos, int n); /* Declaration of the helper function to increment position */

    pos = 0;        /* Initialize the position in the line */

    /* Process input character by character until EOF (End of File) is reached */
    while ((c = getchar()) != EOF)
    {
        if (iscntrl(c) || c == ' ') /* Check if the character is a control character or a blank space */
        {
            /* Non-graphic or blank character */
            pos = inc(pos, OCTLEN); /* Increment position by the length of an octal representation */
            printf("\\%03o", c);    /* Print the octal representation of the character */
            /* If newline character, reset position to 0 */
            if (c == '\n')
                pos = 0;
            putchar('\n'); /* Print a newline for better formatting */
        }
        else
        {
            /* Graphic (printable) character */
            pos = inc(pos, 1); /* Increment position by 1 */
            putchar(c);        /* Print the character as is */
        }
    }
    return 0;
}

/*
 * inc : Increment position counter for output.
 * If adding the next output will exceed MAXLINE, it inserts a newline and resets the position.
 */
int inc(int pos, int n)
{
    if (pos + n < MAXLINE) /* Check if the new position is within the maximum line length */
        return pos + n;    /* Update and return the new position */
    else
    {
        putchar('\n');     /* Insert a newline if MAXLINE is exceeded */
        return n;          /* Reset the position to the current length (start of new line) */
    }
}

