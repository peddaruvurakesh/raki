/*
 * Program: Rewrite `getint` to treat a '+' or '-' not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 *ZZ
 * Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 *
 * SAMPLE INPUT/OUTPUT:
 * Input: +123
 * Output: 123
 *
 * Input: -456
 * Output: -456
 *
 * Input: +
 * Output: invalid entry
 *
 * Input: -a
 * Output: invalid entry
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define MAXLEN 500
#define BUFFSIZE 100

/** FUNCTION PROTOTYPES */
/**
 * Get the next character from the buffer or standard input.
 * return The next character from the input.
 */
int getch(void);

/**
 * push a character back onto the input buffer.
 * c The character to be pushed back.
 */
void ungetch(int c);

/**
 * Get next integer from input and store it in *pn.
 *  pn Pointer to an integer where the value will be stored.
 * @return 1 if a valid integer was read, 0 otherwise.
 */
int getint(int *pn);

/** MAIN PROGRAM */
/* main(): Accepts operators with integers */
int main()
{
    int inumber;
    /* function call which returns value */
    int iresult = getint(&inumber);

    if (iresult == 0)
        printf("invalid entry\n");
    else
        printf("%d\n", inumber);
}
/* End main() */

/* getint: get next integer from input into *pn */
/* Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 */
/**
 *  Reads the next integer from the input and stores it at the address provided by pPtr.
 * Handles the sign ('+' or '-') and ensures that if a sign is not followed by a digit, it is treated as invalid.
 * 
 *  pPtr Pointer to the integer variable where the input value should be stored.
 *  Returns 1 if an integer was successfully read, otherwise returns 0.
 */
int getint(int *pPtr)
{
    int ivar, isign;

    while (isspace(ivar = getch())) /* skip white space */
        ;

    if (!isdigit(ivar) && ivar != EOF && ivar != '+' && ivar != '-') {
        ungetch(ivar); /* it is not a number */
        return 0;
    }

    isign = (ivar == '-') ? -1 : 1;

    if (ivar == '+' || ivar == '-') {
        ivar = getch();
        /* if it is not a digit */
        if (!isdigit(ivar)) {
            ungetch(ivar);
            return 0;
        }
    }

    for (*pPtr = 0; isdigit(ivar); ivar = getch())
        *pPtr = 10 * *pPtr + (ivar - '0');

    *pPtr *= isign;

    if (ivar != EOF)
        ungetch(ivar);

    return 1;
}
/* end of getint() */

char cbuf[BUFFSIZE]; /* buffer for ungetch */
int ibufp = 0;       /* next free position in buf */

/* getch:To return a character or element in buffer */
/* Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 */
/**
 *  Get a character from the buffer if available, otherwise read from standard input.
 * 
 * return The character from buffer or input.
 */
int getch(void)
{
    return (ibufp > 0) ? cbuf[--ibufp] : getchar();
}

/* ungetch:To store a character in buffer */
/* Author: Rakesh
 * Created: 17 July, 2024
 * Modified: 17 July, 2024
 */
/**
 * @brief Push a character back into the input buffer.
 * 
 * @param iVar The character to be pushed back.
 */
void ungetch(int iVar)
{
    if (ibufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        cbuf[ibufp++] = iVar;
}
/* End of ungetch */

