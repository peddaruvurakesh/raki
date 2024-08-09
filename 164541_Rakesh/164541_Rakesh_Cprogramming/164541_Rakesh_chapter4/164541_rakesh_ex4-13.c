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
 void rev_str(char *,int,int);
/** MAIN PROGRAM */
/** main: Content of main write here */

   int main()
   {
           char s[WORDS];
           printf("Enter the string\n");
           scanf("%s",s);
          //function call
          rev_str(s,0,strlen(s)-1);
          printf("s = %s\n",s);
  }
/* End main() */
/** rev_str: To reverse the string using recursion*/
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
/** End of rev_str*/
