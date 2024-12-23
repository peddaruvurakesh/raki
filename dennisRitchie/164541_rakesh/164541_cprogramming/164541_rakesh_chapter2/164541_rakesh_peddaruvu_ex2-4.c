/*
 * This program implements an alternative version of the function squeeze(s1,s2) 
 * that deletes each character in string s1 that matches any character in the string s2.
 * 
 * Author   : Rakesh
 * Created  : 3 July, 2024
 * Modified : 3 July, 2024
 * 
 * Sample Input and Output:
 * Enter the string s1:
 * Hello, World!
 * Enter the string s2:
 * l
 * Resulting string: Heo, Word!
 * 
 * Enter the string s1:
 * Programming
 * Enter the string s2:
 * p
 * Resulting string: rogramming
 * 
 * Do you want to repeat again?(y/n)
 * y
 * Enter the string s1:
 * Example
 * Enter the string s2:
 * e
 * Resulting string: xampl
 */

#include <stdio.h>
#include <ctype.h> // For tolower function

/** MACRO DEFINITIONS **/
#define LIMIT 100 // Define maximum string length

/** FUNCTION PROTOTYPES **/
void my_Squeeze(char s[], char a[]); // Function prototype for my_Squeeze

/** MAIN PROGRAM */
/** main: Handles user input and output for squeezing characters */
int main() {
    char sStr[LIMIT]; // String to be modified (s1)
    char sSub_str[LIMIT]; // String containing characters to delete (s2)
    char cCh; // Character to decide if the user wants to repeat

    do {
        // Prompt user to enter the first string (s1)
        printf("Enter the string s1:\n");
        scanf("%[^\n]", sStr); // Read input until newline
        
        // Clear the input buffer
        while (getchar() != '\n');

        // Prompt user to enter the second string (s2)
        printf("Enter the string s2:\n");
        scanf(" %[^\n]", sSub_str); // Read input until newline

        // Call the my_Squeeze function to remove characters
        my_Squeeze(sStr, sSub_str);
        
        // Output the resulting string after squeezing
        printf("Resulting string: %s\n", sStr);
        
        // Ask user if they want to repeat the process
        printf("Do you want to repeat again?(y/n)\n");
        scanf(" %c", &cCh); // Read the character for continuing or stopping
        
        // Clear the input buffer again
        while (getchar() != '\n');
    } while (cCh == 'y' || cCh == 'Y'); // Continue if user inputs 'y' or 'Y'

    return 0; // Return success
}
/* End main() */

/* my_Squeeze: Deletes characters from s1 that match any character in s2 */
/* Author   : Rakesh
 * Created  : 3 July, 2024
 * Modified : 3 July, 2024
 * 
 * Parameters:
 *   char sStr[] : The input string from which characters will be removed.
 *   char sSub_str[] : The string containing characters that need to be removed from sStr.
 * 
 * This function modifies sStr in place, removing all occurrences of characters found in sSub_str,
 * regardless of case (i.e., 'A' and 'a' are treated the same).
 */
void my_Squeeze(char sStr[], char sSub_str[]) {
    int istart_1, istart_2, ivar = 0, ifound; // Index variables and a found flag

    // Iterate through each character of the first string (s1)
    for (istart_1 = 0; sStr[istart_1] != '\0'; istart_1++) {
        ifound = 0; // Reset found flag for each character in s1
        
        // Check if the current character in s1 exists in s2
        for (istart_2 = 0; sSub_str[istart_2] != '\0'; istart_2++) {
            // Use tolower to make the comparison case-insensitive
            if (tolower(sStr[istart_1]) == tolower(sSub_str[istart_2])) {
                ifound = 1; // Mark as found
                break; // Exit inner loop if match is found
            }
        }

        // If the character from s1 was not found in s2, keep it in the result
        if (ifound == 0) {
            sStr[ivar++] = sStr[istart_1]; // Store the character and increment index
        }
    }
    
    // Null-terminate the modified string
    sStr[ivar] = '\0';
}
/** End of my_Squeeze() */

