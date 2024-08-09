/*This program prints its input one word per line. 

Name         :rakesh
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
/*MACRO DEFINITIONS*/
#define VALUE 10

/* MAIN PROGRAM */
/*
 * main:content of main write here
*/
int main()

{
	int chars;
	int index=0;
	char str[100];
	printf("enter characters:\n");
	//To get characters from user until end of file
	while((chars=getchar())!=EOF){
		str[index++]=chars;
	}
	str[index]='\0';
 int i;
    int space_detected = 0; // Flag to detect space or tab sequence

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            if (!space_detected) {
                putchar('\n');
                space_detected = 1; // Set flag when a space or tab is detected
            }
        } else {
            putchar(str[i]);
            space_detected = 0; // Reset flag when a non-space character is detected
        }
    }

    return 0;
}


/*End of main()*/
