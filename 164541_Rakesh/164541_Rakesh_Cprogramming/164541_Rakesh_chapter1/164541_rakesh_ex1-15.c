/*
* This program is to rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.
* Author: rakesh
* Created: 25 June, 2024
* Modified:25 June, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<ctype.h>
/** FUNCTION PROTOTYPES */
float conv(float);
/** MAIN PROGRAM */
/** main: Accepts */
int main()
{
	//fahrenheit to celsius
	//float c;
	int fahrenheit,celsius;
	printf("C =");
	scanf("%d",&celsius);
	if(!(isalnum(celsius))){
		printf("Please enter a valid number\n");
		return 1;
	}
         fahrenheit=conv(celsius);
		printf("F=%d\n",fahrenheit);
}
/* End main() */

/* conv():it converts fahrenheit to celsius*/
float conv(float celsius){
	
	float	fahrenheit=(9.0/5.0*celsius)+32.0;
		return fahrenheit;
	}
/* end of conv()*/
