/*
 * This program rewrites the function my_Lower, which converts uppercase letters 
 * to lowercase using a conditional expression instead of if-else.
 * Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 *
 * Sample Input/Output:
 * 1.
 *   Input: HELLO
 *   Output: hello
 *
 * 2.
 *   Input: World123!
 *   Output: world123!
 *
 * 3.
 *   Input: A B C D
 *   Output: a b c d
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>

/** FUNCTION PROTOTYPES **/
char my_Lower(char s);

/** MAIN PROGRAM **/
/** main: Accepts input and converts it to lowercase using conditional operator */
int main() {
    char cCharacter; // Variable to store input character
    printf("Enter characters (Press Ctrl+D to end input):\n"); // Prompt for user input
    while ((cCharacter = getchar()) != EOF && cCharacter != '\n') {
        /* Calling function my_Lower() to convert to lowercase */
        char c_upper = my_Lower(cCharacter);
        /* Printing the lowercase character */
        printf("%c", c_upper);
    }
    printf("\n");
    return 0; // Return 0 indicating successful execution
}
/* End main() */

/** my_Lower: Converts uppercase letters to lowercase using conditional expression */
/* Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 */
char my_Lower(char cChar) {
    // Conditional expression to convert uppercase to lowercase
    return ((cChar >= 'A' && cChar <= 'Z') ? (cChar ^ 32) : cChar);
}
/* End my_Lower() */

