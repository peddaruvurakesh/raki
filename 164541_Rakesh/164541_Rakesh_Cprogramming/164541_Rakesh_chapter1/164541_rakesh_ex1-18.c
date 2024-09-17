/*
 * This program is to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. *
Author: rakesh
 * Created: 28 June, 2024
 * Modified:4 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define LENGTH 100
/** FUNCTION PROTOTYPES */
/** MAIN PROGRAM */
/** main:removes blank lines and tabs  */
int main(){
	char ch,str[LENGTH];
	int count=0;
	while((ch=getchar())!=EOF){
		str[count++]=ch;
		if(ch==' '||ch=='\t')
		{
			count--;
		}
	}
	str[count+1]='\0';
	/* To remove blank lines */
	int j=0,k;
	for(j=0;str[j]!='\0';j++){
		if((str[j]=='\n') && (str[j+1]=='\n')){
			for(k=j;str[k];k++)
				str[k]=str[k+1];
			j--;
		}
	}
	printf("%s\n",str);
}		
/* End main() */
