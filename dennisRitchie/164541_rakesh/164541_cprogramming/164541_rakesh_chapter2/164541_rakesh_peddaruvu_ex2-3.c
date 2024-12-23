/*
 * This program converts a string of hexadecimal digits (including an optional 0x or 0X) into
 * its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
 * 
 * Author   : Rakesh
 * Created  : 3 July, 2024
 * Modified : 3 July, 2024
 * 
 * Sample Input and Output:
 * Enter input:
 * 0x1A3
 * output = 419
 * 
 * Enter input:
 * 1F
 * output = 31
 * 
 * Enter input:
 * ABC
 * output = 2748
 * 
 * Enter input:
 * 0xinvalid
 * Enter valid hex number
 * 
 * Do you want to give input again?(y/n)
 * y
 * Enter input:
 * 0x1Z
 * Enter valid hex number
 */

#include <stdio.h>

/** MACRO DEFINITIONS **/
#define RANGE 100

/** FUNCTION PROTOTYPES **/
int my_Converthtoi(const char p[]);

/** MAIN PROGRAM */
/** main: Handles user input and output for hexadecimal conversion */
int main()
{
    int iOutput; // Variable to store the output integer value
    char sStr[RANGE], cCh; // Array to store user input and character for repeat prompt

    /* Loop to allow user to input multiple hexadecimal numbers */
    do {
        printf("Enter input \n");
        scanf(" %[^\n]s", sStr); // Read a string input including spaces until newline

        /* FUNCTION CALL */
        iOutput = my_Converthtoi(sStr); // Convert hexadecimal string to integer

        /* Check for valid conversion */
        if (iOutput == -1) {
            printf("Enter valid hex number\n"); // Invalid hexadecimal input
        } else {
            printf("Output = %d\n", iOutput); // Valid conversion output
        }

        printf("Do you want to give input again?(y/n)\n");
        scanf(" %c", &cCh); // Read the character for continuing or stopping
    } while (cCh == 'y' || cCh == 'Y'); // Continue if user inputs 'y' or 'Y'

    return 0; // Return success
}
/* End main() */

/* Converts hexadecimal string to integer */
/* Author   : Rakesh
 * Created  : 3 July, 2024
 * Modified : 3 July, 2024
 * 
 * my_Converthtoi: Converts a hexadecimal string to an integer
 * 
 * Parameters:
 *   const char cVar[] : Input hexadecimal string that may start with "0x" or "0X".
 * 
 * Returns:
 *   The integer value corresponding to the hexadecimal input if valid, 
 *   otherwise returns -1 if the input is invalid.
 */
int my_Converthtoi(const char cVar[])
{
    int istart = 0, isum = 0; // istart to track where to begin parsing, isum to accumulate the result

    /* Check for the optional '0x' or '0X' prefix */
    if ((cVar[0] == '0') && ((cVar[1] == 'x') || (cVar[1] == 'X'))) {
        istart = 2; // Move past the prefix
    }

    /* The allowable digits are 0 through 9, a through f, and A through F. */
    for (; cVar[istart]; istart++) { // Loop until the end of the string
        int ivalue; // Variable to hold the numeric value of the current character

        /* Convert the character to its integer value */
        if (cVar[istart] >= '0' && cVar[istart] <= '9') {
            ivalue = cVar[istart] - '0'; // '0'-'9'
        } else if (cVar[istart] >= 'a' && cVar[istart] <= 'f') {
            ivalue = cVar[istart] - 'a' + 10; // 'a'-'f' -> 10-15
        } else if (cVar[istart] >= 'A' && cVar[istart] <= 'F') {
            ivalue = cVar[istart] - 'A' + 10; // 'A'-'F' -> 10-15
        } else {
            return -1; // Invalid character found
        }

        /* Accumulate the converted value */
        isum = isum * 16 + ivalue; // Shift left by one hex digit and add new value
    }

    return isum; // Return the accumulated integer value
}
/* End of my_Converthtoi */

