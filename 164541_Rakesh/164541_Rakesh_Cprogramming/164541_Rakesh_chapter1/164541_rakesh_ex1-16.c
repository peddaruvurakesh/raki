/*
* This program is to revise the main routine of the longest-line program so it will correctly print the length of arbitrary long 
* input lines, and as much as possible of the text.
 * Name:D.rakesh
* Author: rakesh
* Created: 4 July, 2024
* Modified:4 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define LINES 50
#define COUNT 50
/** FUNCTION PROTOTYPES */
void copy(char to[],char from[]);
/** MAIN PROGRAM */
/** main: content of main write here */
int main(){
           int ch, start, big_line_length = 0, count = 0;
           char lines[LINES];
           char longest[COUNT];
           for(start=0; (ch = getchar()) != EOF;start++ )
          {
           
                  count++;
                lines[start]=ch;
                  if(ch == '\n')
                  {
                         
                          if(count > big_line_length)
                          {
                                  big_line_length = count;
                                  copy(longest,lines);
}
count=0;
start=-1;
}
}
			 printf("longest line is- %s",longest);
		  
         printf("  with length = %d\n",big_line_length);
}
/* End main() */
/* To copy content into another string*/
void copy(char to[],char from[]){
	int i;
	i=0;
	while((to[i]=from[i])!='\0')
		++i;
}
/* End copy()*/
