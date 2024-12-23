/*
 * This program is an extended version of a reverse Polish calculator.
 * It adds the modulus (%) operator and provisions for negative numbers.
 * 
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 8 July, 2024
 *
 * Sample Input/Output:
 * 
 * Input:
 *   5 8 +
 * Output:
 *   13
 *
 * Input:
 *   10 3 %
 * Output:
 *   1
 *
 * Input:
 *   -4 2 *
 * Output:
 *   -8
 *
 * Input:
 *   15 3 /
 * Output:
 *   5
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** MACRO DEFINITIONS **/
#define MAX 50            // Maximum size of the stack
#define NUMBER '0'        // Signal that a number was found
#define BUFFSIZE 100      // Size of buffer for `getch` and `ungetch`

/** FUNCTION PROTOTYPES **/
void push(double);
int getall(char []);
double pop(void);
int getch(void);
void ungetch(int);

/** GLOBAL VARIABLES **/
double gstk[MAX]; // Stack to hold numbers for the reverse Polish notation
int gtop = 0;     // Stack pointer for the `gstk`
char sbuf[BUFFSIZE]; // Buffer for `getch` and `ungetch`
int ibufp = 0;       // Buffer pointer for `getch` and `ungetch`

/** MAIN PROGRAM **/
/* main: Accepts inputs and functions as a reverse Polish calculator */
int main() {
    int i_type;        // Type of the next operation or number
    double d_op2;      // Variable to store the second operand in binary operations
    char sStr[MAX];    // String to hold numbers or operators

    // Reverse Polish calculator loop
    while ((i_type = getall(sStr)) != EOF) {
        switch (i_type) {
            case NUMBER:
                // If a number was found, push it onto the stack
                push(atof(sStr));
                break;

            case '+':
                // Addition of two numbers
                push(pop() + pop());
                break;

            case '*':
                // Multiplication of two numbers
                push(pop() * pop());
                break;

            case '-':
                // Subtraction of two numbers
                d_op2 = pop();
                push(pop() - d_op2);
                break;

            case '/':
                // Division of two numbers
                d_op2 = pop();
                if (d_op2 != 0.0)
                    push(pop() / d_op2);
                else
                    printf("Error: zero divisor\n");
                break;

            case '%':
                // Modulus operation
                d_op2 = pop();
                if (d_op2 != 0.0) {
                    int iresult = ((int)pop() % (int)d_op2);
                    // Adjust result for negative modulus
                    if (iresult < 0 && d_op2 > 0) {
                        iresult += (int)d_op2;
                    } else if (iresult > 0 && d_op2 < 0) {
                        iresult += (int)d_op2;
                    }
                    push(iresult);
                } else {
                    printf("Error: zero divisor.\n");
                }
                break;

            case '\n':
                // If new line, pop and print result
                printf("%.8g\n", pop());
                break;

            default:
                // Unknown command error handling
                printf("Error: unknown command %s\n", sStr);
                break;
        }
    }
    return 0;
}

/** End of main **/

/* push: Push a number onto the value stack */
void push(double d_var) {
    if (gtop == MAX) {
        printf("Error: stack overflow\n");
        return;
    }
    gstk[gtop++] = d_var;
}

/* pop: Pop and return the top value from the stack */
double pop(void) {
    if (gtop == 0) {
        printf("Error: stack underflow\n");
        return 0.0;
    }
    return gstk[--gtop];
}

/* getch: Get a (possibly pushed-back) character */
int getch(void) {
    return (ibufp > 0) ? sbuf[--ibufp] : getchar();
}

/* ungetch: Push character back onto input */
void ungetch(int ivar) {
    if (ibufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        sbuf[ibufp++] = ivar;
    }
}

/* getall: Get the next operator or numeric operand */
int getall(char sStr[]) {
    int iIndex = 0, ivar;

    // Skip whitespace characters
    while ((sStr[0] = ivar = getch()) == ' ' || ivar == '\t');

    sStr[1] = '\0';

    // Not a number or a negative sign
    if (!isdigit(ivar) && ivar != '.' && ivar != '-') {
        return ivar;
    }

    iIndex = 0;

    // Handle negative numbers
    if (ivar == '-') {
        char next = getch();
        if (isdigit(next) || next == '.') {
            sStr[++iIndex] = ivar = next;
        } else {
            ungetch(next);
            return ivar;
        }
    }

    // Collect the integer part
    if (isdigit(ivar)) {
        while (isdigit(sStr[++iIndex] = ivar = getch()));
    }

    // Collect the fractional part
    if (ivar == '.') {
        while (isdigit(sStr[++iIndex] = ivar = getch()));
    }

    sStr[iIndex] = '\0';
    if (ivar != EOF) {
        ungetch(ivar);
    }

    // Signal that a number was found
    return NUMBER;
}

/** End of getall **/

