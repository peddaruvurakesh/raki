/*This program is to modify the temperature conversion program to print a heading above the table. 
Author       :rakesh
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
/*MACRO DEFINITIONS*/
#define VALUE 10

/* MAIN PROGRAM */
/*
 * main:Accepts fahrenheit values and converts into celsius
 */
int main()
{
	//fahrenheit to celsius
	float fahren;
	float celsius;
	/** converting fahrenheit to celsius*/
	printf(" -----------------------------------\n");
	printf("|    fahrenheit to celsius table    |\n");
	printf(" -----------------------------------\n");
	for(fahren=0;fahren<100;fahren=fahren+VALUE){
		//calculating celsius
		celsius=(fahren-32)*5.0/9.0;
	printf("|          %2.0f - %6.2f              |\n",fahren,celsius);
	}
	printf(" -----------------------------------\n");
}
/* End of main() */

