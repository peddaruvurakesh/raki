/*
 * This program is to add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:23 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
/** MACRO DEFINITIONS */
#define MAX 26
/* signal that a number was found */
#define NUMBER '0'
#define VARIABLE '1'
#define BUFFSIZE 100
/** FUNCTION PROTOTYPES */
void push(double);
int getall(char[] );
double pop(void);
double stk[MAX];
int top=0;
char vars[MAX];
/** MAIN PROGRAM */
/** main: Reverse polish calculator assigning variables */

int main()
{
	int type,start=0,end=0;
       char cha_r[MAX];	
	double op2; 
	char s[MAX]; 
	/* reverse Polish calculator */
	while ((type = getall(s)) != EOF) { 
		switch (type) { 
			 //If number was found
			case NUMBER: 
				push(atof(s)); 
				break; 
			case VARIABLE:
			//if already assigned character exists	
			
				if(cha_r[start]==s[0]||cha_r[start+1]==s[0]){
					printf("%c=%d\n",s[0],vars[s[0]-'a']);
					push(vars[(s[0]-'a')]);
				}    
			//assign variable	        
				

                                else{
				cha_r[end++]=s[0];
				vars[(s[0]-'a')]=pop();
					printf("%c=%d\n",s[0],vars[s[0]-'a']);
				 }
				
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
				//In case of new line it pop and print number
			case '\n': 
				printf("%.8g\n", stk[top-1]); 
				break; 
			default: 
				printf("error: unknown command %c\n", s[0]); 
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

int buf = -1;
 //getch:reads the character from input.
int getch(void)
{
  char temp;

  if (buf != -1)
  {
    temp = buf;
    buf = -1;

    return temp;
  }

  return getchar();
}
//ungetch:pushes character back into the buffer.
void ungetch(int c)
{
  if (buf != -1)
  {
    printf("ungetch: buffer full\n");
  }
  else
  {
    buf = c;
  }
}
/* getop: get next character or numeric operand */
int getall(char s[]) 
{ 
	int  c; 
	while ((s[0]= c = getch()) == ' ' || c == '\t') 
		; 
 
	if(isalpha(c))
		return VARIABLE;
	if (!isdigit(c) && c != '.')	
		return s[0]; /* not a number */ 

	if (isdigit(c)) /* collect integer part */  
	return NUMBER;
	if (c != EOF) 
		ungetch(s[0]); 
}
/**End of getall*/
