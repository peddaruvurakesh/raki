/*This program is to write getfloat, the floating-point analog of getint. What type does 
  getfloat return as its function value? 
 * Author: rakesh
 * Created: 17 July, 2024
 * Modified:17 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<ctype.h>
#include<math.h>
/** MACRO DEFINITIONS */
#define MAXLEN 500
#define BUFFSIZE 100
/** FUNCTION PROTOTYPES */
int getch(void);
void ungetch(int c);
int getfloat(double *ptr);
	/** MAIN PROGRAM */
	/** main: calls getfloat function */


int main()
{
	double number = 0;

	getfloat(&number);
	printf("%.6f\n", number);


}
/* End main() */
/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
	int c, sign;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'&& c!='.') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if(!isdigit(c))
		return 0;
	//Before decimal point
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	//after decimal point
	if(c=='.')
	{
		int i;
		for (i = 1; (c = getch()) && isdigit(c); ++i)
		{
			*pn += (c - '0') / (pow(10, i));
		}
	}
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
/*end of getfloat()*/
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
