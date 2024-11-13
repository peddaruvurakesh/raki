#include <stdio.h>

// Function declaration
int factorial(int n);

int main() {
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));  // Function call
    return 0;
}

// Function definition
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

