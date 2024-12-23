/*
* This program is to write a recursive version of the function reverse(s), which reverses the 
string s in place.
* Author: rakesh
* Created: 9 July, 2024
* Modified:10 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
  #include<string.h>
/** MACRO DEFINITIONS */
#define WORDS 100
/** FUNCTION PROTOTYPES */
 void rev_Str(char *,int,int);
/** MAIN PROGRAM */
/** main: Content of main write here */

   int main()
   {
           char sStr[WORDS];
           printf("Enter the string\n");
           scanf("%[^\n]",sStr);
          /* rev_str function call */
          rev_Str(sStr,0,strlen(sStr)-1);
          printf("s = %s\n",sStr);
  }
/* End main() */
/** rev_str: To reverse the string using recursion*/
/* Author: rakesh
* Created: 9 July, 2024
* Modified:10 July, 2024
*/
  void rev_Str(char *pPtr,int inum1,int inum2)
  {
          char ctemp;
          if(inum1<inum2)
          {
		  /* To swap two variables using temporary variable */
                  ctemp = pPtr[inum1];
                  pPtr[inum1] = pPtr[inum2];
                  pPtr[inum2] = ctemp;
                  inum1++, inum2--;
                  rev_Str(pPtr,inum1,inum2);
          }
  }
/** End of rev_str*/
