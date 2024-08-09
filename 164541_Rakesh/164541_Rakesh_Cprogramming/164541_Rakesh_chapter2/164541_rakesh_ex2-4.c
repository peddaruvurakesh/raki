/*
 * This program is to write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2.  
* Author: rakesh
* Created: 3 July, 2024
* Modified:3 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<ctype.h>
/** MACRO DEFINTIONS */
#define LIMIT 100

/** FUNCTION PROTOTYPES */
void squeeze(char s[],char a[]);

/** MAIN PROGRAM */
/** main: calls squeeze loop to delete common characters */
int main(){
	char str[LIMIT];
	char sub_str[LIMIT],ch;
	do{

printf("enter the string s1\n");
	scanf("%[^\n]",str);
printf("enter the string s2\n");
	scanf(" %[^\n]",sub_str);
	squeeze(str,sub_str);
        printf("%s\n",str);
	printf("do you want to repeat again?(y/n)\n");
	scanf(" %c",&ch);
	while(getchar()!='\n');
	}while(ch=='y'||ch=='Y');
}
/* End main() */

/*squeeze: to find the common characters on two strings and delete it from first string*/
void squeeze(char str[],char sub_str[]){
	int start,j,k=0,found;
	for(start=0;str[start]!='\0';start++)
        { 
		found=0;
                for(j=0;sub_str[j]!='\0';j++){
			if(tolower(str[start])==tolower(sub_str[j])){
				found=1;
			break;}
		}
	
		if(found==0)
			str[k++]=str[start];
        }
	/*null terminate the string*/
	str[k]='\0';
}
/** end of squeeze()*/
