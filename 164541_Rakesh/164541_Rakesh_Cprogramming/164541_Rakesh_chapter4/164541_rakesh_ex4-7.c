/*
 * This program is to write a routine ungets(s) that will push back an entire string onto the input
 * Author: Rakesh peddaruvu
 * Created: 10 July, 2024
 * Modified:23 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
/*Includes the string handling library.*/

/** MACRO DEFINITIONS */
#define MAXLEN 100
#define BUFFSIZE 100

/** FUNCTION PROTOTYPES */
int getstr(char [], int );
void ungets(char s[]);

/** MAIN PROGRAM */
/** main: Accepts entire string*/
int main(void)
{
  char line[MAXLEN];
  char line2[MAXLEN],ch;
  /*getstr function to get the input string and store it in line*/
  getstr(line, MAXLEN);
 
  /*into buffer using ungetch*/
  ungets(line);
  /*from buffer getting input */
  getstr(line2,MAXLEN);
  printf("%s", line2);
  
  
  return 0;
}
/* End of main()*/
int getch(void);
void ungetch(int c);

/*getstr():To get the input string and store it in line*/
int getstr(char s[], int lim) 
 { 
 int c, i; 
 i = 0; 
 /*get entire string line*/
 while ( ((c=getch()) != EOF )&&(--lim>0)) 
 s[i++] = c; 
if(c=='\n')
	 s[i++]=c;
 /*null terminate the string*/
 s[i] = '\0'; 
 return i; 
 } 
/*Index for the next free position in the buffer.*/
int bufp = 0;
/*Buffer array to store pushed-back characters.*/
char buf[BUFFSIZE];
/*ungets: Function to push back an entire string onto the input buffer.*/
void ungets(char s[])
{
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}
/*getch: Function to get a character from the buffer or standard input*/
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
/*ungetch: Function to push a character back into the buffer*/
void ungetch(int c)
{
  if (bufp >= BUFFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}
/** End of ungetch */

