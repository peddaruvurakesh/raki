/*
 * This program is to do alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.
 * Reverse Polish Notation Calculator
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 10 July, 2024
 *
 * This program implements a reverse Polish calculator that allows users
 * to perform various arithmetic operations. It uses `getline` to read
 * entire input lines, simplifying input handling.
 *
 * Input:
 * - A line of text containing numbers and operators in reverse Polish notation.
 * - Supported operators: +, -, *, /, %, D (duplicate), S (swap), T (peek), C (clear).
 *
 * Output:
 * - The result of the calculation is printed when the user inputs a newline character.
 * - Error messages are displayed for invalid operations or stack errors.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define MAX 50         // Maximum stack size
#define NUMBER '0'     // Signal that a number was found

/** FUNCTION PROTOTYPES */
void push(double);
int get_line(char line[], unsigned int max_line_len);
int getall(char []);
double pop(void);
double gstk[MAX];        // Global stack for calculator
void duplicatetop(void);
void swapTopTwo(void);
void peek(int);
void clearStack(void);
void printInstructions(void);

int gtop = 0;           // Global stack pointer
char line[MAX];        // Buffer for input line

/** MAIN PROGRAM */
/** main: Accepts input for reverse Polish calculator */
int main() {
    int itype;           // Type of token read
    printInstructions(); // Print calculator instructions

    while (get_line(line, MAX) != 0) {
        // Reverse Polish calculator
        int iline_i = 0; // Reset line index for each new line
        char sStr[MAX];  // Buffer for tokens

        while ((itype = getall(sStr)) != '\0') {
            switch (itype) {
                case NUMBER:
                    push(atof(sStr)); // Convert string to double and push
                    break;
                case '+':
                    push(pop() + pop()); // Addition
                    break;
                case '*':
                    push(pop() * pop()); // Multiplication
                    break;
                case '-':
                    {
                        double dop2 = pop();
                        push(pop() - dop2); // Subtraction
                    }
                    break;
                case '/':
                    {
                        double dop2 = pop();
                        if (dop2 != 0.0)
                            push(pop() / dop2); // Division
                        else
                            printf("error: zero divisor\n");
                    }
                    break;
                case '%':
                    {
                        double dop2 = pop();
                        if (dop2 != 0.0) {
                            int iresult = ((int)pop() % (int)dop2);
                            // Adjust result for negative modulus
                            if (iresult < 0 && dop2 > 0)
                                iresult += (int)dop2;
                            else if (iresult > 0 && dop2 < 0)
                                iresult += (int)dop2;
                            push(iresult);
                        } else {
                            printf("Error: zero divisor.\n");
                        }
                    }
                    break;
                case 'D': // Duplicate top element
                    duplicatetop();
                    break;
                case 'S': // Swap top 2 elements
                    swapTopTwo();
                    break;
                case 'T':
                    {
                        int inum;
                        printf("Number of top elements to print: ");
                        scanf("%d", &inum);
                        peek(inum);
                        clearStack();
                    }
                    break;
                case 'C': // Clear the stack
                    clearStack();
                    break;
                case '\n': // Print the result when newline is encountered
                    printf("%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s\n", sStr);
                    return 1;
            }
        }
    }
}

/* End of main() */

/* Print instructions for user access */
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
    printf(" - Print n Top Elements: T\n");
    printf(" - Clear the Stack: C\n");
    printf("Enter your commands:\n");
}

/* Push: Push f onto value stack */
void push(double dvar) {
    if (gtop == MAX) {
        printf("stack overflow...\n");
        return;
    }
    gstk[gtop++] = dvar; // Store the value and increment stack pointer
}

/* Pop: Pop and return top value from stack */
double pop(void) {
    if (gtop == 0) {
        printf("stack underflow...\n");
        return 0.0; // Return 0 if stack is empty
    }
    return gstk[--gtop]; // Decrement stack pointer and return value
}

/* Duplicate top element */
void duplicatetop(void) {
    if (gtop > 0) {
        double temp = gstk[gtop - 1]; // Get top element
        push(temp); // Push duplicate onto stack
    } else {
        printf("Error: Stack is empty, nothing to duplicate.\n");
    }
}

/* Swap top two elements */
void swapTopTwo(void) {
    if (gtop > 1) {
        double temp = gstk[gtop - 1]; // Swap the top two elements
        gstk[gtop - 1] = gstk[gtop - 2];
        gstk[gtop - 2] = temp;
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}

/* Peek: Print top n elements */
void peek(int inum) {
    if (gtop > 0) {
        for (int iIndex = 0; iIndex < inum && iIndex < gtop; iIndex++)
            printf("%d element: %.8g\n", iIndex + 1, gstk[gtop - 1 - iIndex]);
    } else {
        printf("Error: Stack is empty, can't print top element\n");
    }
}

/* Clear stack */
void clearStack(void) {
    while (gtop > 0) {
        gstk[--gtop] = 0.0; // Reset each element to 0
    }
}

/* getline(): to get entire line */
int get_line(char sline[], unsigned int imax_line_len) {
    int iVar, iNum;

    for (iNum = 0; iNum < imax_line_len - 1 && (iVar = getchar()) != EOF && iVar != '\n'; ++iNum) {
        sline[iNum] = iVar; // Store character in line buffer
    }

    if (iVar == '\n') {
        sline[iNum] = iVar; // Append newline character
        ++iNum;
    }

    sline[iNum] = '\0'; // Null-terminate the string
    return iNum; // Return the number of characters read
}

/* getall(): To check input and process tokens */
int getall(char sStr[]) {
    int iVar;
    int iIndex = 0;

    // Skip any white spaces
    while ((iVar = line[iline_i]) == ' ' || iVar == '\t') {
        iline_i++;
    }

    // Check if it's a number
    if (!isdigit(iVar) && iVar != '.' && iVar != '-') {
        // If it's not a number, return the character itself
        return line[iline_i++];
    }

    // Process a negative number or just a minus sign
    if (iVar == '-') {
        if (isdigit(line[iline_i + 1]) || line[iline_i + 1] == '.') {
            sStr[iIndex++] = iVar; // Store negative sign
            iVar = line[++iline_i];
        } else {
            return line[iline_i++]; // Return the minus sign
        }
    }

    // Collect integer part
    if (isdigit(iVar)) {
        do {
            sStr[iIndex++] = iVar; // Store digit
            iVar = line[++iline_i]; // Move to next character
        } while (isdigit(iVar)); // Continue while digits are found
    }

    // Collect fraction part if any
    if (iVar == '.') {
        sStr[iIndex++] = iVar; // Store decimal point
        while (isdigit(iVar = line[++iline_i])) {
            sStr[iIndex++] = iVar; // Store digits after decimal point
        }
    }

    sStr[iIndex] = '\0'; // Null-terminate the string
    return NUMBER; // Signal that a number was found
}

/* End of getall() */

