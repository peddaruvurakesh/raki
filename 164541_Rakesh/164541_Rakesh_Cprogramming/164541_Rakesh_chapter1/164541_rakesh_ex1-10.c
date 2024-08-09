/*This program is to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\.  makes tabs and backspaces visible in an unambiguous way. 
 *
Name         :rakesh
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>


/* MAIN PROGRAM */
/*
 * main:content of main write here
*/
int main(){
int character;
int blanks=0;
/** getchar(): reads  the next character from stream and returns it as an unsigned char cast to an int, or EOF*/
while((character=getchar())!=EOF){
	if(character=='\t')
	{
		//prints \t
	printf("\\t");	
	}
	else if(character=='\b')
	{
		//prints \b
		printf("\\b");
		
	}
	else if(character=='\\')
	{
		//prints 
		printf("\\\\");
	}
	/** putchar():writes the character*/
	else 
		putchar(character);
}
}
/*End of main()*/	
