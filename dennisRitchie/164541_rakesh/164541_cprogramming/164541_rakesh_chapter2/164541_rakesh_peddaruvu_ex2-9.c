/*
 * This program is to find the bit count of a given integer using the property 
 * that in a two's complement number system, the operation x &= (x-1) deletes 
 * the rightmost 1-bit in x.
 * Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 *
 * Sample Input/Output:
 * 1.
 *   Input: 29
 *   Output: 4
 *
 * 2.
 *   Input: 15
 *   Output: 4
 *
 * 3.
 *   Input: 0
 *   Output: 0
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>

/** FUNCTION PROTOTYPES **/
int my_Bitcount(unsigned);

/** MAIN PROGRAM **/
/** main: calls bitcount function */
int main() {
    int ix; // Variable to store the input number
    printf("Enter a number: ");
    scanf(" %d", &ix); // Input for the number
    
    /* Function call to count the bits */
    int i_bits = my_Bitcount(ix);
    printf("Number of 1 bits: %d\n", i_bits); // Print the count of bits
    return 0; // Return 0 indicating successful execution
}
/* End main() */

/** my_Bitcount(): To count the number of 1 bits in an unsigned integer */
/* Author: Rakesh
 * Created: 4 July, 2024
 * Modified: 4 July, 2024
 */
int my_Bitcount(unsigned ix) {
    int ib; // Variable to count the bits
    /* Loop to count bits: x &= (x - 1) is used */
    for (ib = 0; ix != 0; ix &= (ix - 1)) {
        ib++; // Increment count for each 1-bit found
    }
    return ib; // Return the count of 1 bits
}
/* End of my_Bitcount() */

