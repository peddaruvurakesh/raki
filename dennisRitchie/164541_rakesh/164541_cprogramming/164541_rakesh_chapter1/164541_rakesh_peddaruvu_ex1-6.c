/* 
 * This program is to verify that the expression getchar() != EOF evaluates to 0 or 1.
 * 
 * Name         : Rakesh
 * Created Date : 24-06-2024
 * Modified Date: 24-06-2024
 */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MAIN PROGRAM */
/*
 * main: Reads a character input from the user and verifies whether the 
 * expression getchar() != EOF returns 0 or 1.
 */
int main() {
    // Prompt user for input
    printf("Enter a character and press Enter (CTRL+D for EOF):\n");

    // Print the value of the expression getchar() != EOF (which will be either 0 or 1)
    printf("The value of the expression getchar() != EOF is: %d\n", getchar() != EOF);

    return 0; // Return 0 to indicate successful completion
}
/* End of main() */

