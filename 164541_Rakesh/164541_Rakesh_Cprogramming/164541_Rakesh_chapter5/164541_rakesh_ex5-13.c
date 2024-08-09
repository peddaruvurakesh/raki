/*This program to execute tail, which prints the last n lines of its input. By default, n is set to 10, let us say, but it can be changed by an optional argument so that tail -n prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program. 
 * Author: rakesh
 * Created: 19 July, 2024
 * Modified:19 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<stdlib.h>
#include"error_handling.h"
/** MACRO DEFINITIONS */
#define MAXLINE 1000
/** FUNCTION PROTOTYPES */
void tail_print(char[],int );

/** MAIN PROGRAM */
/** main: Accepts input n lines and prints*/

int main(int argc,char *argv[]){
	int n;
        /* By default last 10 lines */
	char c;
        
	if(argc==1){
		n=10;
	}
	/*considering n value*/
	else{

	n=atoi(argv[1]);
	}
	/*checking argument count*/
	if(argc>2)
	{
		printf("usage ./a.out n\n");
			return 0;
	}
	char str[MAXLINE];
	char ch;
	int count=0,i=0;
	/*entering string*/
	while((ch=getchar())!=EOF){
		str[i++]=ch;
		}
	/* null terminate the string */
	str[i]='\0';
	if(i>MAXLINE-1)
	{
		handle_error(ERROR_OUT_OF_RANGE);
		return 1;
	}
	/* function call to print last n lines*/
	tail_print(str,n);
	

}
/* End of main() */
/* tail_print():To print last n lines like tail */
void tail_print(char str[],int num){
int index=0;
int count=0;
for(index=0;str[index]!='\0';index++){
	/*counting new lines */
if(str[index]=='\n'){
	count++;
}
}
/* To get last n lines */
int last=count-num;
count=0;
for(index=0;str[index]!='\0';index++){
if(str[index]=='\n'){
	count++;
}
/*after first lines it starts printing required lines*/
if(count>=last)
{
printf("%c",str[index]);
}
}
}
/* End tail_print()*/
