/*
 * Program: Write `getFloat`, the floating-point analog of `getint`.
 * The function reads the next floating-point number from input and stores it in the provided variable.
 *
 * Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 *
 * SAMPLE INPUT/OUTPUT:
 * Input: 123.456
 * Output: 123.456000
 *
 * Input: -78.91
 * Output: -78.910000
 *
 * Input: +45
 * Output: 45.000000
 *
 * Input: abc
 * Output: 0.000000
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
#include <math.h>

/** MACRO DEFINITIONS */
#define MAXLEN 500
#define BUFFSIZE 100

/** FUNCTION PROTOTYPES */
/*
 * Get the next character from the buffer or standard input.
 * Returns the next character from the input.
 */
int getch(void);

/*
 * Push a character back onto the input buffer.
 * Parameters:
 *   c - The character to be pushed back.
 */
void ungetch(int c);

/*
 * Get next floating-point number from input and store it in *ptr.
 * Parameters:
 *   ptr - Pointer to a double where the value will be stored.
 * Returns 1 if a valid floating-point number was read, 0 otherwise.
 */
int getFloat(double *ptr);

/** MAIN PROGRAM */
/* main: calls getFloat function */
int main()
{
    double dnumber = 0;
    /* Function call to get floating-point value */
    getFloat(&dnumber);
    /* Prints the value in float format */
    printf("%.6f\n", dnumber);
}
/* End main() */

/* getFloat: get next floating-point number from input into *ptr */
/* Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 */
/*
 * Reads the next floating-point number from input and stores it at the address provided by pPtr.
 * Handles the sign ('+' or '-') and decimals. If a sign or decimal is not followed by a digit, it is treated as invalid.
 * 
 * Parameters:
 *   pPtr - Pointer to the double variable where the input value should be stored.
 * Returns 1 if a floating-point number was successfully read, otherwise returns 0.
 */
int getFloat(double *pPtr)
{
    int ivar, isign;

    while (isspace(ivar = getch())) /* skip white space */
        ;

    if (!isdigit(ivar) && ivar != EOF && ivar != '+' && ivar != '-' && ivar != '.') {
        ungetch(ivar); /* it is not a number */
        return 0;
    }

    isign = (ivar == '-') ? -1 : 1;

    if (ivar == '+' || ivar == '-') {
        ivar = getch();
        if (!isdigit(ivar) && ivar != '.') {
            ungetch(ivar);
            return 0;
        }
    }

    /* Before decimal point */
    for (*pPtr = 0; isdigit(ivar); ivar = getch())
        *pPtr = 10 * *pPtr + (ivar - '0');

    /* After decimal point */
    if (ivar == '.') {
        double factor = 0.1;
        while (isdigit(ivar = getch())) {
            *pPtr += (ivar - '0') * factor;
            factor *= 0.1;
        }
    }

    *pPtr *= isign;

    if (ivar != EOF)
        ungetch(ivar);

    return 1;
}
/* End of getFloat() */

char cbuf[BUFFSIZE]; /* Buffer for ungetch */
int ibufp = 0;       /* Next free position in buffer */

/* getch: To return a character or element from the buffer */
/* Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 */
/*
 * Get a character from the buffer if available, otherwise read from standard input.
 * 
 * Returns the character from buffer or input.
 */
int getch(void)
{
    return (ibufp > 0) ? cbuf[--ibufp] : getchar();
}

/* ungetch: To store a character in buffer */
/* Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 */
/*
 * Push a character back into the input buffer.
 * 
 * Parameters:
 *   iVar - The character to be pushed back.
 */
void ungetch(int iVar)
{
    if (ibufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        cbuf[ibufp++] = iVar;
}
/* End of ungetch */

