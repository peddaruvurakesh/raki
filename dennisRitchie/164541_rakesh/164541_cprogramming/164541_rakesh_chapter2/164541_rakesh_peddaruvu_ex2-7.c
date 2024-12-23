/*
 * This program implements a function `invert(x, p, n)` that returns x with the n bits that begin 
 * at position p inverted (i.e., 1 changed to 0 and vice versa), leaving the others unchanged.
 * Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 *
 * Sample Input/Output:
 * 1.
 *   
 * 
Enter x value: 29
//00000000000000000000000000011101
//Enter position: 1
//Enter number of bits: 3
//Insufficient bits
 *
 * 2.
 *   Enter x value: -5
 *   Enter positive value
 *
 * 3.
 *   Enter x value: 15
 *   00000000000000000000000000001111
 *   Enter position: 3
 *   Enter number of bits: 5
 *   Insufficient bits
 */

 /** REQUIRED HEADER FILES **/
#include <stdio.h>

/** FUNCTION PROTOTYPES **/
unsigned int invert(unsigned, int, int);
void my_Binary(int);

/** MAIN PROGRAM **/
/** main: Accepts input and inverts the bits */
int main() {
    int iposition, ibits; // Variables for position and number of bits
    int ix;              // Variable for x value

    /* Entering x value */
    printf("Enter x value: ");
    scanf(" %d", &ix);
    my_Binary(ix); // Print binary representation of x

    /* Entering position value */
    printf("Enter position: ");
    scanf(" %d", &iposition);

    /* Entering bits */
    printf("Enter number of bits: ");
    scanf(" %d", &ibits);

    // Check for negative x value
    if (ix < 0) {
        printf("Enter positive value\n");
        return 1; // Exit if x is negative
    }

    // Check for insufficient bits
    if (ibits > iposition + 1) {
        printf("Insufficient bits\n");
        return 1; // Exit if insufficient bits to invert
    }

    /* Function call */
    unsigned int iresul = invert(ix, iposition, ibits);
    my_Binary(iresul); // Print binary representation of the result
    printf("%d\n", iresul); // Print the result after inversion

    return 0; // End of the main function
}
/** End of main() */

/** invert(): returns x with the n bits that begin at position p inverted */
unsigned int invert(unsigned ix, int ip, int in) {
    unsigned int imask = ((1 << in) - 1) << (ip + 1 - in); // Create a mask for n bits at position p
    return ix ^ imask; // Invert the bits using XOR
}
/** End of invert() */

/* To print bits in binary */
void my_Binary(int iresul) {
    int ipos;
    for (ipos = 31; ipos >= 0; ipos--)
        printf("%d", iresul >> ipos & 1); // Print each bit
    printf("\n");
}
/** End of my_Binary() */

