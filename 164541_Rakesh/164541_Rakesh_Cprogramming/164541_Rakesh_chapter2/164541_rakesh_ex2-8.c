/*
 * This program is to write a function rightrot(x,n) that returns the value of the integer x rotated  to the right by n positions.
 * Author: rakesh
 * Created: 4 July, 2024
 * Modified:4 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<ctype.h>
//#include"error_handling.h"

/** FUNCTION PROTOTYPES */
unsigned int right_rotation( int , int  );
void binary(int);
/** MAIN PROGRAM */
/** main: Accepts integer and positions calls rightrot function */
int main()
{
	char ch;
	do{
	 int x;
	printf("enter a number ");
	  if (scanf(" %d", &x) != 1) {
  //      handle_error(ERROR_INVALID_INPUT);
        return 0;
    }
	binary(x);
	int n;
	
	printf("enter n value ");
	scanf(" %d",&n);
	unsigned int resul=right_rotation( x, n);
	printf("%d\n",resul);
	binary(resul);
	printf("do you want to repeat again(y/n)\n");
	scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');


}
/*rightrot():  returns the value of the integer x rotated  to the right by n positions.*/
unsigned int right_rotation( int x,  int n)
{
	
	 unsigned int bits = sizeof(x)*8;
    unsigned int right_shift = x >> n;
    int y=x<<bits-1-n;
    //clear a bit
    y=y&~(1<<bits-1);
    unsigned int res = right_shift | y;
    return res;
}
/*binary(): To print bits in binary*/
void binary(int resul){
	int pos;
	for(pos=31;pos>=0;pos--)
		printf("%d",resul>>pos&1);
	printf("\n");
}
/*End of binary()*/
