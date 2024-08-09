/*
 * This program is to write a function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none. 

 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:11 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
#include"error_handling.h"
/** MACRO DEFINITIONS*/
#define RANGE 50
/** FUNCTION PROTOTYPES */
int strindex(char[],char);
/** MAIN PROGRAM */
/** main: content of main write here*/
int main(){
        char str[RANGE],t;
        int value;
        char ch,c;
        /* do while loop :for to repeat the loop based on condition */
        do{
                
                value=0;
                printf("Enter the main string\n");
		        while ((ch = getchar()) != EOF && ch != '\n') {
				/* error handling: if given range is more */
            if (value < RANGE - 1) {
                str[value++] = ch;
            } else {
		    /* To handle error */
                handle_error(ERROR_OUT_OF_RANGE);
                while ((ch = getchar()) != '\n' && ch != EOF); 
		/* To clear input buffer */
                return 0;
            }
        }
        str[value] = '\0';  
	/* null-terminating the string */
                
                /* character to find */
                printf("Enter the character\n");
                scanf(" %c",&t);

                /*calling strindex function to find rightmost index */
                int index=strindex(str,t);
                if (index != -1) {
                        printf("Rightmost index of '%c' in the string is: %d\n", t, index);
                } else {
                        printf("Character '%c' not found in the string.\n", t);
                }
                printf("\n");
                printf("do you want find again a character index in a string ? (y / n)\n");
                scanf(" %c",&c);
           while((ch=getchar())!='\n');
        }while(c=='y'||c=='Y');
        /* End of do-while */
}
		
/* End of main() */

/*strindex function to find a character in a string*/
int strindex(char s[],char t){
	int low_end;
	int length=strlen(s);
	/*it take input from the end of string for to find rightmost occurence */
	for(low_end=length-1;low_end>=0;low_end--)
	{
		//it checks whether t is present in string s or not 
		if(s[low_end] == t)
		{
			return low_end;
		}


	}
	/* if character is not found */
	return -1;
}
/*End of strindex*/
