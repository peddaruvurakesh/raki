/*
 * This program is to write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Author: rakesh
 * Created:17 July, 2024
 * Modified:17 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define WORDS 100

/** FUNCTION PROTOTYPES */
void my_strncat(char *,char*,int);
void my_strncpy(char *,char*,int);
int my_strncmp(char*,char*,int);
/** MAIN PROGRAM */
/** main: Content of main write here */
int main(){
	char s[WORDS],t[WORDS];
	int n;
	printf("Enter the source string\n");	
	scanf(" %s",s);
	printf("Enter the destination string\n");
	scanf(" %s",t);
	printf("Enter a number \n");
	scanf(" %d",&n);
	//calling function to concatenate strings
		my_strncat(s,t,n);
	//	my_strncpy(s,t,n);
	/*int result=my_strncmp(s,t,n);
	if (result < 0) {
		printf("The first %d characters of '%s' are less than '%s'.\n", n, s, t);
	} else if (result == 0) {
		printf("The first %d characters of '%s' are equal to '%s'.\n", n, s, t);
	} else {
		printf("The first %d characters of '%s' are greater than '%s'.\n", n, s,t);
	}
*/
		printf("string --> %s\n",s);

}
/* End main() */
//my_strncat():To concatenate string t to the end of s
void my_strncat(char *s,char *t,int n){
	//To move end of s
	int min,max;
	for(max=0;s[max];max++);
	//concatenate t at end of s
	for(min=0;min<n&&t[min]!='\0';min++,max++){
		s[max]=t[min];
	}
	//Null terminate the string
	s[max]='\0';
}
/**End strncat() */
/*my_strncpy():To copy string t to s upto n*/
void my_strncpy(char *s,char *t,int n){
	//To move end of s
	int i;
	for(i=0;(i<n)&&(s[i] = t[i]);i++);

	//Null terminate the string
	s[i] = '\0';

}
/**End strncpy() */
int my_strncmp(char *s, char *t,int n) 
{ 
	int i; 
	for (i = 0; (s[i] == t[i])&&(i<n); i++) 
		if (s[i] == '\0'||t[i]=='\0') 
		       return 0;	
	if(i==n)
		return 0;
	else
	return s[i] - t[i]; 
}
