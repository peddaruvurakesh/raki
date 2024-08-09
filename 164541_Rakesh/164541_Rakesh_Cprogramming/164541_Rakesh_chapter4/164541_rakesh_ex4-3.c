/*
 * This program is based on the given the basic framework, it's straightforward to extend the calculator. Add 
 the modulus (%) operator and provisions for negative numbers. 
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
/** MACRO DEFINITIONS */
#define MAX 5
/* signal that a number was found */
#define NUMBER '0'
#define BUFFSIZE 100
/** FUNCTION PROTOTYPES */
void push(double);
int getall(char []);
double pop(void);
double stk[MAX];
int top=0;
/** MAIN PROGRAM */
/** main: Accepts */

int main()
{
	int type; 
	double op2; 
	char s[MAX]; 
	/* reverse Polish calculator */
	while ((type = getall(s)) != EOF) { 
		switch (type) { 
			 //If number was found
			case NUMBER: 
				push(atof(s)); 
				break; 
				//Addition of two given numbers
			case '+': 
				push(pop() + pop()); 
				break; 
				
			case '*':
			       //Multiplication of numbers	
				push(pop() * pop()); 
				break; 
			case '-': 
				//Subtraction of numbers
				op2 = pop(); 
				push(pop() - op2); 
				break; 
			case '/': 
				//Division of two numbers
				op2 = pop(); 
				if (op2 != 0.0) 
					push(pop() / op2); 
				else 
					printf("error: zero divisor\n"); 
      				break;
			//Adding modulous operator
				   case '%':
      					op2 = pop();

      					if (op2 != 0.0)
      					{
        					push((int)pop() % (int)op2);
      					}		
      					else
      					{
        					printf("Error: zero divisor.\n");
      					}
				break; 
				//In case of new line it pop and print number
			case '\n': 
				printf("%.8g\n", pop()); 
				break; 
			default: 
				printf("error: unknown command %s\n", s); 
				break; 
		}
	} 
}

/* End main() */
/* push: push f onto value stack */
void push(double f)
{
	if(top == MAX) {
		printf("stack is overflow...\n");
		return;
	}


	stk[top++] = f;
}
/* pop: pop and return top value from stack */
double pop(void )
{
	if(top == 0) {
		printf("stack is underflow...\n");
		return 0.0;
	}

	return stk[--top];
}

int bufp = 0;
/* buffer for ungetch */
char buf[BUFFSIZE];
/* get a (possibly pushed-back) character */
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
/* push character back on input */
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
/* getall: get next character or numeric operand */
int getall(char s[]) 
{ 
	int i=0, c; 
	//escape whitespaces
	while ((s[0] = c = getch()) == ' ' || c == '\t') ; 
	if (!isdigit(c) && c != '.') 
		return c; /* not a number */ 
	i = 0; 
	if (isdigit(c)) /* collect integer part */ 
		while (isdigit(s[++i] = c = getch())) 
			; 
	if (c == '.') /* collect fraction part */ 

		while (isdigit(s[++i] = c = getch())) 
			; 
	s[i] = '\0'; 
	if (c != EOF) 
		ungetch(c); 
	return NUMBER; 
}
/**End of getall*/
