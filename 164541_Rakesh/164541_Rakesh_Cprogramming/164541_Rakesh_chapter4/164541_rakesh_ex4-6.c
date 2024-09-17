/*
 * This program is to add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value
 * Author: Rakesh Peddaruvu
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
int getall(char []);
double pop(void);
double stk[MAX];
void print_all_variables();
void print_last_result();
int top=0;
double last_result=0;
char vars[MAX];
/** MAIN PROGRAM */
/** main: Reverse polish calculator assigning variables */

int main()
{
	int type,start,end=0,n=0;
       char cha_r[MAX];	
	double op2; 
	char s[MAX]; 
	int true_val;
	/* reverse Polish calculator */
	while ((type = getall(s)) != EOF) { 
		true_val=1;
		start=0;
		switch (type) { 
			 /*If number was found */
			case NUMBER: 
				push(atof(s)); 
				break; 
			case VARIABLE:
			/*if already assigned character exists*/	
			
				while(start<MAX){
				if(cha_r[start]==s[0]){
					printf("%c=%d\n",s[0],vars[s[0]-'a']);
					push(vars[(s[0]-'a')]);
					true_val=0;
				}    
				start++;
			}
			
			/*assign variable*/	        
                                if(true_val){
				cha_r[end++]=s[0];
				vars[(s[0]-'a')]=pop();
					printf("%c=%d\n",s[0],vars[s[0]-'a']);
				 }
				break;
			case '=':
				 vars[(s[0]-'a')]=pop();
                                        printf("%c=%d\n",s[0],vars[s[0]-'a']);
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
				/*In case of new line it pop and print number*/
			 case '@':
                       print_all_variables();
                       break;

                      case 'l':
                           print_last_result();
                                 break;
			case '\n': 
				  last_result=stk[top-1];
				printf("%.8g\n", last_result); 
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
/* print all stored variables */
void print_all_variables()
{
    for (int i = 0; i < MAX; i++) {
        if (vars[i] != 0) {
            printf("%d\n", vars[i]);
        }
    }
}

/* print the last result */
void print_last_result()
{
    printf("Last result = %.8g\n", last_result);
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
	int i=0, c,d; 
	while ((s[0] = c = getch()) == ' ' || c == '\t') 
		; 
	s[1] = '\0'; 
	if(isalpha(c)&&(c=getch())!='=')
		return VARIABLE;

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

