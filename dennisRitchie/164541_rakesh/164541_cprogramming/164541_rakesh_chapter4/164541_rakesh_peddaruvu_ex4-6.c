/*
 * This program is a reverse Polish notation calculator with the ability to assign and use variables.
 * It allows handling twenty-six variables (with single-letter names) and tracks the most recently printed value.
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 8 July, 2024
 */

/**
 * INPUT/OUTPUT EXAMPLES:
 * 
 * INPUT:
 *   5 4 +        // Adds 5 and 4, output will be 9
 *   a=           // Assigns value 9 to variable 'a'
 *   6 2 -        // Subtracts 2 from 6, output will be 4
 *   b=           // Assigns value 4 to variable 'b'
 *   @            // Prints all stored variables
 *   l            // Prints the last result, which is 4
 *
 * OUTPUT:
 *   9
 *   a=9
 *   4
 *   b=4
 *   a=9
 *   b=4
 *   Last result = 4
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define MAX 26        // Maximum number of variables
#define NUMBER '0'    // Signal that a number was found
#define VARIABLE '1'  // Signal that a variable was found
#define BUFFSIZE 100  // Buffer size for storing characters

/** FUNCTION PROTOTYPES */
void push(double dvar);
int getall(char sStr[]);
double pop(void);
void print_all_variables();
void print_last_result();
int getch(void);
void ungetch(int ivar);

/** GLOBAL VARIABLES */
double gstk[MAX];     // Stack to hold values for calculations
int gtop = 0;         // Top of stack index
double glast_result = 0; // Last calculated result
char gvars[MAX];      // Array to store values of variables

/** MAIN PROGRAM */
/** main: Reverse Polish calculator with variable assignment */
int main()
{
    int itype, istart, iend = 0;
    char scha_r[MAX]; // Track assigned variables
    double dop2;
    char sStr[MAX];
    int itrue_val;

    // Reverse Polish calculator loop
    while ((itype = getall(sStr)) != EOF) {
        itrue_val = 1;
        istart = 0;
        switch (itype) {
            // If a number was found
            case NUMBER:
                push(atof(sStr));
                break;

            case VARIABLE:
                // Check if the variable is already assigned
                while (istart < MAX) {
                    if (scha_r[istart] == sStr[0]) {
                        printf("%c=%d\n", sStr[0], gvars[sStr[0] - 'a']);
                        push(gvars[sStr[0] - 'a']);
                        itrue_val = 0;
                    }
                    istart++;
                }

                // Assign variable if it was not previously assigned
                if (itrue_val) {
                    scha_r[iend++] = sStr[0];
                    gvars[sStr[0] - 'a'] = pop();
                    printf("%c=%d\n", sStr[0], gvars[sStr[0] - 'a']);
                }
                break;

            // Assign value to a variable
            case '=':
                gvars[sStr[0] - 'a'] = pop();
                printf("%c=%d\n", sStr[0], gvars[sStr[0] - 'a']);
                break;

            // Addition of two numbers
            case '+':
                push(pop() + pop());
                break;

            // Multiplication of two numbers
            case '*':
                push(pop() * pop());
                break;

            // Subtraction of two numbers
            case '-':
                dop2 = pop();
                push(pop() - dop2);
                break;

            // Print all stored variables
            case '@':
                print_all_variables();
                break;

            // Print the last result
            case 'l':
                print_last_result();
                break;

            // End of input line: print the last result
            case '\n':
                glast_result = gstk[gtop - 1];
                printf("%.8g\n", glast_result);
                break;

            default:
                printf("error: unknown command %s\n", sStr);
                break;
        }
    }
}

/* FUNCTION DEFINITIONS */

/* push: push a value onto the stack */
void push(double dvar)
{
    if (gtop == MAX) {
        printf("stack overflow...\n");
        return;
    }
    gstk[gtop++] = dvar;
}

/* pop: pop and return the top value from the stack */
double pop(void)
{
    if (gtop == 0) {
        // Stack underflow, return 0 as a default value
        return 0;
    }
    return gstk[--gtop];
}

/* print_all_variables: print all stored variables */
void print_all_variables()
{
    for (int i = 0; i < MAX; i++) {
        if (gvars[i] != 0) {
            printf("%c=%d\n", 'a' + i, gvars[i]);
        }
    }
}

/* print_last_result: print the last calculated result */
void print_last_result()
{
    printf("Last result = %.8g\n", glast_result);
}

/* BUFFER AND INPUT HANDLING FUNCTIONS */
int ibufp = 0;  // Buffer pointer for ungetch
char sbuf[BUFFSIZE]; // Buffer to hold pushed-back characters

/* getch: get a (possibly pushed-back) character */
int getch(void)
{
    return (ibufp > 0) ? sbuf[--ibufp] : getchar();
}

/* ungetch: push character back onto input */
void ungetch(int ivar)
{
    if (ibufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        sbuf[ibufp++] = ivar;
    }
}

/* getall: get next character or numeric operand */
int getall(char sStr[])
{
    int iNum = 0, iVar;
    while ((sStr[0] = iVar = getch()) == ' ' || iVar == '\t')
        ;
    sStr[1] = '\0';

    if (isalpha(iVar) && (iVar = getch()) != '=') {
        return VARIABLE;
    }

    if (!isdigit(iVar) && iVar != '.') {
        return iVar; // Not a number
    }

    // Collect integer part
    iNum = 0;
    if (isdigit(iVar)) {
        while (isdigit(sStr[++iNum] = iVar = getch()))
            ;
    }

    // Collect fractional part
    if (iVar == '.') {
        while (isdigit(sStr[++iNum] = iVar = getch()))
            ;
    }

    sStr[iNum] = '\0';
    if (iVar != EOF) {
        ungetch(iVar);
    }
    return NUMBER;
}

