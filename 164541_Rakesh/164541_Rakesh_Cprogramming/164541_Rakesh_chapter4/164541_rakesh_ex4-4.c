/*
 * Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 * Author: Rakesh Peddaruvu
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
double stk[MAX];
void duplicatetop(void);
void swapTopTwo(void);
void peek(int);
void clearStack(void);
void printInstructions(void);
int top=0;
/** MAIN PROGRAM */
/** main: Accepts input and works has reverse polish calculator it duplicates, swaps and clears*/

int main()
{
	int type,num; 
	printInstructions();
	double op2; 
	char s[MAX]; 
	/* reverse Polish calculator */
	while ((type = getall(s)) != EOF) { 
		switch (type) { 
			/*If number was found*/
			case NUMBER: 
				push(atof(s)); 
				break; 
				/*Addition of two given numbers*/
			case '+': 
				push(pop() + pop()); 
				break; 
		

			case '*':
				/*Multiplication of numbers*/	
				push(pop() * pop()); 
				break; 
			case '-': 
				/*Subtraction of numbers*/
				op2 = pop(); 
				push(pop() - op2); 
				break; 
			case '/': 
				/*Division of two numbers*/
				op2 = pop(); 
				if (op2 != 0.0) 
					push(pop() / op2); 
				else 
					printf("error: zero divisor\n"); 
				break;
				/*Adding modulous operator*/
			case '%':
				op2 = pop();

				if (op2 != 0.0)
				{
					int result=((int)pop() % (int)op2);
					// Adjust result for negative modulus
					if (result < 0 && op2 > 0) {
						result += (int)op2;
					} else if (result > 0 && op2 < 0) {
						result += (int)op2;
					}
					push(result);
				}		
				else
				{
					printf("Error: zero divisor.\n");
				}
				break;
			case 'D': /*To Duplicate top elelent of the stack*/
                                duplicatetop();
                                break;
                        case 'S': /*To Swap top 2 element of the stack*/
                                swapTopTwo();
                                break;
			case 'T':
				printf(" top elements :");
				scanf("%d",&num);
				peek(num);
				clearStack();
				break;
                        case 'C': /*To clear the stack*/
                                clearStack();
				printf("clear the stack\n");
                                break;
			case '\n':
				int i;
				for(i=0;i<top;i++)
					printf("%.8g ",stk[i]);
				break;


			default: 
				printf("error: unknown command %s\n", s); 
				return 1;
				break; 
		}
	} 
}
/* End main() */
/* To printInstructions to have clear understanding */
void printInstructions(void){
        printf("Welcome the Calculator!\n");
        printf("You can perform the following operations:\n");
        printf(" - Addition: +\n");
        printf(" - Subtraction: -\n");
        printf(" - Multiplication: *\n");
        printf(" - Division: /\n");
        printf(" - Modulo: %%\n");
       
        printf(" - Duplicate Top Element: D\n");
        printf(" - Swap Top 2 Elements: S\n");
        printf(" - print n top Elements: T\n");
        printf(" - Clear the Stack: C\n");
        printf("Enter your commands :\n");
}
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
	s[1]='\0';
	if (!isdigit(c) && c != '.'&& c!='-') 
		return c;
	/* not a number */ 
	i=0;
	if(c == '-'){
		/*Check as C is '-' or not*/
		char next = getch();  /*If it is then store the next value in next variable*/
		if(isdigit(next) || next == '.'){ /*Now check for that NEXT value like isdigit & .*/
			s[++i] = c = next; /*then store that in s[]*/
		}
		else{
			ungetch(next); /*Otherwise handling the space using ungetch()*/
			return c; /*And if that is operator then return That Sign*/
		}
	}

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
/*To duplicate a top element */
void duplicatetop(void) {
    if (top > 0) {
        double temp = stk[0];  // Duplicate the first entered element
        for (int i = top; i > 0; i--) {
            stk[i] = stk[i - 1];  // Shift all elements up by one
        }
        stk[0] = temp;  // Place the duplicate at the beginning
        top++;  // Increment stack pointer
    } else {
        printf("Error: Stack is empty, nothing to duplicate.\n");
    }
}
/* End  duplicatetop */
/* To swap two elements */
void swapTopTwo(void) {
    if (top > 1) {
        double temp = stk[0];  // Swap the first two elements
        stk[0] = stk[1];
        stk[1] = temp;
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}
/* End  swaptoptwo */
/* T print top given n elements */
void peek(int num){
        if(top > 0){ /*Checking for underflow condition*/
		int i;
		for(i=1;i<=num;i++)
                printf("%d element: %.8g\n",i, stk[--top]);
	       	/*Print the TOP Element*/
        }
        else{
                printf("Error: Stack is Empty can't print top element\n");
        }

}
/* End  of peek */
/* To clear the stack */
void clearStack(void)

	{
  while (top > 0)
  {
    stk[--top] = 0.0;
  }
}
/* End of clearstack*/


