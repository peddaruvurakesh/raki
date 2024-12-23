/**
 * Program Name: Reverse Polish Notation (RPN) Calculator
 * Author: Rakesh Peddaruvu
 * Date: 28/11/2024
 * 
 * Description:
 * This program implements a Reverse Polish Notation (RPN) calculator using command-line arguments. 
 * It evaluates arithmetic expressions provided in postfix notation. 
 * The calculator supports basic operations: addition (+), subtraction (-), multiplication (*), and division (/).
 * 
 
 * Sample Input:
 *   ./rpn_calculator 5 1 2 + 4 * + 3 -
 * 
 * Sample Output:
 *   14
 * 
 * Error Examples:
 *   ./rpn_calculator 5 1 0 /
 *   Output: error: zero divisor
 * 
 * Notes:
 * - Numbers are treated as operands and are pushed onto the stack.
 * - Operators are applied to the topmost operands on the stack.
 * - Input arguments must be space-separated.
 */

#include <stdio.h>
#include <math.h>  /* for atof() */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXOP 100   /* maximum size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of value stack */
#define BUFSIZE 100 /* buffer size for ungetch */

/* Function Prototypes */
int getop(char[]);
void ungets(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* Global Variables */
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* Main Function: Reverse Polish Notation Calculator */
int main(int argc, char *argv[]) {
    char s[MAXOP];
    double op2;

    /* Process command-line arguments */
    while (--argc > 0) {
        ungets(" ");    /* Push end of argument */
        ungets(*++argv); /* Push the argument string */

        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                argc = 1; /* Exit early on error */
                break;
        }
    }
    printf("\t%8g\n", pop()); /* Print the result */
    return 0;
}

/* getop: Get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; /* Skip whitespace */

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* Not a number */

    i = 0;
    if (isdigit(c)) /* Collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* Collect fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* push: Push value onto the stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: Pop and return top value from the stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getch: Get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: Push character back onto input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets: Push string back onto the input buffer */
void ungets(char s[]) {
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

