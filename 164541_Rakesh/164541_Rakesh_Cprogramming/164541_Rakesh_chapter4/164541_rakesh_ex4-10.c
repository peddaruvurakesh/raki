/* An alternate organization uses getline to read an entire input line; this makes 
getch and ungetch unnecessary. Revise the calculator to use this approach. 
 * Author: rakesh
 * Created: 24 July, 2024
 * Modified:24 July, 2024
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
int get_line(char[],int);
char line_i[BUFFSIZE];
int top=0,line=0;
/** MAIN PROGRAM */
/** main: Accepts */

int main()
{
	int type; 
	double op2; 
	char s[MAX]; 
	while(get_line(line_i,BUFFSIZE)!=0){
		line=0;
	/* reverse Polish calculator */
	while ((type = getall(s)) != '\0') { 
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

/* getline: get line into s, return length */
 int get_line(char line_i[], int lim)
 {
 int c, i;
 i = 0;
 for(i=0;i<lim && (c=getchar())!=EOF && c!='\n';++i){
	 line_i[i]=c;
 }

 if (c == '\n'){
 line_i[i] = c;
 ++i;
 }
 line_i[i]='\0';
 return i;
 }

int getall(char s[])
{
  int i = 0, c;

  while ((s[0] = c = line_i[line++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  /*if (isalpha(c))
  {
    
    return VARIABLE;
  }*/

  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }

  if (c == '-')
  {
    int next = line_i[line++];
    if (next == '\n' || next == ' ' || next == '\t' || next == '\0')
    {
      --line;
      return '-';
    }
    else if (!isdigit(next) && next != '.') // not a number
    {
      return next;
    }
    else
    {
      s[++i] = c = next;
    }
  }
  else
  {
    c = line_i[line++];
  }

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = line_i[line++]))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = line_i[line++]))
      ;
  }

  --line;
  return NUMBER;
}
/**End of getall*/
