/*
 * This program modifies the `itoa()` function to handle the largest negative number correctly
 * in two's complement representation. The challenge with representing the largest negative number 
 * arises because its absolute value exceeds the range of positive integers that can be represented.
 * 
 * Example:
 *   INT_MIN for a 32-bit system is -2147483648, but the positive range is only up to +2147483647.
 *   Therefore, simply negating INT_MIN does not yield a valid positive integer within range.
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 8 July, 2024
 * Modified : 8 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>   // Provides string handling functions
#include <limits.h>   // Provides macros for INT_MIN and INT_MAX

/** MACRO DEFINITIONS */
#define WORDS 100  // Maximum length for string representation of number

/** FUNCTION PROTOTYPES */
void my_Itoa(int n, char s[]);
void my_Reverse(char s[]);

/** MAIN PROGRAM */
/** main: Converts integer to string by calling `my_Itoa()` */
int main() {
    long int ln;  // Variable to hold the input number
    char sStr[WORDS];  // Array to store the resulting string

    // Get user input for the number
    scanf("%ld", &ln);

    // Check if the entered number is within the valid range of an integer
    if (ln > INT_MAX || ln < INT_MIN) {
        printf("Entered number not in range\n");
        return 0;  // Exit if out of range
    }

    // Call the function to convert integer to string
    my_Itoa(ln, sStr);

    // Reverse the resulting string for proper representation
    my_Reverse(sStr);

    // Print the resulting string
    printf("string = %s\n", sStr);

    return 0;
}
/* End main() */

/** my_Itoa: Converts an integer to a string */
void my_Itoa(int inum, char sStr[]) {
    int iIndex = 0, isign;

    // Handle INT_MIN specifically because its absolute value cannot be represented within int range
    if ((isign = inum) == INT_MIN) {
        inum = -(inum + 1);  // Make the value positive, handling overflow issue by adding 1
    } else if ((isign = inum) < 0) {
        inum = -inum;  // Make the value positive if negative
    }

    // Generate the string representation of the number in reverse order
    do {
        sStr[iIndex++] = inum % 10 + '0';  // Get the next digit and convert to character
    } while ((inum /= 10) > 0);  // Continue until all digits are processed

    // If the original number was INT_MIN, we need to correct the last digit
    if (isign == INT_MIN) {
        sStr[0] += 1;  // Increment the last digit to correct for INT_MIN offset
    }

    // If the number was negative, add the negative sign
    if (isign < 0) {
        sStr[iIndex++] = '-';
    }

    // Null terminate the resulting string
    sStr[iIndex] = '\0';
}
/* End my_Itoa */

/** my_Reverse: Reverses a given string in place */
void my_Reverse(char sStr[]) {
    int itemp, iIndex1, iIndex2;

    // Loop to reverse the string by swapping characters
    for (iIndex1 = 0, iIndex2 = strlen(sStr) - 1; iIndex1 < iIndex2; iIndex1++, iIndex2--) {
        itemp = sStr[iIndex1];       // Temporary store for swapping
        sStr[iIndex1] = sStr[iIndex2];  // Swap characters
        sStr[iIndex2] = itemp;       // Complete the swap
    }
}
/* End my_Reverse() */

