/* This program is to  add the commands to print the top elements of the stack without popping, to 
duplicate it, and to swap the top two elements. Add a command to clear the stack. 
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
/** MACRO DEFINITIONS */
#define MAX 50
/* signal that a number was found */
#define NUMBER '0'
#define BUFFSIZE 100
/** FUNCTION PROTOTYPES */
void push(double);
int getall(char []);
double pop(void);
void viewtop(void);
void duplicate(void);
void swap(void);
void clear();
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
				//To view top element
			case 't':
				viewtop();
				break;
			case 'd':
				duplicate();
				break;
			case 's':
				swap();
				break;
			case 'c':
				clear();
				break;
				//In case of new line it pop and print number
			case '\n': 
				printf("%.8g\n", stk[top-1]); 
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
/** viewtop:prints top element*/
void viewtop(void) {
	int start;
    if (top > 0){
	    for(start=0;start<top;start++)
		    printf("%g ",stk[start]);
	    printf("\n");
        printf("stack top: %g\n", stk[top-1]);
    }
    else
        printf("error: stack empty\n");
}
/*duplicate:duplicates the already present element*/
void duplicate(void) {
    if (top > 0) {
        double temp = stk[top-1];
        push(temp);
    } else {
        printf("error: stack empty\n");
    }
}
/*swap:Swap two elements present in stack*/
void swap(void) {
    if (top > 1) {
        double temp1 = stk[top-1];
        double temp2 = stk[top -2];
        stk[top-1] = temp2;
        stk[top- 2] = temp1;
    } else {
        printf("error: not enough elements to swap\n");
    }
}
/*clear:To clear the stack*/
void clear(void)
{
  while (top > 0)
  {
    stk[--top] = 0.0;
  }
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
/* getop: get next character or numeric operand */
int getall(char s[]) 
{ 
	int i=0, c; 
	while ((s[0] = c = getch()) == ' ' || c == '\t') 
		; 
	s[1] = '\0'; 
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
