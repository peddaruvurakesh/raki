/*
* This program is to  adapt the ideas of printd to write a recursive version of itoa; that is, convert 
an integer into a string by calling a recursive routine. 
* Author: rakesh
* Created: 9 July, 2024
* Modified:10 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
  #include<string.h>
/** MACRO DEFINITIONS */

/** FUNCTION PROTOTYPES */
 void rev_str(char *,int,int);
 void printd(int);
/** MAIN PROGRAM */
/** main: Content of main write here */

   int main()
   {
           int num;
	   scanf("%d",&num);
           printd(num);
 
          //rev_str(s,0,strlen(s)-1);
          //printf("s = %s\n",s);
  }
/* End main() */
/* printd: print n in decimal */ 
 void printd(int n) 
 { 
 if (n < 0) { 
 putchar('-'); 
 n = -n; 
 } 
 if (n / 10) {
	 //recursive function
 printd(n / 10);
 } 
 putchar(n % 10 + '0'); 
 } 
 
  void rev_str(char *p,int i,int j)
  {
          char temp;
          if(i<j)
          {
                  temp = p[i];
                  p[i] = p[j];
                  p[j] = temp;
                  i++, j--;
                  rev_str(p,i,j);
          }
  }

