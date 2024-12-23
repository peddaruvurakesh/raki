#include <stdio.h>
#include <assert.h>

// Function to calculate factorial of a positive integer
int factorial(int n) {
    // Assert that the input is a non-negative number
    assert(n >= 0);
    
    int result = 1;
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    // Assert that the result is never zero for positive inputs
    assert(result > 0 || n == 0);  // Factorial of 0 is 1
    
    return result;
}

int main() {
    int num;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    // Assert that the input number is within a reasonable limit
    assert(num >= 0 && num <= 12);  // Restricting to 12 to prevent integer overflow

    int fact = factorial(num);

    printf("Factorial of %d is %d\n", num, fact);

    return 0;
}

