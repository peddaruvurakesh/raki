
/*
* This program is to Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise 
* Author: rakesh
* Created: 15 July, 2024
* Modified:16 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define SIZE 50
/** FUNCTION PROTOTYPES */
int strend(char[],char[]);
/** MAIN PROGRAM */
/** main: Contents of main write here */
int main()
{
	char main_str[SIZE],sub_str[SIZE];

	printf("Enter the main string\n");
	scanf("%[^\n]",main_str);
	printf("Enter the sub string\n");
	scanf("%s",sub_str);
	int index=strend(main_str,sub_str);
	printf("%d\n",index);
}
/**End of main() */

/**strend(): this function returns index position */
int strend(char main_str[],char sub_str[]){
	int start,end;
	for(start=0;main_str[start];start++)
	{
		if(main_str[start] == sub_str[0])
		{
			for(end=1;sub_str[end];end++)
			{
				if(sub_str[end]!=main_str[start+end])
					break;
			}
			//To find sub string  occurs at the end of the main string
                       if(main_str[start+end]=='\0'){
			       //if sub string is found
			if(sub_str[end] == '\0') 
				return 1;
			else
				return 0;
		       }
		}
	}
}
/*End of strend*/
