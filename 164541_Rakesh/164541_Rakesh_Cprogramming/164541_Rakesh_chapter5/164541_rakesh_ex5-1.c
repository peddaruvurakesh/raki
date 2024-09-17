/*This program is to rewrite getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input
* Author: rakesh
* Created: 17 July, 2024
* Modified:17 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<ctype.h>
/** MACRO DEFINITIONS */
#define MAXLEN 500
#define BUFFSIZE 100
/** FUNCTION PROTOTYPES */
int getch(void);
void ungetch(int c);
int getint(int *pn);
/** MAIN PROGRAM */
/** main: Rewrites getint by calling getint function*/
int main()
{
  int number = 0;

  getint(&number);
  printf("%d\n", number);

  
}
/* End main() */
/* getint: get next integer from input into *pn */
 int getint(int *pn)
 {
 int c, sign;
 while (isspace(c = getch())) /* skip white space */
 ;
 if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
 ungetch(c); /* it is not a number */
 return 0;
 }
 sign = (c == '-') ? -1 : 1;
 if (c == '+' || c == '-')
 c = getch();
 if(!isdigit(c))
	 return 0;
 for (*pn = 0; isdigit(c); c = getch())
 *pn = 10 * *pn + (c - '0');
 *pn *= sign;
 if (c != EOF)
 ungetch(c);
 return c;
 }
/*end of getint()*/
 char buf[BUFFSIZE]; /* buffer for ungetch */
 int bufp = 0; /* next free position in buf */
 int getch(void) /* get a (possibly pushed-back) character */
 {
 return (bufp > 0) ? buf[--bufp] : getchar();
 }
 void ungetch(int c) /* push character back on input */
 {
 if (bufp >= BUFFSIZE)
 printf("ungetch: too many characters\n");
 else
 buf[bufp++] = c;
 }

