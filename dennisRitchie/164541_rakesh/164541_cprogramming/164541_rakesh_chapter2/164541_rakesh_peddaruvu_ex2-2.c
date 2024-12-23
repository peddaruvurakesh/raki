/*
 * This program writes a loop equivalent to the following for loop 
 * without using && or ||:
 * 
 * for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * 
 * Author   : Rakesh
 * Created  : 3 July, 2024
 * Modified : 3 July, 2024
 * 
 * Sample Output:
 * enter input:
 * Hello
 * output: Hello
 * do you want to give input another time ? (y/n)
 * y
 * enter input:
 * World
 * output: World
 * do you want to give input another time ? (y/n)
 * n
 */

#include <stdio.h>

/** MACRO DEFINITIONS */
#define LIMIT 10
#define RANGE 100

/** MAIN PROGRAM */
/** main: Writes an equivalent loop for the for loop above */
int main() {
    int iminimum;
    char sname[RANGE], cCharacter;
    
    do {
        /* Asking user to enter input */
        printf("Enter input:\n");
        
        /* Initialize iminimum to 0 */
        iminimum = 0;  
        
        /* Loop until we reach the limit or encounter a newline or EOF */
        while (iminimum < LIMIT - 1) {
            cCharacter = getchar(); // Read a character from input
            
            /* Check for newline or EOF */
            if (cCharacter == '\n') {
                break; // Exit the loop if a newline is encountered
            }
            if (cCharacter == EOF) {
                break; // Exit the loop if EOF is encountered
            }

            /* Store the character in the array */
            sname[iminimum] = cCharacter;
            iminimum++; // Increment the counter
        }
        
        /* Null terminate the string */
        sname[iminimum] = '\0';

        /* Print the obtained characters */
        printf("Output: %s\n", sname);

        /* To repeat another time */
        printf("Do you want to give input another time? (y/n)\n");
        scanf(" %c", &cCharacter);
        
        /* To clear buffer */
        while (getchar() != '\n'); // Clear the input buffer
    } while (cCharacter == 'y' || cCharacter == 'Y');

    return 0;
}
/* End main() */

