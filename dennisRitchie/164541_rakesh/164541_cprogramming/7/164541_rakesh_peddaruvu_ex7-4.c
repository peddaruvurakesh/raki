/*
* This program is to  a private version of scanf analogous to minprintf from the previous 
section.*/
/* Author: rakesh
* Created: 16 July, 2024
* Modified:16 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdarg.h>
/** MACRO DEFINITIONS */

/** FUNCTION PROTOTYPES */
void minscanf(const char *fmt, ...);
/** MAIN PROGRAM */
/** main: To scan variable arguments */

int main() {
    int iNum;
    float fDnum;
    double dDoub;
    unsigned int uUnint;
    char cCharacter;
    char sStr[50];
    void *pPointer;

    // Input Section using minscanf
    printf("Enter integer number: ");
    minscanf("%d", &iNum);

    printf("Enter float number: ");
    minscanf("%f", &fDnum);

    printf("Enter double number: ");
    minscanf("%lf", &dDoub);

    printf("Enter unsigned integer number: ");
    minscanf("%u", &uUnint);

    printf("Enter character: ");
    minscanf(" %c", &cCharacter);

    printf("Enter string: ");
    minscanf("%s", sStr);

    pPointer = &iNum; // Example of a pointer (address of iNum)

    // Output Section
    printf("You have entered:\n");
    printf("Integer iNum: %d\n", iNum);
    printf("Float fDnum: %f\n", fDnum);
    printf("Double dDoub: %lf\n", dDoub);
    printf("Unsigned integer uUnint: %u\n", uUnint);
    printf("Character cCharacter: %c\n", cCharacter);
    printf("String sStr: %s\n", sStr);
    printf("Octal representation of iNum: %o\n", iNum);
    printf("Hexadecimal representation of iNum: %x\n", iNum);
    printf("Pointer pPointer: %p\n", pPointer);

    return 0;
}

/* End main() */
/* minscanf(): my scanf function */
/* Author: rakesh
* Created: 16 July, 2024
* Modified:16 July, 2024
*/
void minscanf(const char *sfmt, ...) {
    va_list ap;
    const char *p;
    int *ip;
    float *fp;
    double *dp;
    unsigned int *up;
    char *cp;
    char *sp;

    va_start(ap, sfmt);
    for (p = sfmt; *p; p++) {
        if (*p == '%') {
            p++; /* Move past '%' */
            switch (*p) {
                case 'd': /* Integer */
                    ip = va_arg(ap, int*);
                    scanf("%d", ip);
                    break;
                case 'f': /* Float */
                    fp = va_arg(ap, float*);
                    scanf("%f", fp);
                    break;
                case 'l': /* Double */
                    if (*(p + 1) == 'f') {
                        dp = va_arg(ap, double*);
                        scanf("%lf", dp);
                        p++; /* Skip 'f' after 'l' */
                    }
                    break;
                case 'u': /* Unsigned Integer */
                    up = va_arg(ap, unsigned int*);
                    scanf("%u", up);
                    break;
                case 'c': /* Character */
                    cp = va_arg(ap, char*);
                    scanf(" %c", cp); /* The space before %c is important to skip whitespace */
                    break;
                case 's': // String
                    sp = va_arg(ap, char*);
                    scanf("%s", sp);
                    break;
                case 'o': // Octal
                    ip = va_arg(ap, int*);
                    scanf("%o", ip);
                    break;
                case 'x': // Hexadecimal
                    ip = va_arg(ap, int*);
                    scanf("%x", ip);
                    break;
                
                default:
                    /* Handle unexpected format specifiers (e.g., error or unsupported types) */
                    break;
            }
        }
    }
    va_end(ap);
}

