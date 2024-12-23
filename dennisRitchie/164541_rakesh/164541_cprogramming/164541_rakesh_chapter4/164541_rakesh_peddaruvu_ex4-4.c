  {/*
 * This program implements an extended Reverse Polish Notation (RPN) calculator.
 * It supports basic operations like addition, subtraction, multiplication, division, and modulus,
 * as well as additional stack operations such as duplication, swapping the top two elements, peeking at the top elements, and clearing the stack.
 *
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 8 July, 2024
 * 
 * INPUT:
 * - The program takes operations and numbers in Reverse Polish Notation.
 *   Example: To evaluate (3 + 5) * 2, enter: 3 5 + 2 *
 * 
 * OUTPUT:
 * - Outputs the result after evaluating the expression.
 * - Displays error messages in case of invalid operations or stack conditions.
 * 
 * OPERATIONS SUPPORTED:
 * - + : Addition
 * - - : Subtraction
 * - * : Multiplication
 * - / : Division
 * - % : Modulus
 * - D : Duplicate the top element of the stack
 * - S : Swap the top two elements of the stack
 * - T : Print the top n elements of the stack
 * - C : Clear the stack
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define MAX 50        // Maximum stack size
#define NUMBER '0'    // Signal that a number was found
#define BUFFSIZE 100  // Buffer size for input

/** FUNCTION PROTOTYPES */
void push(double);
int getall(char[]);
double pop(void);
void duplicatetop(void);
void swapTopTwo(void);
void peek(int);
void clearStack(void);
void printInstructions(void);

/** GLOBAL VARIABLES */
double gstk[MAX];  // Stack array to hold double values
int gtop = 0;      // Top of stack pointer

/** MAIN PROGRAM */
/** 
 * main: Accepts input and acts as a reverse Polish notation calculator.
 * Supports basic arithmetic and stack operations.
 */
int main() {
    int itype, inum;
    double d_op2;
    char sStr[MAX];

    // Display the available operations to the user
    printInstructions();

    // Reverse Polish calculator loop
    while ((itype = getall(sStr)) != EOF) {
        switch (itype) {
            case NUMBER:  // If a number is found
                push(atof(sStr));
                break;
            case '+':  // Addition
                push(pop() + pop());
                break;
            case '*':  // Multiplication
                push(pop() * pop());
                break;
            case '-':  // Subtraction
                d_op2 = pop();
                push(pop() - d_op2);
                break;
            case '/':  // Division
                d_op2 = pop();
                if (d_op2 != 0.0)
                    push(pop() / d_op2);
                else
                    printf("Error: Zero divisor\n");
                break;
            case '%':  // Modulus
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
                    printf("Error: Zero divisor\n");
                }
                break;
            case 'D':  // Duplicate top element of the stack
                duplicatetop();
                break;
            case 'S':  // Swap top 2 elements of the stack
                swapTopTwo();
                break;
            case 'T':  // Print n top elements
                printf("Number of elements to print: ");
                scanf("%d", &inum);
                peek(inum);
                break;
            case 'C':  // Clear the stack
                clearStack();
                printf("Stack cleared\n");
                break;
            case '\n':  // Print the stack elements
                for (int ivar = 0; ivar < gtop; ivar++)
                    printf("%.8g ", gstk[ivar]);
                printf("\n");
                break;
            default:
                printf("Error: Unknown command %s\n", sStr);
                return 1;
                break;
        }
    }
}

/** FUNCTION DEFINITIONS */

// Display instructions for using the calculator
void printInstructions(void) {
    printf("Welcome to the RPN Calculator!\n");
    printf("You can perform the following operations:\n");
    printf(" - Addition: +\n");
    printf(" - Subtraction: -\n");
    printf(" - Multiplication: *\n");
    printf(" - Division: /\n");
    printf(" - Modulo: %%\n");
    printf(" - Duplicate Top Element: D\n");
    printf(" - Swap Top 2 Elements: S\n");
    printf(" - Print n Top Elements: T\n");
    printf(" - Clear the Stack: C\n");
    printf("Enter your commands:\n");
}

// Push a value onto the stack
void push(double dvar) {
    if (gtop == MAX) {
        printf("Error: Stack overflow\n");
        return;
    }
    gstk[gtop++] = dvar;
}

// Pop and return the top value from the stack
double pop(void) {
    if (gtop == 0) {
        printf("Error: Stack underflow\n");
        return 0.0;
    }
    return gstk[--gtop];
}

// Duplicate the top element of the stack
void duplicatetop(void) {
    if (gtop > 0) {
        double dtemp = gstk[gtop - 1];
        gstk[gtop++] = dtemp;
    } else {
        printf("Error: Stack is empty, nothing to duplicate\n");
    }
}

// Swap the top two elements of the stack
void swapTopTwo(void) {
    if (gtop > 1) {
        double dtemp = gstk[gtop - 1];
        gstk[gtop - 1] = gstk[gtop - 2];
        gstk[gtop - 2] = dtemp;
    } else {
        printf("Error: Not enough elements to swap\n");
    }
}

// Print the top n elements of the stack
void peek(int inum) {
    if (inum > gtop) {
        printf("Error: Requested more elements than available in the stack\n");
    } else {
        for (int i = 0; i < inum; i++) {
            printf("%d element: %.8g\n", i + 1, gstk[gtop - 1 - i]);
        }
    }
}

// Clear the stack
void clearStack(void) {
    gtop = 0;  // Reset the top pointer to 0, effectively clearing the stack
}

// Get the next character or numeric operand
int getall(char sStr[]) {
    int iNum = 0, iVar;
    // Skip whitespace
    while ((sStr[0] = iVar = getch()) == ' ' || iVar == '\t');
    sStr[1] = '\0';

    if (!isdigit(iVar) && iVar != '.' && iVar != '-') {
        return iVar;  // Not a number
    }

    if (iVar == '-') {
        char cnext = getch();
        if (isdigit(cnext) || cnext == '.') {
            sStr[++iNum] = iVar = cnext;
        } else {
            ungetch(cnext);
            return iVar;  // It's just a negative sign as an operator
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

// Get a (possibly pushed-back) character
int getch(void) {
    static char sbuf[BUFFSIZE];
    static int ibufp = 0;

    return (ibufp > 0) ? sbuf[--ibufp] : getchar();
}

// Push a character back on input
void ungetch(int iNum) {
    static char sbuf[BUFFSIZE];
    static int ibufp = 0;

    if (ibufp >= BUFFSIZE) {
        printf("Error: Too many characters\n");
    } else {
        sbuf[ibufp++] = iNum;
    }
}

    gstk[--gtop] = 0.0;
  }
}
/* End of clearstack*/

