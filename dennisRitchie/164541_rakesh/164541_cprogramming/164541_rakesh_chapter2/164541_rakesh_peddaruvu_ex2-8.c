/*
 * This program implements a function `rightrot(x, n)` that returns the value of the integer x 
 * rotated to the right by n positions.
 * Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 *
 * Sample Input/Output:
 * 1.
 *   Enter a number: 29
 *   Enter n value: 2
 *   Result after right rotation: 7
 *
 * 2.
 *   Enter a number: -5
 *   Error: Number must be non-negative
 *
 * 3.
 *   Enter a number: 15
 *   Enter n value: 3
 *   Result after right rotation: 7
 */

 /** REQUIRED HEADER FILES **/
#include <stdio.h>

/** FUNCTION PROTOTYPES **/
unsigned int right_Rotation(int, int);
void my_Binary(int);

/** MAIN PROGRAM **/
/** main: Accepts integer and positions, calls rightrot function */
int main() {
    char cCh; // Variable for user choice to repeat the program
    do {
        int ix; // Variable for the input number
        printf("Enter a number: ");
        
        // Input validation for non-negative integer
        if ((scanf(" %d", &ix) != 1) || (ix < 0)) {
            printf("Error: Number must be non-negative\n");
            return 0; // Exit if invalid input
        }

        int inum; // Variable for the number of positions to rotate
        printf("Enter n value: ");
        scanf(" %d", &inum); // Input for rotation positions
        
        /* right_rotation function call returning unsigned int value */
        unsigned int iresul = right_Rotation(ix, inum);
        printf("Result after right rotation: %d\n", iresul); // Print result
        
        printf("Do you want to repeat again (y/n)? ");
        scanf(" %c", &cCh); // Ask user if they want to repeat
    } while (cCh == 'y' || cCh == 'Y');

    return 0; // End of the main function
}
/** End of main() */

/** rightrot(): returns the value of the integer x rotated to the right by n positions */
unsigned int right_Rotation(int ix, int inum) {
    unsigned int ibits = sizeof(ix) * 8; // Get the number of bits in an integer
    unsigned int iright_shift = ix >> inum; // Shift the number to the right by n positions
    int iy = ix << (ibits - 1 - inum); // Shift the original number to the left
    
    /* Clear the leftmost bit */
    iy = iy & ~(1 << (ibits - 1));
    
    unsigned int ires = iright_shift | iy; // Combine the shifted values
    return ires; // Return the result
}
/** End of right_Rotation() */

/* my_Binary(): To print bits in binary */
void my_Binary(int iresul) {
    int ipos;
    for (ipos = 31; ipos >= 0; ipos--)
        printf("%d", iresul >> ipos & 1); // Print each bit
    printf("\n");
}
/** End of my_Binary() */

