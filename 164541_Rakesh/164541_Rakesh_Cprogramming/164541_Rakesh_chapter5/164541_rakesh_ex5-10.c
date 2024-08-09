/*
 *  Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument.
 *  expr 2 3 4 + *
 *  evaluates 2 * (3+4).
 *
 * Author: rakesh
 * Created: 19 July, 2024
 * Modified:31 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define MAX 100

/* signal that a number was found */
#define NUMBER '0'

/** FUNCTION PROTOTYPES */
void push(double);
double pop(void);
int getop(char[]);

/** GLOBAL VARIABLES */
double stk[MAX];
int top = 0;

/** MAIN PROGRAM */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    
    if (argc < 2) {
        printf("Usage: expr <expression>\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        type = getop(argv[i]);

        switch (type) {
            case NUMBER:
                push(atof(argv[i]));
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
            case '%':
                op2 = pop();
                if ((int)op2 != 0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", argv[i]);
                return 1;
        }
    }

    printf("Result: %.8g\n", pop());
    return 0;
}

/** FUNCTION DEFINITIONS */

/* push: push f onto value stack */
void push(double f)
{
    if (top < MAX) {
        stk[top++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (top > 0) {
        return stk[--top];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: determine if the input is a number or an operator */
int getop(char s[])
{
    if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))) {
        return NUMBER;
    }
    
    
    else {
        return s[0];
    }
}

