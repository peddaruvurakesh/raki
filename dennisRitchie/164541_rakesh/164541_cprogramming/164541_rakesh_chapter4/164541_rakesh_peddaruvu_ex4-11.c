/*
 * This program is to modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.
*/
/*
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
int getop(char []);
double pop(void);
double gstk[MAX];
void duplicatetop(void);
void swapTopTwo(void);
void peek(int);
void clearStack(void);
void printInstructions(void);
int gtop=0;
/** MAIN PROGRAM */
/** main: Accepts input for reverse polish calculator*/

int main()
{
	int itype,inum; 
	printInstructions();
	double d_op2; 
	char sStr[MAX]; 
	/* reverse Polish calculator */
	while ((itype = getop(sStr)) != EOF) { 
		switch (itype) { 
			/* If number was found */
			case NUMBER: 
				push(atof(sStr)); 
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
				d_op2 = pop(); 
				push(pop() - d_op2); 
				break; 
			case '/': 
				/* Division of two numbers */
				d_op2 = pop(); 
				if (d_op2 != 0.0) 
					push(pop() / d_op2); 
				else 
					printf("error: zero divisor\n"); 
				break;
				/*  modulous operator */
			case '%':
				d_op2 = pop();

				if (d_op2 != 0.0)
				{
					int iresult=((int)pop() % (int)d_op2);
					/* Adjust result for negative modulus */
					if (iresult < 0 && d_op2 > 0) {
						iresult += (int)d_op2;
					} else if (iresult > 0 && d_op2 < 0) {
						iresult += (int)d_op2;
					}
					push(iresult);
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
				scanf("%d",&inum);
				peek(inum);
				clearStack();
				break;
                        case 'C': /*To clear the stack*/
                                clearStack();
                                break;
			case '\n':
				
					printf("%.8g\n",pop());
				break;


			default: 
				printf("error: unknown command %s\n", sStr); 
				return 1;
				break; 
		}
	} 
}
/* To print instructions for user to understand */
/*
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
*/
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
/*
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
*/
void push(double dvar)
{
	if(gtop == MAX) {
		printf("stack is overflow...\n");
		return;
	}


	gstk[gtop++] = dvar;
}
/* pop: pop and return top value from stack */
/*
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
*/
double pop(void )
{
	if(gtop == 0) {
		printf("stack is underflow...\n");
		return 0.0;
	}

	return gstk[--gtop];
}
/* getop : To return input */
/*
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
*/
int getop(char sStr[]) {
    static int buf = EOF; 
    /* Internal buffer to store pushed-back character */
    int iVar, iNum = 0;

    /* If there's a character in the buffer, use it, otherwise, read from input */
    if (buf != EOF) {
        iVar = buf;
        buf = EOF;  
	/* Clear the buffer after using the stored character */
    } else {
        iVar = getchar();
    }

    /* Skip whitespace */
    while (iVar == ' ' || iVar == '\t') {
        iVar = getchar();
    }

    sStr[0] = iVar;
    sStr[1] = '\0';

    /* Check if the character is not a number or a decimal point or a negative sign */
    if (!isdigit(iVar) && iVar != '.' && iVar != '-') {
        return iVar;  /* Not a number, return it */
    }

    /* Handle negative numbers */
    if (iVar == '-') {
        int inext = getchar();
        if (!isdigit(inext) && inext != '.') {
            buf = inext;  
	    /* Store the non-digit character for later */
            return '-';  
	    /* Return '-' as an operator */
        }
        sStr[++iNum] = iVar = inext;  
	/* Otherwise, treat as part of a negative number */
    }

    /* Read the integer part */
    if (isdigit(iVar)) {
        while (isdigit(sStr[++iNum] = iVar = getchar())) {
            /* Continue reading digits */
        }
    }

    /* Read the fractional part */
    if (iVar== '.') {
        while (isdigit(sStr[++iNum] = iVar = getchar())) {
            /* Continue reading digits after the decimal point */
        }
    }

    sStr[iNum] = '\0'; 
    /* Null-terminate the string */

    if (iVar != EOF) {
        buf = iVar;
      	/* Store the character for the next call */
    }

    return NUMBER;  
    /* Indicate that a number was found */
}


/**End of getall*/
void duplicatetop(void) {
    if (gtop > 0) {
        double temp = gstk[0];  
	/* Duplicate the first entered element */
        for (int i = gtop; i > 0; i--) {
            gstk[i] = gstk[i - 1];  
	    /* Shift all elements up by one */
        }
        gstk[0] = temp;  
	/* Place the duplicate at the beginning */
        gtop++;  /* Increment stack pointer */
    } else {
        printf("Error: Stack is empty, nothing to duplicate.\n");
    }
}

void swapTopTwo(void) {
    if (gtop > 1) {
        double temp = gstk[0];  
	/* Swap the first two elements */
        gstk[0] = gstk[1];
        gstk[1] = temp;
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}
void peek(int num){
        if(gtop > 0){
	       	/*Checking for underflow condition*/
		int i;
		for(i=1;i<=num;i++)
                printf("%d element: %.8g\n",i, gstk[--gtop]);
	       	/*Print the TOP Element*/
        }
        else{
                printf("Error: Stack is Empty can't print top element\n");
        }

}
/* To clear the entire stack */
void clearStack(void)

	{
  while (gtop > 0)
  {
    gstk[--gtop] = 0.0;
  }
}
/* End of clearStack*/

