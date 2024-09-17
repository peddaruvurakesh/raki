/*
 * This program is to write the function any(s1,s2), which returns the first location in a string s1 where any character from the 
 * string s2 occurs, or -1 if s1 contains no characters from s2
 * Author: rakesh
 * Created: 3 July, 2024
 * Modified:3 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>

/** MACRO DEFINTIONS */
#define LIMIT 100

/** FUNCTION PROTOTYPES */
int find(char s[],char a[]);
/** MAIN PROGRAM */
/** main: calls find loop and prints return value */
int main(){
	char str[LIMIT];
	char sub_str[LIMIT];
	char ch;
	do{
		/** enter string 1 **/
		printf("enter the string s1\n");
		scanf("%[^\n]",str);
		/** enter string 2 **/
		printf("enter the string s2\n");
		scanf(" %[^\n]",sub_str);
		int index=find(str,sub_str);
		if(index!=-1)
			printf("duplicate character found at index %d in string1\n",index);
		else
			printf("no character found  %d\n",index);

		printf("do you want to do it again? (y/n)\n");
		scanf(" %c",&ch);
		while(getchar()!='\n');
	}while(ch=='y' || ch=='Y');
}
/* End main() */

/*find: to find the common character on  string s1 and to return index*/
int find(char s[],char a[]){
	int i,j,found;
	for(i=0;s[i]!='\0';i++)
	{ 
		for(j=0;a[j]!='\0';j++){
			if(s[i]==a[j]){
				/*if character is found from string1 into string2 */
				return i;
			}


		}
	}
	/* if s1 contains no characters from s2 */
	return -1;
}
/** End of find*/
