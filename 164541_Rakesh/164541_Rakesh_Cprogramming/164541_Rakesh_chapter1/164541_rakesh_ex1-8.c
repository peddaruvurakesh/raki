/*This is to write a program to count blanks, tabs, and newlines. 
 
Name         :rakesh
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
#include"error_handling.h"
/*MACRO DECLARATIONS*/
#define RANGE 100
/* MAIN PROGRAM */
/*
 * main:Accepts characters and counts number of blanks tabs and newlines
*/
int main(){
	char str[RANGE];
     
	int blanks=0, tabs=0,newlines=0;
	int count=0,character;
	char c;
		character=0;
	while((character=getchar())!=EOF)
		str[count++]=character;
	str[count]='\0';
	while(character=getchar()!=EOF&&character!='\n');
	//error handling
	if(count>RANGE-1){
		handle_error(ERROR_OUT_OF_RANGE);
		return 0;
	}
	int index;
	/* To count tabs newlines spaces */
	for(index=0;str[index]!='\0';index++){
	
		if(str[index]==' ') 
			blanks++;
		if(str[index]=='\t')
			tabs++;
		if(str[index]=='\n')
			newlines++;}
	printf("Total blanks %d Total tabs %d Total new lines %d\n",blanks,tabs,newlines);

	/* To clear the buffer */
}
/* End of main() */
