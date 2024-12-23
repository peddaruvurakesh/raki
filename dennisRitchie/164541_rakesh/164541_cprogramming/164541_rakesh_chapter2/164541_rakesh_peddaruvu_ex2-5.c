/*
 * This program implements the function my_Find(s1, s2), which returns the first location in 
 * a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 * Author: Rakesh
 * Created: 3 July, 2024
 * Modified: 3 July, 2024
 *
 * Sample Input/Output:
 * 1. 
 *    Enter the string s1: Hello, World!
 *    Enter the string s2: o
 *    Duplicate character found at index 4 in string1
 *    Do you want to do it again? (y/n)
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>

/** MACRO DEFINITIONS **/
#define LIMIT 100  // Maximum length of input strings

/** FUNCTION PROTOTYPES **/
int my_Find(char s[], char a[]);

/** MAIN PROGRAM **/
/** main: accepts input strings and calls the find function */
int main() {
    char sStr[LIMIT];       // String s1 where we will search for characters
    char sSub_str[LIMIT];   // String s2 containing characters to search for
    char cCh;               // Variable to hold user's choice for repeating the process

    do {
        /** Enter string s1 **/
        printf("Enter the string s1: ");
        scanf("%[^\n]", sStr); // Read input string s1 including spaces
        getchar(); // To consume the newline character left in the buffer

        /** Enter string s2 **/
        printf("Enter the string s2: ");
        scanf("%[^\n]", sSub_str); // Read input string s2 including spaces
        getchar(); // To consume the newline character left in the buffer

        // Call my_Find to get the index of the first matching character
        int iIndex = my_Find(sStr, sSub_str);

        // Check if a character from s2 was found in s1
        if (iIndex != -1)
            printf("Duplicate character found at index %d in string1\n", iIndex);
        else
            printf("No character found in string1\n");

        // Ask the user if they want to repeat the process
        printf("Do you want to do it again? (y/n)\n");
        scanf(" %c", &cCh); // Read user's choice for repeating
        while (getchar() != '\n'); // Clear the buffer

    } while (cCh == 'y' || cCh == 'Y'); // Repeat if user inputs 'y' or 'Y'

    return 0; // End of the main function
}
/* End main() */

/** my_Find: to find the first occurrence of any character in s1 from s2 and return the index */
/* Author: Rakesh
 * Created: 3 July, 2024
 * Modified: 3 July, 2024
*/
int my_Find(char sStr[], char svar[]) {
    int istart_1, istart_2; // Loop variables for iterating through strings
    for (istart_1 = 0; sStr[istart_1] != '\0'; istart_1++) { // Iterate through s1
        for (istart_2 = 0; svar[istart_2] != '\0'; istart_2++) { // Iterate through s2
            if (sStr[istart_1] == svar[istart_2]) { // Check for matching characters
                /* If a character from s2 is found in s1, return the index */
                return istart_1; 
            }
        }
    }
    /* If no characters from s2 were found in s1, return -1 */
    return -1;
}
/** End of my_Find */

