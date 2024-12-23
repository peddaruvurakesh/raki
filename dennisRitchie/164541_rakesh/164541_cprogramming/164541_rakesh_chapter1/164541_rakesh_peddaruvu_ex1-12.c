/*
 * This program prints its input one word per line.
 * 
 * Name         : Rakesh
 * Created Date : 24-06-2024
 * Modified Date: 24-06-2024
 */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define VALUE 10 // Not used in this program; can be removed or utilized if needed
#define LENGTH 500 // Maximum length of the input string

/* MAIN PROGRAM */
/*
 * main: Reads input from the user and prints one word per line.
 */
int main() {
    int ichars; // Variable to hold character input
    int iIndex = 0; // Index variable for input array
    char sStr[LENGTH]; // Array to store user input

    // Prompt the user for input
    printf("Enter characters (press CTRL+D to end input):\n");

    /* Get characters from user until EOF */
    while ((ichars = getchar()) != EOF) {
        sStr[iIndex++] = ichars; // Store each character in the array
    }
    sStr[iIndex] = '\0'; // Null-terminate the string

    int inum; // Variable for iterating through the input string
    int ispace_detected = 0; // Flag to detect sequences of spaces or tabs

    /* Loop through the input string and print each word on a new line */
    for (inum = 0; sStr[inum] != '\0'; inum++) {
        // Check for spaces or tabs
        if (sStr[inum] == ' ' || sStr[inum] == '\t') {
            if (!ispace_detected) {
                // If space/tab is detected for the first time in a sequence, print newline
                putchar('\n');
                ispace_detected = 1; // Set flag when a space or tab is detected
            }
        } else {
            // Print the character if it's not a space or tab
            putchar(sStr[inum]);
            ispace_detected = 0; // Reset flag when a non-space character is detected
        }
    }

    return 0; // Return 0 to indicate successful program execution
}
/* End of main() */

