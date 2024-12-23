/*Question:7.3
Revise minprintf to handle more of the other facilities of printf

Explanation
The task is to enhance the minprintf function to handle more format specifiers and features similar to the standard printf function. The initial minprintf implementation only supports a few basic specifiers (%d, %f, and %s). The goal is to extend minprintf to support additional format specifiers and possibly other functionalities that printf offers.
 * 
 * 
 * Sample Input:
 * Enter a string, an integer, and a float: Hello 42 3.14
 * 
 * Sample Output:
 * Hello
 * 42
 * 3.140000
 */
/*
NAME : Rakesh
created date :04/12/2024
modified date : 04/12/2024
*/




//HEADDER FILES
#include <stdio.h>
#include <stdarg.h>

void minprintf(const char *fmt, ...);

int main(void) {
    // Input variables
    char a[15];
    int b;
    float f;

    // Prompt the user for input
    printf("Enter a string, an integer, and a float: ");
    scanf("%s %d %f", a, &b, &f);

    // Print the inputs using the custom minprintf function
    minprintf("%s\n%d\n%f\n", a, b, f);

    return 0; // Exit program
}

void minprintf(const char *fmt, ...) {
    va_list ap; // Points to each unnamed argument in turn
    const char *p;
    char *sval;  // To hold string arguments
    int ival;    // To hold integer arguments
    double dval; // To hold float/double arguments

    va_start(ap, fmt); // Initialize the argument pointer

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p); // Print regular characters
            continue;
        }

        // Handle format specifiers
        switch (*++p) {
            case 'd': // Integer
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;

            case 'f': // Float/Double
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;

            case 's': // String
                sval = va_arg(ap, char *);
                for (; *sval; sval++) // Print each character of the string
                    putchar(*sval);
                break;

            default: // Unrecognized specifier
                putchar(*p);
                break;
        }
    }

    va_end(ap); // Clean up when done
}

