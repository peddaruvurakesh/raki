/*
* This program is  a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs. 
* Author: rakesh
* Created: 8 July, 2024
* Modified:16 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
#include<limits.h>
/** MACRO DEFINITIONS */
#define WORDS 100

/** FUNCTION PROTOTYPES */
void my_itoa(int n, char s[]);
void reverse(char s[]);

/** MAIN PROGRAM */
/** main:  converts integer to string by calling itoa */
int main(){
long int n;
scanf("%ld",&n);
char s[WORDS];
if(n > INT_MAX || n < INT_MIN){
	 printf("Entered number not in range\n");
	 return 0;
 }
my_itoa(n,s);
 reverse(s);
printf("string = %s\n",s);
}
/* End main() */
void my_itoa(int n, char s[])
 {
 int i, sign;
 if((sign=n)==INT_MIN)
 {
	 n=-(n+1);
 }
 else if((sign = n) < 0) {
 n = -n; /* make n positive */
 i = 0;
 }
/*do while to take integer as input converts into string */
 do { 
/* generate digits in reverse order */
 s[i++] = n % 10 + '0'; /* get next digit */
 } while ((n /= 10) > 0);
 if(sign==INT_MIN)
	 s[0]+=1;
 /* delete it */
 if (sign < 0)
 s[i++] = '-';
 s[i] = '\0';
 
 }
/*reverse():To reverse the string*/
void reverse(char s[])
 {
 int c, i, j;
 for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
 c = s[i];
 s[i] = s[j];
 s[j] = c;
 }
 }
/*End of reverse()*/
