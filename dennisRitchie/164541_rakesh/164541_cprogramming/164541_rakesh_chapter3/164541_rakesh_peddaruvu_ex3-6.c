/*
 * This program defines a version of `itoa` that accepts three arguments: an integer `n`, 
 * a string `s`, and a minimum field width. The converted number is padded with blanks on 
 * the left if necessary to meet the specified width.
 * 
 * Sample Input:
 * Enter a number: 
 * -123
 * Enter minimum field width: 
 * 6
 * 
 * Sample Output:
 * "  -123"
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 9 July, 2024
 * Modified : 16 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>  // For input/output functions
#include <string.h> // For string handling functions

/** MACRO DEFINITIONS */
#define WORDS 100  // Maximum length of the result string

/** FUNCTION PROTOTYPES */
void my_Itoa(int n, char s[], int width);
void reverse(char s[]);

/** MAIN PROGRAM */
/** main: Converts an integer to a string with minimum field width */
int main() {
    int inumber;

    // Prompt user for the integer to convert
    printf("Enter a number: \n");
    scanf("%d", &inumber);

    int iwidth;

    // Prompt user for the minimum field width
    printf("Enter minimum field width: \n");
    scanf("%d", &iwidth);

    char sStr[WORDS]; // Array to store the converted string

    // Calling `my_Itoa()` function to convert the number to a string
    my_Itoa(inumber, sStr, iwidth);

    // Print the resulting string representation of the number
    printf("%s\n", sStr);

    return 0;
}
/* End main() */

/** 
 * my_Itoa: Converts an integer to a string representation with minimum field width
 * 
 * Parameters:
 * - `inum` (int): The integer value to convert
 * - `sStr` (char[]): The character array to store the resulting string
 * - `imin_width` (int): The minimum width of the output string, padded with blanks if necessary
 */
void my_Itoa(int inum, char sStr[], int imin_width) {
    int iIndex, sign;
    
    // To hold the original number in case it's negative
    if ((sign = inum) < 0)
        inum = -inum; // Make `inum` positive for conversion

    iIndex = 0;

    // Generate digits in reverse order
    do {
        sStr[iIndex++] = inum % 10 + '0'; // Get next digit
    } while ((inum /= 10) > 0); // Continue until all digits are processed

    // If the number was negative, add the negative sign
    if (sign < 0)
        sStr[iIndex++] = '-';

    // Null-terminate the string
    sStr[iIndex] = '\0';

    // Reverse the generated string to correct the order
    reverse(sStr);

    // Calculate the length of the converted string
    int ilen = strlen(sStr);

    // If the length of the string is less than the specified width, pad with spaces
    if (ilen < imin_width) {
        // Shift the characters to the right to make room for padding
        for (iIndex = ilen; iIndex >= 0; iIndex--) {
            sStr[iIndex + (imin_width - ilen)] = sStr[iIndex];
        }
    }

    // Add padding with blanks on the left
    for (iIndex = 0; iIndex < (imin_width - ilen); iIndex++) {
        sStr[iIndex] = ' ';
    }
}
/* End of my_Itoa */

/** 
 * reverse: Reverses a given string in place
 * 
 * Parameters:
 * - `sStr` (char[]): The character array to be reversed
 */
void reverse(char sStr[]) {
    int itemp, iIndex1, iIndex2;

    // Loop to reverse the string by swapping the characters
    for (iIndex1 = 0, iIndex2 = strlen(sStr) - 1; iIndex1 < iIndex2; iIndex1++, iIndex2--) {
        // Swap characters at the beginning and end
        itemp = sStr[iIndex1];
        sStr[iIndex1] = sStr[iIndex2];
        sStr[iIndex2] = itemp;
    }
}
/* End of reverse() */

/*
 * Explanation of Functions:
 *
 * - `my_Itoa(int inum, char sStr[], int imin_width)`:
 *   - Converts an integer `inum` to its string representation, padding with spaces
  *   length is less than this width, spaces will be added to the left.
 */

