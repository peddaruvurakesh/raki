#include <stdio.h>
#include <stdarg.h>

void minprintf(const char *fmt, ...);

int main(void) {
    printf("Testing minprintf:\n");
    minprintf("Integer (%%d):                   %d\n", 10);
    minprintf("Unsigned Integer (%%u):          %u\n", 20);
    minprintf("Float (%%f):                     %f\n", 3.14f);
    minprintf("String (%%s):                    %s\n", "Hello");
    minprintf("Pointer (%%p):                   %p\n", (void*)0x123456);
    minprintf("Character (%%c):                 %c\n", 'A');
    minprintf("Long Integer (%%ld):             %ld\n", 1234567890L);
    minprintf("Unsigned Long Integer (%%lu):    %lu\n", 9876543210UL);
    minprintf("Double (%%lf):                   %lf\n", 2.71828);
    return 0;
}

void minprintf(const char *fmt, ...) {
    va_list ap; // Declare a variable to process variable arguments
    const char *p;
    char *sval;
    int ival;
    unsigned int uval;
    long int lval;
    unsigned long ulval;
    double dval;
    void *pval;
    char cval;

    va_start(ap, fmt); // Initialize the variable argument list

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'd': // Integer
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'u': // Unsigned Integer
                uval = va_arg(ap, unsigned int);
                printf("%u", uval);
                break;
            case 'f': // Float
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's': // String
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'p': // Pointer
                pval = va_arg(ap, void *);
                printf("%p", pval);
                break;
            case 'c': // Character
                cval = (char)va_arg(ap, int); // Characters are promoted to int
                putchar(cval);
                break;
            case 'l': // Long or Double
                if (*++p == 'd') { // Long Integer
                    lval = va_arg(ap, long int);
                    printf("%ld", lval);
                } else if (*p == 'u') { // Unsigned Long Integer
                    ulval = va_arg(ap, unsigned long);
                    printf("%lu", ulval);
                } else if (*p == 'f') { // Double
                    dval = va_arg(ap, double);
                    printf("%lf", dval);
                } else {
                    printf("Unknown format specifier: %%l%c\n", *p);
                }
                break;
            default:
                putchar('%');
                putchar(*p);
                break;
        }
    }

    va_end(ap); // Clean up
}

