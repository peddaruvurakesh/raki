/* 
* This program is to write a loop equivalent to the for loop above without using && or ||.
* for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
* Author: rakesh
* Created: 3 July, 2024
* Modified:3 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define LIMIT 10
#define RANGE 50
/** MAIN PROGRAM */
/** main: writes a equivalent loop for above for loop */
int main(){
	int min;
	char name[RANGE],ch;
	do{
	printf("enter input:\n");
	for(min=0;min<LIMIT-1;min++){
	char ch=getchar();
	if(ch=='\n')
		break;
	else if(ch==EOF)
		break;
	else
	name[min]=ch;
	}
	/* null terminate the string */
	name[min]='\0';
	/* printing obtained characters */
	
	printf("output : %s\n",name);
	/*To repeat another time*/
        printf("do you want to give input another time ?(y/n)\n");
	scanf(" %c",&ch);
        /* To clear buffer */
	while(getchar()!='\n');
	}while(ch=='y'||ch=='Y');
	return 0;
}
/* End main() */
