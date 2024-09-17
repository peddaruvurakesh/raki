/*
 * This program is to expand(s1,s2) that expands shorthand notations like in order a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally. 
 * Author: rakesh
 * Created: 5 July, 2024
 * Modified:16 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
//C standard library header file
#include<ctype.h>

/** MACRO DEFINITIONS */
#define WORDS 100

/** FUNCTION PROTOTYPES */
void expand(char[],char[]);

/** MAIN PROGRAM */
/** main: Content of main write here */
int main(){
	char s1[WORDS],a[20],s2[WORDS];
	char start,end,ch;
	char c;
	int i=0,j,k=0;
	while((ch=getchar())!=EOF&&ch!='\n')
		s1[i++]=ch;
	//Null terminate the string
	s1[i]='\0';

	expand(s1,s2);
	i=0;
	while (s2[i] != '\0') {
		/* Check for alphabetic range*/
		if (isalpha(s2[i])) {
			start = s2[i];
			while (isalpha(s2[i])) {
				end = s2[i];
				i++;
			}
			/*if a - z*/
		if(start<end){
			for ( c = start; c <= end; c++) {
				printf("%c", c);
			}
		}
			/*if z - a*/
		else
		{

			for ( c = start; c >= end; c--) {
				printf("%c", c);
		}
		
		}
		}
		/* Check for numeric range*/
		if (isdigit(s2[i])) {
			start = s2[i];
			while (isdigit(s2[i])) {
				end = s2[i];
				i++;
			}
	
			for ( c = start; c <= end; c++) {
				printf("%c", c);
			}
			
		}

		/* Move to the next character if it's neither alphabetic nor numeric */
		if(s2[i]=='-'){
			
			printf("%c",s2[i]);
			i++;
		}
		if (!isalpha(s2[i]) && !isdigit(s2[i])) {
			printf("%c",s2[i]);
			i++;
		}
	}

	return 0;
}
/* End main() */
/* expand():To keep given characters in order*/
void expand(char s1[],char s2[]){
	int n=strlen(s1);
	int i,j,temp;
	for(i=0,j=0;i<n;i++,j++)
	{
		/*to print as a-z-0-9 as az-09 */
			if(isdigit(s1[i-1])&&(s1[i]=='-')&&isdigit(s1[i+1])||isalpha(s1[i-1])&&(s1[i]=='-')&&isalpha(s1[i+1])){
			i++;	}
                 s2[j]=s1[i];
		}
	

	//Null terminate the string
	s2[j]='\0';

}
//End of expand()
