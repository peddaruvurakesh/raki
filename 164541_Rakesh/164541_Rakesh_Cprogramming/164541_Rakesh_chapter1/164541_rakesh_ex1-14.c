/* This program is to write a program to print a histogram of the frequencies of different characters in its input. 
 * Author: rakesh
 * Created: 25 June, 2024
 * Modified:25 June, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define MAX 50
/** MAIN PROGRAM */
/** main: content of main prints histogram of frequencies of different characters */
int main(){
	char str[MAX];
	char ch;
	int i=0;
	int start,end;
	int k,count=0;
	printf("enter a string\n");
	while((ch=getchar())!=EOF)
		str[i++]=ch;
	str[i]='\0';
	for(start=0;str[start];start++)
	{
		//To not count already counted ones
		for(end=0;end<start;end++)  {
			if(str[start]==str[end])
				break;
		}
		//To check again if it is not counted one
		if(end==start)  
		{  
			for(end=start+1,count=1;str[end];end++)
				if(str[start] == str[end])
					count++;
			     if (str[start] == ' ') {
                printf("\\s ");
            } else if (str[start] == '\t') {
                printf("\\t ");
            } else if (str[start] == '\n') {
                printf("\\n ");
            } else {
                printf("%c ", str[start]);
	    }
                        //To print histogram of frequencies of characters
			for( k=0;k<count;k++)
				printf("*");
			printf("\n");
		}
	}
}
/* End main() */

