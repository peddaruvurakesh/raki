/* Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest
* Author: rakesh
* Created: 4 July, 2024
* Modified:9 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
void skip_comments(char *);
/** MAIN PROGRAM */
/** main: opens a file (comment.c)and removes comments in it */
  
   int main()  //command line arguments
   {
          
          char ch,str[500];
	  int k=0;
          while( (ch = getchar()) != EOF )
		  str[k++]=ch;
	  str[k]='\0';
	  skip_comments(str);
	  printf("%s\n",str);
   }
/*  int line_comment = FALSE;
  

  int min = 0, j = 0;
  while (str[min] != '\0')
  {
   //if it is a comment then make linecomment true 
      if (str[min] == '/' && str[min + 1] == '/')
      {
        line_comment = TRUE;
      }

      if (str[min] == '\n')
      {
        line_comment = FALSE;
      }

    //include all characters except in line comment
      if (!line_comment )
      {
        no_com_str[j++] = str[min];
      }
      ++min;
    }
  no_com_str[j] = '\0';
  printf("%s\n",no_com_str);


  }
  */
/* End main() */
	  // Function to skip comments (both line and block comments)
void skip_comments(char *str) {
    int i = 0, j;
    while (str[i] != '\0') {
        if (str[i] == '/' && str[i + 1] == '/') {
            // Skip line comments
            i += 2;
            while (str[i] != '\n' && str[i] != '\0') {
                i++;
            }
        } else if (str[i] == '/' && str[i + 1] == '*') {
            // Skip block comments
            i += 2;
            while (!(str[i] == '*' && str[i + 1] == '/') && str[i] != '\0') {
                i++;
            }
	      if (str[i] != '\0') {
                i += 2; // Move past the closing '* /'
            }
            
        } else {
            str[j++]=str[i++];
        }
    }
    str[j]='\0';
}
