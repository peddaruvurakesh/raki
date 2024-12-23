/*Question7-5
Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversion. 

Explanation
The task is to rewrite a postfix calculator program from Chapter 4 using scanf and/or sscanf for input and number conversion. The postfix calculator evaluates expressions in Reverse Polish Notation (RPN), where operators follow their operands*/






/*
AUTHOR : rakesh peaddruvu
created date :07/12/2024
modified date :07/12/2024
*/
//HEADDER FILES

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK 100  // Maximum stack size

// Stack structure and functions
double stack[MAX_STACK];
int stack_top = 0;

// Push a value onto the stack
void push(double value) {
    if (stack_top < MAX_STACK) {
        stack[stack_top++] = value;
    } else {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
}

// Pop a value from the stack
double pop() {
    if (stack_top > 0) {
        return stack[--stack_top];
    } else {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
}

// Main function
int main() {
    char input[100];  // Buffer to store the input expression
    printf("Enter the postfix expression: ");
    fgets(input, sizeof(input), stdin);  // Read the input expression

    char *token = input;
    char op;  // Operator
    double num;  // Operand
    double op1, op2;

    while (*token) {
        // Skip whitespaces
        if (isspace(*token)) {
            token++;
            continue;
        }

        // Process numbers
        if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) {
            sscanf(token, "%lf", &num);  // Read the number
            push(num);
            // Move token pointer forward to skip the processed number
            while (isdigit(*token) || *token == '.' || *token == '-') token++;
        }
        // Process operators
        else if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
            op = *token++;
            op2 = pop();  // Pop the top operand
            op1 = pop();  // Pop the next operand

            switch (op) {
                case '+':
                    printf("Evaluated: %.2lf + %.2lf\n", op1, op2);
                    push(op1 + op2);
                    break;
                case '-':
                    printf("Evaluated: %.2lf - %.2lf\n", op1, op2);
                    push(op1 - op2);
                    break;
                case '*':
                    printf("Evaluated: %.2lf * %.2lf\n", op1, op2);
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        printf("Evaluated: %.2lf / %.2lf\n", op1, op2);
                        push(op1 / op2);
                    } else {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Error: Unknown operator '%c'.\n", op);
                    exit(1);
            }
        }
        // Handle invalid input
        else {
            printf("Error: Invalid token '%c'.\n", *token);
            exit(1);
        }
    }

    // The final result should be the only value in the stack
    if (stack_top == 1) {
        printf("Result: %.2lf\n", pop());
    } else {
        printf("Error: Invalid postfix expression.\n");
    }

    return 0;
}

