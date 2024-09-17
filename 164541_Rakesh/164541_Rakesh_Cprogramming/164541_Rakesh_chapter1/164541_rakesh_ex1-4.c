/*This program is to print the corresponding Celsius to Fahrenheit table. 

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
 * main:Accepts celsius values and converts into fahrenheit table
 */
int main(){

	//converts celsius to fahrenheit
	printf("celsius to fahrenheit\n");
	float fahrenheit,celsius;
                //calculating fahrenheit 
		scanf("%f",&celsius);
		fahrenheit=(9.0/5.0*celsius)+32.0;


		printf("%2.2f c - %3.0f f\n",celsius,fahrenheit);
	}
/* End of main() */
