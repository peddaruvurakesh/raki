/*This program is to write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters
 * Author: rakesh
 * Created: 4 July, 2024
 * Modified:16 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** Macro definitions */
#define CHAR 20

/** FUNCTION PROTOTYPES */
void escape(char[],char[]);

/** MAIN PROGRAM */
/** main: calls escape function*/
int main(){
	char s[CHAR];
	char ch;int i=0;
	char t[CHAR];
	while((ch=getchar())!=EOF)
		t[i++]=ch;
	//call escape function
	escape(s,t);
	printf("%s",s);
}
/* End main() */
/*escape():converts characters like newline and tab into visible escape sequences like \n and \t*/
void escape(char s[],char t[]){
		int i,j;
		for(i=0,j=0;t[i]!='\0';i++)	{
			switch (t[i]) {
				/*if it is newline*/
				case '\n':
					s[j++]='\\';
					s[j++]='n';
					break;
					/*if it is a tabspace*/
				case '\t':
					s[j++]='\\';
					s[j++]='t';
					break;
					/* By default add characters into array*/
				default:
					s[j++]=t[i];
					break;
			}
		}
		//Null terminate the string
		s[j]='\0';
	}
/* End  of escape()*/
