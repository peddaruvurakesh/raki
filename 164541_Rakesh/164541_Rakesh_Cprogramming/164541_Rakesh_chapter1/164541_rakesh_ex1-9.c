/*This program is to write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. 
Name         :rakesh
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
#define MAX 50
/* MAIN PROGRAM */
/*
 * main:Accepts characters and replaces more blanks by single blank 
*/
int main(){
int start ,end;
char str[MAX];
int character;
int blanks=0,value=0;
/** getchar(): reads  the next character from stream and returns it as an unsigned char cast to an int, or EOF*/
while((character=getchar())!=EOF){
    	str[value++]=character;
}
str[value]='\0';
/* To remove more than one blank spaces */
for(start=0;str[start];start++){
	if(((str[start]==' ')&&(str[start+1]==' '))||str[start]=='\t'){
		for(end=start;str[end];end++)
			str[end]=str[end+1];
		        start--;
	}
}
//NULL teminate the string
str[start]='\0';
printf("%s\n",str);
}
/*End of main*/	
