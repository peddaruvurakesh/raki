/*
 * Program: Write a function `setbits(x, p, n, y)` that returns `x` with the `n` bits that begin at position `p`
 * set to the rightmost `n` bits of `y`, leaving the other bits unchanged.
 *
 * Author: Rakesh
 * Created: 3 July, 2024
 * Modified: 4 July, 2024
 *
 * SAMPLE INPUT/OUTPUT:
 *
 * Input:
 *   Enter x value: 255
 *   Enter y value: 240
 *   Enter position p: 3
 *   Enter number of bits n: 2
 * Output:
 *   x = 243
 *   (Binary representation of original x: 11111111, result: 11011111)
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
/*
 * Set n bits of x starting at position p to the rightmost n bits of y.
 * Parameters:
 *   x - The integer whose bits will be modified.
 *   p - The position from which to begin replacing bits (starting from 0).
 *   n - The number of bits to replace.
 *   y - The integer from which the rightmost n bits will be taken.
 * Returns the modified value of x.
 */
unsigned int setbits(int x, int p, int n, int y);

/*
 * Print the binary representation of an integer.
 * Parameters:
 *   iresul - The integer to be printed in binary.
 */
void my_Binary(int iresul);

/** MAIN PROGRAM */
/* main: calls setbits function */
int main()
{
    /* Entering x unsigned value */
    printf("Enter x value: ");
    int ix;
    scanf("%u", &ix);

    /* Entering y unsigned value */
    printf("Enter y value: ");
    int iy;
    scanf("%u", &iy);

    /* If it is less than 0 */
    if (ix < 0 || iy < 0)
    {
        printf("Enter positive value\n");
        return 1;
    }

    int ip;
    int in;

    /* Entering position */
    printf("Enter position p: ");
    scanf("%d", &ip);
    printf("Enter number of bits n: ");
    scanf("%d", &in);

    if (in > ip + 1)
    {
        printf("Insufficient bits\n");
        return 0;
    }

    /* setbits function call */
    unsigned int iresul = setbits(ix, ip, in, iy);
    printf("Modified x = %d\n", iresul);

    /* Optionally print the binary representation of result */
    printf("Binary representation of modified x: ");
    my_Binary(iresul);

    return 0;
}
/* End of main */

/* setbits(): To set bits */
/* Author: Rakesh
 * Created: 3 July, 2024
 * Modified: 4 July, 2024
 */
/*
 * Set n bits of x starting at position p to the rightmost n bits of y.
 *
 * Parameters:
 *   ix - The integer whose bits will be modified.
 *   ip - The position from which to begin replacing bits (starting from 0).
 *   in - The number of bits to replace.
 *   iy - The integer from which the rightmost n bits will be taken.
 * Returns the modified value of ix.
 */
unsigned int setbits(int ix, int ip, int in, int iy)
{
    /* Position p starts from 0 */
    --ip;

    /* Mask to clear the n bits from position p in x */
    unsigned int imask1 = (~(~(~0 << in) << ip) & ix);

    /* Mask to extract the rightmost n bits of y and shift to position p */
    unsigned int imask2 = (~(~0 << in) & iy) << ip;

    return imask1 | imask2;
}
/* End of setbits */

/* my_Binary: To print bits in binary */
/* Author: Rakesh
 * Created: 3 July, 2024
 * Modified: 4 July, 2024
 */
/*
 * Print the binary representation of an integer.
 *
 * Parameters:
 *   iresul - The integer to be printed in binary.
 */
void my_Binary(int iresul)
{
    int ipos;
    for (ipos = 31; ipos >= 0; ipos--)
        printf("%d", (iresul >> ipos) & 1);
    printf("\n");
}
/* End of my_Binary */

