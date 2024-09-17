/*
 * This program is to Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. 
 * Author: rakesh
 * Created: 4 July, 2024
 * Modified:9 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
// long input line count
#define COLUMN 10
/** MAIN PROGRAM */
/** main: Accepts characters and folds long input lines */
int main(){
	char ch;
	int i=0,j=0,k=0;
	char line[500];
	

	while((ch=getchar())!=EOF){
		line[i++]=ch;
	}
	line[i]='\0';
            for (j = 0; j < i; j += COLUMN) {
        // Print a line of WIDTH characters or up to the end of the buffer
        for (int k = j; k < j + COLUMN && k < i; k++) {
            printf("%c",line[k]);
        }
        putchar('\n');  // Newline after each line of WIDTH characters
    }



}
/* End main() */
