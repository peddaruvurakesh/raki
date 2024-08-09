/*
 * This program is to write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.  
 * Author: rakesh
 * Created: 3 July, 2024
 * Modified:4 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
unsigned int setbits(int , int , int, int );
void binary(int);
/** MAIN PROGRAM */
/** main: call setbits function */
int main(){

        printf("enter x value\n");
 int x;
	scanf(" %u",&x);

        printf("enter y value\n");
	  int y;
	scanf(" %u",&y);
        if(x<0||y<0){
		printf("Enter positive value\n");
			return 0;
	}
	int p;
	int n;
	printf("enter position p\n");
	scanf(" %d",&p);
	printf("enter no.of bits n\n");
	scanf(" %d",&n);
	if(n>p+1){
		printf("insufficient bits\n");
		return 0;
	}
	/* setbits function call */
	unsigned int resul=setbits( x, p, n,y);
	printf("x=%d\n",resul);

}
/*End of main*/
unsigned int setbits( int x, int p, int n, int y)
{
	/* position p starts from 0 */
 --p; 
  /* 1111 0011 */
  unsigned int mask1 = (~(~(~0 << n) << p) & x);
  unsigned int mask2 = (~(~0 << n) & y) << p;

  return mask1 | mask2;
}
/* To print bits in binary*/
void binary(int resul){
	int pos;
	for(pos=31;pos>=0;pos--)
		printf("%d",resul>>pos&1);
	printf("\n");
}
/** End of binary*/

