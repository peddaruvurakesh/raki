/*
 * Program to implement a Reverse Polish Notation (RPN) calculator.
 * This calculator can handle common operations (+, -, *, /, %) as well as functions like sin, exp, and pow.
 * Additional features include duplicating, swapping, and clearing stack elements.
 *
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 8 July, 2024
 *
 * INPUT:
 * - Operators (+, -, *, /, %, D, S, T, C, s, e, p)
 * - Numerical operands
 * 
 * OUTPUT:
 * - The result of operations in RPN format.
 *
 * Example Input and Output:
 * 5 3 +       => Output: 8
 * 2 s         => Output: sin(2) = 0.90929743
 * 4 3 p       => Output: 4^3 = 64
 * D           => Duplicate top element.
 * S           => Swap top two elements.
 * T 3         => Print top 3 elements.
 * C           => Clear the stack.
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/** MACRO DEFINITIONS */
#define MAX 50
/* Signal that a number was found */
#define NUMBER '0'
#define BUFFSIZE 100

/** FUNCTION PROTOTYPES */
void push(double value);
int getall(char s[]);
double pop(void);
void duplicateTop(void);
void swapTopTwo(void);
void peek(int num);
void clearStack(void);
void printInstructions(void);

/** GLOBAL VARIABLES */
double gstk[MAX]; // Stack array to store numbers
int gtop = 0;     // Index for top of the stack
int ibufp = 0;    // Buffer index for ungetch()
char sbuf[BUFFSIZE]; // Buffer for ungetch()

/** MAIN PROGRAM */
/** 
 * Accepts input and works as a Reverse Polish calculator.
 * It performs basic arithmetic operations, including additional functions such as sin, exp, and pow.
 */
int main() {
    int itype, inum;
    double d_op2;
    char sStr[MAX];

    printInstructions();

    // Reverse Polish calculator
    while ((itype = getall(sStr)) != EOF) {
        switch (itype) {
            case NUMBER: // If number was found
                push(atof(sStr));
                break;
            case '+': // Addition
                push(pop() + pop());
                break;
            case '*': // Multiplication
                push(pop() * pop());
                break;
            case '-': // Subtraction
                d_op2 = pop();
                push(pop() - d_op2);
                break;
            case '/': // Division
                d_op2 = pop();
                if (d_op2 != 0.0)
                    push(pop() / d_op2);
                else
                    printf("Error: Zero divisor\n");
                break;
            case '%': // Modulus
                d_op2 = pop();
                if (d_op2 != 0.0) {
                    int result = ((int)pop() % (int)d_op2);
                    // Adjust result for negative modulus
                    if (result < 0 && d_op2 > 0) {
                        result += (int)d_op2;
                    } else if (result > 0 && d_op2 < 0) {
                        result += (int)d_op2;
                    }
                    push(result);
                } else {
                    printf("Error: Zero divisor.\n");
                }
                break;
            case 'D': // Duplicate top element of the stack
                duplicateTop();
                break;
            case 'S': // Swap top two elements of the stack
                swapTopTwo();
                break;
            case 'T': // Print top n elements
                printf("Number of top elements: ");
                scanf("%d", &inum);
                peek(inum);
                break;
            case 'C': // Clear the stack
                clearStack();
                printf("Cleared the stack\n");
                break;
            case 'p': // Power operation
                d_op2 = pop();
                push(pow(pop(), d_op2));
                break;
            case 's': // Sine operation
                push(sin(pop()));
                break;
            case 'e': // Exponential operation
                push(exp(pop()));
                break;
            case '\n': // Print the top value
                printf("%.8g\n", pop());
                break;
            default:
                printf("Error: Unknown command %s\n", sStr);
                return 1;
        }
    }
}

/** FUNCTION DEFINITIONS */

/** 
 * Print the instructions to guide the user on how to use the calculator.
 */
void printInstructions(void) {
    printf("Welcome to the Calculator!\n");
    printf("You can perform the following operations:\n");
    printf(" - Addition: +\n");
    printf(" - Subtraction: -\n");
    printf(" - Multiplication: *\n");
    printf(" - Division: /\n");
    printf(" - Modulo: %%\n");
    printf(" - Duplicate Top Element: D\n");
    printf(" - Swap Top 2 Elements: S\n");
    printf(" - Print top n Elements: T\n");
    printf(" - Print in sine form: s\n");
    printf(" - Print in exponential form: e\n");
    printf(" - Power operation: p\n");
    printf(" - Clear the Stack: C\n");
    printf("Enter your commands:\n");
}

/** 
 * Push value onto the stack.
 * 
 * @param value - the value to be pushed onto the stack.
 */
void push(double value) {
    if (gtop == MAX) {
        printf("Stack overflow\n");
        return;
    }
    gstk[gtop++] = value;
}

/** 
 * Pop and return top value from stack.
 * 
 * @return the top value from the stack.
 */
double pop(void) {
    if (gtop == 0) {
        printf("Stack underflow\n");
        return 0.0;
    }
    return gstk[--gtop];
}

/** 
 * Get the next character or numeric operand.
 * 
 * @param sStr - string to store the operand.
 * @return the type of input (number or operator).
 */
int getall(char sStr[]) {
    int iNum = 0, iVar;

    // Escape whitespaces
    while ((sStr[0] = iVar = getch()) == ' ' || iVar == '\t');

    sStr[1] = '\0';

    if (!isdigit(iVar) && iVar != '.' && iVar != '-') {
        return iVar; // Not a number
    }

    iNum = 0;
    if (iVar == '-') {
        char cnext = getch();
        if (isdigit(cnext) || cnext == '.') {
            sStr[++iNum] = iVar = cnext;
        } else {
            ungetch(cnext);
            return iVar;
        }
    }

    if (isdigit(iVar)) {
        while (isdigit(sStr[++iNum] = iVar = getch()));
    }

    if (iVar == '.') {
        while (isdigit(sStr[++iNum] = iVar = getch()));
    }

    sStr[iNum] = '\0';
    if (iVar != EOF) {
        ungetch(iVar);
    }
    return NUMBER;
}

/** 
 * Duplicate the top element of the stack.
 */
void duplicateTop(void) {
    if (gtop > 0) {
        push(gstk[gtop - 1]);
    } else {
        printf("Error: Stack is empty, nothing to duplicate.\n");
    }
}

/** 
 * Swap the top two elements of the stack.
 */
void swapTopTwo(void) {
    if (gtop > 1) {
        double temp = gstk[gtop - 1];
        gstk[gtop - 1] = gstk[gtop - 2];
        gstk[gtop - 2] = temp;
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}

/** 
 * Print the top n elements of the stack.
 * 
 * @param num - the number of elements to print from the top of the stack.
 */
void peek(int num) {
    if (gtop > 0 && num <= gtop) {
        for (int i = 0; i < num; i++) {
            printf("%d element: %.8g\n", i + 1, gstk[gtop - i - 1]);
        }
    } else {
        printf("Error: Insufficient elements in stack to print\n");
    }
}

/** 
 * Clear all elements from the stack.
 */
void clearStack(void) {
    while (gtop > 0) {
        gstk[--gtop] = 0.0;
    }
}

/** 
 * Get a (possibly pushed-back) character.
 * 
 * @return the character from input or buffer.
 */
int getch(void) {
    return (ibufp > 0) ? sbuf[--ibufp] : getchar();
}

/** 
 * Push character back on input.
 * 
 * @param iVar - the character to push back to the buffer.
 */
void ungetch(int iVar) {
    if (ibufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        sbuf[ibufp++] = iVar;
    }
}

