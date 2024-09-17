/*
 * This program is to do alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.
 * Author: Rakesh Pedddaruvu
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
int get_line(char line[], unsigned int max_line_len);
int getall(char []);
double pop(void);
double stk[MAX];
void duplicatetop(void);
void swapTopTwo(void);
void peek(int);
void clearStack(void);
void printInstructions(void);
int top=0;
char var = '0';
char line[MAX];
int line_i = 0;
/** MAIN PROGRAM */
/** main: Accepts input for reverse polish caluculator */

int main()
{
	int type,num; 
	printInstructions();
	double op2; 
	char s[MAX]; 
	 while(get_line(line, MAX)!=0){
		 line_i=0;
	/* reverse Polish calculator */
	while ((type = getall(s)) != '\0') { 
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
				/* Adding modulous operator */
			case '%':
				op2 = pop();

				if (op2 != 0.0)
				{
					int result=((int)pop() % (int)op2);
					/* Adjust result for negative modulus */
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
				/* To print data */
					printf("%.8g\n",pop());
				break;


			default: 
				printf("error: unknown command %s\n", s); 
				return 1;
				break; 
		}
	} 
	 }
}
/* End main() */
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

void duplicatetop(void) {
    if (top > 0) {
        double temp = stk[0];  
	/* Duplicate the first entered element */
        for (int i = top; i > 0; i--) {
            stk[i] = stk[i - 1];  // Shift all elements up by one
        }
        stk[0] = temp;  
	/* Place the duplicate at the beginning */
        top++;  
	/* Increment stack pointer */
    } else {
        printf("Error: Stack is empty, nothing to duplicate.\n");
    }
}

void swapTopTwo(void) {
    if (top > 1) {
        double temp = stk[0];  /* Swap the first two elements */
        stk[0] = stk[1];
        stk[1] = temp;
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}
/* To print top elements */
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
/* To clear stack */
void clearStack(void)

	{
  while (top > 0)
  {
    stk[--top] = 0.0;
  }
}
/* getline(): to get entire line */
int get_line(char line[], unsigned int max_line_len)
{
  int c, i;
  /* To get input from user and within limit */

  for (i = 0; i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}
/* getall(): To check input */
int getall(char s[])
{
  int i = 0, c;

  while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  

  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }
      /* Handle the minus sign: check if it should be treated as a negative number or an operator */
    if (c == '-') {
        int next = line[line_i];
        if (isdigit(next) || next == '.') {
            /* It's a negative number, continue processing */
            s[++i] = c = line[line_i++];
        } else {
            /* It's a subtraction operator, return it as is */
            return '-';
        }
    }

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = line[line_i++]))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = line[line_i++]))
      ;
  }

  --line_i;

  return NUMBER;
}
/* End of getall() */

