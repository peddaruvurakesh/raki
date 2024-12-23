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

/** FUNCTION PROTOTYPES */
 void rev_Str(char *,int,int);
 void printd(int);
/** MAIN PROGRAM */
/** main:converts integer into string */

   int main()
   {
           int inum;
	   scanf("%d",&inum);
	   /* calling printd function to convert integer into string */
           printd(inum);
 
          //rev_Str(s,0,strlen(s)-1);
          //printf("s = %s\n",s);
  }
/* End main() */
/* printd: print n in decimal */ 
/* Author: rakesh
* Created: 9 July, 2024
* Modified:10 July, 2024
*/
 void printd(int inum) 
 { 
 if (inum < 0) { 
 putchar('-'); 
 inum = -inum; 
 } 
 if (inum / 10) {
	 /*recursive function */
 printd(inum / 10);
 } 
 putchar(inum % 10 + '0'); 
 } 
 /* rev_str(): to reverse string */
/* Author: rakesh
* Created: 9 July, 2024
* Modified:10 July, 2024
*/
  void rev_Str(char *ptr,int inum1,int inum2)
  {
          char ctemp;
          if(inum1<inum2)
          {
		  /* To swap two variables using temporary variable */
                  ctemp = ptr[inum1];
                  ptr[inum1] = ptr[inum2];
                  ptr[inum2] = ctemp;
                  inum1++, inum2--;
                  rev_Str(ptr,inum1,inum2);
          }
  }
/* End of rev_str() */
