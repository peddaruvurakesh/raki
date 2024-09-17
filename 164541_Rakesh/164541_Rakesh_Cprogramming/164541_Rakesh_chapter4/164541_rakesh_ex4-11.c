/*
 * This program is to modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.
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
int getop(char []);
double pop(void);
double stk[MAX];
void duplicatetop(void);
void swapTopTwo(void);
void peek(int);
void clearStack(void);
void printInstructions(void);
int top=0;
/** MAIN PROGRAM */
/** main: Accepts input for reverse polish calculator*/

int main()
{
	int type,num; 
	printInstructions();
	double op2; 
	char s[MAX]; 
	/* reverse Polish calculator */
	while ((type = getop(s)) != EOF) { 
		switch (type) { 
			/* If number was found */
			case NUMBER: 
				push(atof(s)); 
				break; 
				/* Addition of two given numbers */
			case '+': 
				push(pop() + pop()); 
				break; 
		

			case '*':
				/* Multiplication of numbers */
				push(pop() * pop()); 
				break; 
			case '-': 
				/* Subtraction of numbers */
				op2 = pop(); 
				push(pop() - op2); 
				break; 
			case '/': 
				/* Division of two numbers */
				op2 = pop(); 
				if (op2 != 0.0) 
					push(pop() / op2); 
				else 
					printf("error: zero divisor\n"); 
				break;
				/*  modulous operator */
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
				printf(" number of top elements:");
				scanf("%d",&num);
				peek(num);
				clearStack();
				break;
                        case 'C': /*To clear the stack*/
                                clearStack();
                                break;
			case '\n':
				
					printf("%.8g\n",pop());
				break;


			default: 
				printf("error: unknown command %s\n", s); 
				return 1;
				break; 
		}
	} 
}
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
/*int getop(char s[])
{
  int i = 0, c;
  static int buf = EOF;

  while ((s[0] = c = getchar()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }

  if (c == '-')
  {
    int next = getchar();
    if (!isdigit(next) && next != '.')
    {
      return next;
    }

    s[i] = c;
    c = next = buf;
  }
  else
  {
    c = getchar();
  }

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getchar()))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = getchar()))
      ;
  }

  if (c != EOF)
  {
    buf = c;
  }

  return NUMBER;
}*/
int getop(char s[]) {
    static int buf = EOF;  /* Internal buffer to store pushed-back character */
    int c, i = 0;

    /* If there's a character in the buffer, use it, otherwise, read from input */
    if (buf != EOF) {
        c = buf;
        buf = EOF;  
	/* Clear the buffer after using the stored character */
    } else {
        c = getchar();
    }

    /* Skip whitespace */
    while (c == ' ' || c == '\t') {
        c = getchar();
    }

    s[0] = c;
    s[1] = '\0';

    /* Check if the character is not a number or a decimal point or a negative sign */
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;  /* Not a number, return it */
    }

    /* Handle negative numbers */
    if (c == '-') {
        int next = getchar();
        if (!isdigit(next) && next != '.') {
            buf = next;  
	    /* Store the non-digit character for later */
            return '-';  
	    /* Return '-' as an operator */
        }
        s[++i] = c = next;  
	/* Otherwise, treat as part of a negative number */
    }

    /* Read the integer part */
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getchar())) {
            // Continue reading digits
        }
    }

    /* Read the fractional part */
    if (c == '.') {
        while (isdigit(s[++i] = c = getchar())) {
            /* Continue reading digits after the decimal point */
        }
    }

    s[i] = '\0';  /* Null-terminate the string */

    if (c != EOF) {
        buf = c;  /* Store the character for the next call */
    }

    return NUMBER;  /* Indicate that a number was found */
}


/**End of getall*/
void duplicatetop(void) {
    if (top > 0) {
        double temp = stk[0];  
	/* Duplicate the first entered element */
        for (int i = top; i > 0; i--) {
            stk[i] = stk[i - 1];  
	    /* Shift all elements up by one */
        }
        stk[0] = temp;  
	/* Place the duplicate at the beginning */
        top++;  /* Increment stack pointer */
    } else {
        printf("Error: Stack is empty, nothing to duplicate.\n");
    }
}

void swapTopTwo(void) {
    if (top > 1) {
        double temp = stk[0];  
	/* Swap the first two elements */
        stk[0] = stk[1];
        stk[1] = temp;
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}
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
/* To clear the entire stack */
void clearStack(void)

	{
  while (top > 0)
  {
    stk[--top] = 0.0;
  }
}
/* End of clearStack*/


