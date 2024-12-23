
/*

*author : Rakesh peddaruvu
*created date :5/10/2024
*modified date: 5/10/2024

*/

/* HEADDERFILES */
#include <stdio.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
/* MAIN FUNCTION */
int main() {
    // Function pointer declaration
    int (*operation)(int, int);

    int x = 10, y = 5;

    // Point the function pointer to the 'add' function
    operation = &add;
    printf("Addition: %d + %d = %d\n", x, y, operation(x, y));

    // Point the function pointer to the 'subtract' function
    operation = &subtract;
    printf("Subtraction: %d - %d = %d\n", x, y, operation(x, y));

    // Point the function pointer to the 'multiply' function
    operation = &multiply;
    printf("Multiplication: %d * %d = %d\n", x, y, operation(x, y));

    // Point the function pointer to the 'divide' function
    operation = &divide;
    printf("Division: %d / %d = %d\n", x, y, operation(x, y));

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}
