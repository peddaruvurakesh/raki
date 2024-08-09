/*
 * This program is to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various 
 floating-point types.
 * Author: rakesh
 * Created: 3 July, 2024
 * Modified:3 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<limits.h>
#include"error_handling.h"
/** MAIN PROGRAM */
/** main: Accepts different datatypes and find thier ranges */
int main(){
	/* char ranges */
	printf("signed char\n");
	/* cast to unsigned char and then right shift by 1 */
	printf("%d to ",-(char)((unsigned char)~0>>1)-1);
	printf("%d\n",(char)((unsigned char)~0>>1));
	printf("unsigned char\n");
	printf("0 to %u\n",((unsigned char)~0));
	/* int */
	printf("signed int\n");
	printf("%d to ",-(int)((unsigned int)~0>>1)-1);
	printf("%d\n",(int)((unsigned int)~0>>1));
	printf("unsigned int\n");
	printf("0 to %u\n",(int)(unsigned int)~0);
	/*short*/
	printf(" signed short \n");
	printf("%d to ",-(short)((unsigned short )~0>>1)-1);
	printf("%d\n",(short)((unsigned short)~0>>1));
	printf("unsigned short\n");
	printf("0 to %d\n",(unsigned short)~0);

	/*long */
	printf("signed  long\n");
	printf("%ld to", LONG_MIN);
	printf(" %ld\n", LONG_MAX);
	printf("unsigned long\n");
	printf("0 to %lu\n", ULONG_MAX);
	/*long long*/
	printf("signed long long\n");
	printf("%lld to", LLONG_MIN);
	printf(" %lld\n", LLONG_MAX);
	printf("unsigned long long\n");
	printf("0 to %llu\n", ULLONG_MAX);

	return 0; 
}
/* End main() */
