/*
* This program is to find a bitcount, In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
* Author: rakesh
* Created: 4 July, 2024
* Modified:4 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
int bitcount(unsigned);
/** MAIN PROGRAM */
/** main: calls bitcount function */
int main(){
int x;
scanf(" %d",&x);
int bits=bitcount(x);
printf("%d\n",bits);
}

/* End main() */
int bitcount(unsigned x)
 {
 int b;
 for (b = 0; x != 0; x&=(x-1))
 b++;
 return b;
 }
