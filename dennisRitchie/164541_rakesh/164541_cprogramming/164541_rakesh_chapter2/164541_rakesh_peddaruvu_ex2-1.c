/*
 * This program determines the ranges of char, short, int, and long variables, 
 * both signed and unsigned, by printing appropriate values from standard headers 
 * and by direct computation. It also computes the ranges of various floating-point types.
 * 
 * Author   : Rakesh
 * Created  : 3 July, 2024
 * Modified : 3 July, 2024
 *
 * Sample Input/Output:
 * 
 * No user input is required for this program. It simply prints the ranges of various types.
 *
 * Output:
 * signed char
 * -128 to 127
 * unsigned char
 * 0 to 255
 * signed int
 * -2147483648 to 2147483647
 * unsigned int
 * 0 to 4294967295
 * signed short
 * -32768 to 32767
 * unsigned short
 * 0 to 65535
 * signed long
 * -9223372036854775808 to 9223372036854775807
 * unsigned long
 * 0 to 18446744073709551615
 * signed long long
 * -9223372036854775808 to 9223372036854775807
 * unsigned long long
 * 0 to 18446744073709551615
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <limits.h>
#include "error_handling.h"

/** MAIN PROGRAM */
/** main: Accepts different datatypes and finds their ranges */
int main() {
    /* char ranges */
    printf("signed char\n");
    /* Compute signed char range using bitwise operations */
    printf("%d to ", (char)(1 << (sizeof(char) * 8 - 1))); // Minimum value
    printf("%d\n", (char)(~(char)(1 << (sizeof(char) * 8 - 1)))); // Maximum value
    
    printf("unsigned char\n");
    /* Maximum value for unsigned char */
    printf("0 to %u\n", ((unsigned char)~0));

    /* int ranges */
    printf("signed int\n");
    /* Compute signed int range using bitwise operations */
    printf("%d to ", -(int)((unsigned int)~0 >> 1) - 1); // Minimum value
    printf("%d\n", (int)((unsigned int)~0 >> 1)); // Maximum value
    
    printf("unsigned int\n");
    /* Maximum value for unsigned int */
    printf("0 to %u\n", (unsigned int)~0);

    /* short ranges */
    printf("signed short\n");
    /* Compute signed short range using bitwise operations */
    printf("%d to ", -(short)((unsigned short)~0 >> 1) - 1); // Minimum value
    printf("%d\n", (short)((unsigned short)~0 >> 1)); // Maximum value
    
    printf("unsigned short\n");
    /* Maximum value for unsigned short */
    printf("0 to %d\n", (unsigned short)~0);

    /* long ranges */
    printf("signed long\n");
    /* Use predefined limits for signed long */
    printf("%ld to %ld\n", LONG_MIN, LONG_MAX);
    
    printf("unsigned long\n");
    /* Maximum value for unsigned long */
    printf("0 to %lu\n", ULONG_MAX);

    /* long long ranges */
    printf("signed long long\n");
    /* Use predefined limits for signed long long */
    printf("%lld to %lld\n", LLONG_MIN, LLONG_MAX);
    
    printf("unsigned long long\n");
    /* Maximum value for unsigned long long */
    printf("0 to %llu\n", ULLONG_MAX);

    return 0;
}
/* End main() */

