/* Question7-4
Write a private version of scanf analogous to minprintf from the previous section

Explanation
The task is to implement a private version of scanf, analogous to the minprintf function provided earlier. The custom minscanf function should process a format string and read input based on the specified format. This involves handling variable-length argument lists and correctly interpreting format specifiers to read different types of input.*/

/*
AUTHOR : rakesh peaddruvu
created date :07/12/2024
modified date :07/12/2024
*/

/*HEADDER FILES*/
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void minscanf(const char *fmt, ...) {
    va_list ap; // Declare a variable to traverse the argument list
    const char *p;
    int *ival;
    float *fval;
    char *sval;
    char *cval;
    
    va_start(ap, fmt); // Initialize the va_list variable

    for (p = fmt; *p != '\0'; p++) {
        if (*p != '%') {
            continue; // Skip non-format specifiers
        }

        switch (*++p) { // Process the next character after '%'
            case 'd': // Integer
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'f': // Float
                fval = va_arg(ap, float *);
                scanf("%f", fval);
                break;
            case 's': // String
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            case 'c': // Character
                cval = va_arg(ap, char *);
                scanf(" %c", cval); // Use " %c" to skip whitespace
                break;
            default:
                printf("Unsupported format specifier: %c\n", *p);
                break;
        }
    }

    va_end(ap); // Clean up the va_list variable
}
//MAIN FUNCTION
int main() {
    int int_val;
    float float_val;
    char str_val[100];
    char char_val;

    printf("Enter an integer: ");
    minscanf("%d", &int_val);

    printf("Enter a float: ");
    minscanf("%f", &float_val);

    printf("Enter a string: ");
    minscanf("%s", str_val);

    printf("Enter a character: ");
    minscanf("%c", &char_val);

    printf("\nYou entered:\n");
    printf("Integer: %d\n", int_val);
    printf("Float: %f\n", float_val);
    printf("String: %s\n", str_val);
    printf("Character: '%c'\n", char_val);

    return 0;
}
