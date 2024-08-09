/* This program is to write the function itob(n,s,b) that converts the integer n into a base bcharacter representation in the string s. In particular, 
 * itob(n,s,16) formats s as a hexadecimal integer in s. 
 * Author: rakesh
 * Created: 8 July, 2024
 * Modified:8 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
/** MACRO DEFINITIONS */
#define WORDS 100
/** FUNCTION PROTOTYPES */
void my_itob(int n, char s[],int);
void reverse(char s[]);
/** MAIN PROGRAM */
/** main: Accepts integer and converts into binary*/
int main(){
	int n,b;
	printf("enter number\n");
	scanf("%d",&n);

	printf("enter base\n");
	scanf(" %d",&b);
	if(b<0){
		printf("enter a valid base value\n");
		return 1;
	}
	char s[WORDS];
	//calling my_itob function 
	my_itob(n,s,b);
	printf("%s\n",s);
}
/* End main() */
void my_itob(int n, char s[],int b)
{
	int i, sign;
	unsigned int num;

	num=n;
	i = 0; do { /* generate digits in reverse order */
		int remainder = num % b;
		s[i++] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
		num /= b;
	} while (num > 0);
	s[i] = '\0';
	reverse(s);
}
/*End of my_itob*/
/*reverse():it reverses the obtained string*/
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
/*End of reverse()*/
