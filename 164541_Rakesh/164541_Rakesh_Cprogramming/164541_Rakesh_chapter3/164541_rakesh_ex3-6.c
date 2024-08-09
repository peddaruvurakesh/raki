/*This program is to write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
* Author: rakesh
* Created: 9 July, 2024
* Modified:16 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
/** MACRO DEFINITIONS */
#define WORDS 100
/** FUNCTION PROTOTYPES */
void itoa(int n, char s[],int);
void reverse(char s[]);
/** MAIN PROGRAM */
/** main: */
int main(){
int number;
printf("enter a number\n");
scanf(" %d",&number);
int width;
printf("enter minimum field width\n");
scanf("%d",&width);
char s[WORDS];
itoa(number,s,width);
printf("%s\n",s);
}
/* End main() */
void itoa(int n, char s[],int min_width)
 {
	
 int i, sign;
 char sum[20];
 if ((sign = n) < 0) /* record sign */
 n = -n; /* make n positive */
 i = 0;
 do { 
/* generate digits in reverse order */
 s[i++] = n % 10 + '0'; 
 /* get next digit */
 } while ((n /= 10) > 0); /* delete it */
 if (sign < 0)
 s[i++] = '-';
 s[i] = '\0';
reverse(s);
     int len = strlen(s);
    if (len < min_width) {
        // Shift the characters to the right to make room for padding
        for (i = len; i >= 0; i--) {
            s[i + (min_width - len)] = s[i];
        }
    }
  
        // Add padding with blanks on the left
        for (i = 0; i < (min_width - len); i++) {
            s[i] = ' ';
        }
    
 }
/* End of itoa*/
/*reverse():To reverse the string*/
void reverse(char s[])
 {
 int c, i, j;
 char sum[20];
 for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
 c = s[i];
 s[i] = s[j];
 s[j] = c;
 }
 }
/*End of reverse()*/
