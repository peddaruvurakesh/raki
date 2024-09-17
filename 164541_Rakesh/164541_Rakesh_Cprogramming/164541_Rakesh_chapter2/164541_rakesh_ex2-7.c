/*
 * This program is to write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 
 * changed into 0 and vice versa), leaving the others unchanged.  
 * Author: rakesh
 * Created: 4 July, 2024
 * Modified:4 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>



/** FUNCTION PROTOTYPES */
unsigned int invert(unsigned,int,int);
void binary(int);

/** MAIN PROGRAM */
/** main: Accepts */
int main(){
	int position,bits;
	int pos;
	int x; 
	printf("enter x value\n");
	scanf(" %d",&x);
	printf("enter  position\n");
	scanf(" %d",&position);
	printf("enter number of bits\n");
	scanf(" %d",&bits);
	
	unsigned int resul=invert(x,position,bits);
	printf("%d\n",resul);
}
/** End of main() */
/** invert():returns x with the n bits that begin at position p inverted*/
unsigned int invert(unsigned x,int p,int n){

	 unsigned int mask = ((1 << n) - 1) << (p + 1 - n);
    return x ^ mask;

}
/**End of invert()*/
//To print bits in binary
void binary(int resul){
	int pos;
	for(pos=31;pos>=0;pos--)
		printf("%d",resul>>pos&1);
	printf("\n");
}
/** End of binary()*/
