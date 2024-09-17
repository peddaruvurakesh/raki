/*
 * This program is to write a pointer version of the function strcat that we showed in Chapter 2:
 strcat(s,t) copies the string t to the end of s.
 * Author: rakesh
 * Created: 03 sep, 2024
 * Modified:03 sep, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include"error_handling.h"

/** MACRO DEFINITIONS */
#define WORDS 100

/** FUNCTION PROTOTYPES */
void my_strcat(char *,char*);
/** MAIN PROGRAM */
/** main: Accepts input and calls strcat function */
int main(){
	char s[WORDS],t[WORDS];
	char ch_1,ch_2,character;
	int index_1,index_2;
	/*do-while: To ask user to repeat this process again or not based on condition*/
	do{
		index_1=0,index_2=0;
		printf("Enter the source string\n");	
		while((ch_1=getchar())!=EOF&&ch_1!='\n'){
			s[index_1++]=ch_1;
		}
		s[index_1]='\0';
		/* error detection for range in s */
		if(index_1>WORDS){
			handle_error(ERROR_OUT_OF_RANGE);
			return 0;
		}
		printf("Enter the destination string\n");
		while((ch_2=getchar())!=EOF&&ch_2!='\n'){
			t[index_2++]=ch_2;
		}
		t[index_2]='\0';
		/* error detection for range in t */
		if(index_2>WORDS){
			handle_error(ERROR_OUT_OF_RANGE);
			return 0;
		}
		/*calling functitrcat to concatenate strings*/
		my_strcat(s,t);
		printf("after string concatenation --> %s\n",s);
		printf("do you want to concatenate another string(y / n)\n"); 
		scanf(" %c",&character);
		while((ch_1=getchar())!='\n');
	}while(character=='y'||character=='Y');

}
/* End main() */
/*my_strcat():To concatenate string t to the end of s*/
void my_strcat(char *s,char *t){
	//To move end of s
	for(;*s!='\0';*s++);
	//concatenate t at end of s
	for(;*t!='\0';s++,t++){
		*s=*t;}
	*s='\0';
}
/**End strcat() */

