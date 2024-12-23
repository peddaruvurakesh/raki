/*
 * This program defines the function `my_Itob(n, s, b)` that converts the integer `n` 
 * into a character representation in base `b` and stores the result in the string `s`. 
 * For example, `my_Itob(n, s, 16)` formats `s` as a hexadecimal representation of `n`.
 * 
 * Sample Input:
 * Enter number: 
 * 255
 * Enter base: 
 * 16
 * 
 * Sample Output:
 * FF
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 8 July, 2024
 * Modified : 8 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>   // For input/output functions
#include <string.h>  // For string handling functions

/** MACRO DEFINITIONS */
#define WORDS 100  // Maximum length of the result string

/** FUNCTION PROTOTYPES */
void my_Itob(int n, char s[], int b);
void reverse(char s[]);

/** MAIN PROGRAM */
/** main: Accepts an integer and a base, converts the integer into the representation in the specified base */
int main() {
    int inum, ibase;

    // Prompt user for the integer to convert
    printf("Enter number: \n");
    scanf("%d", &inum);

    // Prompt user for the base
    printf("Enter base: \n");
    scanf("%d", &ibase);

    // Validate the base value
    if (ibase <= 0) {
        printf("Enter a valid base value (greater than 0)\n");
        return 1;
    }

    char sStr[WORDS];  // Array to store the converted string

    // Calling `my_Itob()` function to convert the number to the specified base
    my_Itob(inum, sStr, ibase);

    // Print the resulting string representation of the number
    printf("%s\n", sStr);

    return 0;
}
/* End main() */

/** 
 * my_Itob: Converts an integer to a string representation in the specified base
 * 
 * Parameters:
 * - `inumber` (int): The integer value to convert
 * - `sStr` (char[]): The character array to store the resulting base representation
 * - `ibase` (int): The base for the conversion (e.g., 2 for binary, 16 for hexadecimal)
 */
void my_Itob(int inumber, char sStr[], int ibase) {
    int iIndex = 0;  // Index for filling in the result string
    unsigned int num;  // Using unsigned to handle negative numbers correctly

    // Handle negative numbers by converting to unsigned
    num = inumber;

    // Generate the digits in reverse order
    do {
        int iremainder = num % ibase;

        // If the remainder is less than 10, convert it to a digit ('0' to '9')
        // Otherwise, convert it to an alphabetic character ('A' to 'Z') for bases greater than 10
        sStr[iIndex++] = (iremainder < 10) ? (iremainder + '0') : (iremainder - 10 + 'A');

        // Update the number by dividing it by the base
        num /= ibase;
    } while (num > 0);  // Continue until all digits are processed

    // Null-terminate the resulting string
    sStr[iIndex] = '\0';

    // Reverse the result string to get the correct order
    reverse(sStr);
}
/* End of my_Itob */

/** 
 * reverse: Reverses a given string in place
 * 
 * Parameters:
 * - `sStr` (char[]): The character array to be reversed
 */
void reverse(char sStr[]) {
    int itemp, istart1, istart2;

    // Loop to reverse the string by swapping the characters
    for (istart1 = 0, istart2 = strlen(sStr) - 1; istart1 < istart2; istart1++, istart2--) {
        // Swap characters at the beginning and end
        itemp = sStr[istart1];
        sStr[istart1] = sStr[istart2];
        sStr[istart2] = itemp;
    }
}
/* End of reverse() */

/*
 * Explanation of Functions:
 *
 * - `my_Itob(int inumber, char sStr[], int ibase)`:
*   - Converts an integer `inumber` to its representation in base `ibase`.*/
