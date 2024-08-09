/** This program is to write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget 
 * about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) 
* Author: rakesh
* Created: 11 July, 2024
* Modified:11 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define TRUE (1 == 1)
#define FALSE !TRUE
/** FUNCTION PROTOTYPES */
/** MAIN PROGRAM */
/** main: Accepts */
  
   int main()  //command line arguments
   {
  
          char ch,str[200],no_com_str[200];
	  int k=0;
          while( (ch = getchar()) != EOF )
		  str[k++]=ch;
  int line_comment = FALSE;
  
int parentheses =0,brackets=0,braces=0;
  int min= 0, j = 0,i=0;
  while (str[min] != '\0')
  {
    
      /*if (str[min] == '/' && str[min + 1] == '/')
      {
        line_comment = TRUE;
      }
      */
      if (str[min] == '/' && str[min + 1] == '/')
      {
	      
	      for(i=min;str[i];i++){
		      if(str[i]=='/'&&str[i+1]=='/')
			      break;
	              }
      printf("comments error\n");
  }
      if (str[min] == '/' && str[min + 1] == '*')
      {
	      
	      for(i=min;str[i];i++){
		      if(str[i]=='*'&&str[i+1]=='/')
			      break;
	              }
      printf("comments error\n");
  }
        
      
      if (str[min] == '\n')
      {
        line_comment = FALSE;
      }
      // increments parantheses
      else if (str[min] == '(')
      {
        ++parentheses;
      }
    // decrements parantheses
      else if (str[min] == ')')
      {
        --parentheses;
      }
    
      else if (str[min] == '{')
      {
        ++braces;
      }
    // decrements parantheses
      else if (str[min] == '}')
      {
        --braces;
      }
      else if (str[min] == '[')
      {
        ++brackets;
      }
    // decrements parantheses
      else if (str[min] == ']')
      {
        --brackets;
      }
      if (!line_comment )
      {
        no_com_str[j++] = str[min];
      }
      ++min;
    }
  //checks parentheses is correct or not if not shows error
  if(parentheses){
	  printf("parentheses error\n");
  }
  if(braces){
	  printf("braces error\n");
  }
  if(brackets){
	  printf("brackets error\n");
  }
  no_com_str[j] = '\0';
  printf("%s\n",no_com_str);


  }

/* End main() */
