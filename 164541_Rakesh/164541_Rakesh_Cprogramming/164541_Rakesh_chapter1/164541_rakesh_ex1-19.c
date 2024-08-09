/*
* This program is to create a function reverse(s) that reverses the character string s. Use it to 
write a program that reverses its input a line at a time. 
* Author: rakesh
* Created: 28 June, 2024
* Modified:4 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define CHAR 200
/** FUNCTION PROTOTYPES */
void rev(char s[]);
/** MAIN PROGRAM */
/** main: content of main write here */
int main(){

        char s[CHAR],a[CHAR],ch;
        int i,j,k=0,t=0;
        while((ch=getchar())!=EOF){
		s[k++]=ch;
	if(ch=='\n'){
		//calling reverse function
		rev(s);
		k=0;
	}
	}
}
/* End main() */
/** rev(): it reverse the lines */
void rev(char s[]){
	int i,j,n,k;
	char temp,a[200];
        for(j=0;s[j]!='\0';j++); 
        for(i=0,j=j-1;i<j;i++,j--)
        {
                temp = s[i], s[i] = s[j], s[j] = temp;
        }
	
        printf("After reversing the string : %s\n",s);

}
/** End of rev()*/
