/*
 * This program is to write a program to print all input lines that are longer than 80 characters. 
 * Name:D.rakesh
* Author: rakesh
* Created: 4 July, 2024
* Modified:4 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define LINES 500
#define COUNT 500
/** FUNCTION PROTOTYPES */
//void copy(char to[],char from[]);
/** MAIN PROGRAM */
/** main: content of main write here */
int main(){
           int i=0,j,ch, start, big_line_length = 0, count = 0,index=0;
           char lines[LINES];
           char line[COUNT];
	   char str[COUNT];
	   int str_index = 0;
	   while((ch=getchar())!=EOF){
		   lines[index++]=ch;
	   }
lines[index]='\0';
    index = 0;
    while (lines[index] != '\0') {
        if (lines[index] == '\n') {
            line[start] = '\0'; // Null-terminate the current line
            if (count > 8) {
                for (j = 0; j < start; j++) {
                    str[str_index++] = line[j];
                }
                str[str_index++] = '\n';
            }
            count = 0; // Reset the count for the new line
            start = 0; // Reset the start for the new line
        } else {
            line[start++] = lines[index];
            count++;
        }
        index++;
    }

    // Handle the last line if it doesn't end with a newline
    if (count > 8) {
        line[start] = '\0';
        for (j = 0; j < start; j++) {
            str[str_index++] = line[j];
        }
        str[str_index++] = '\n';
    }

    str[str_index] = '\0'; // Null-terminate the final string

    printf("Lines longer than 8 characters:\n%s", str);

    return 0;
}
