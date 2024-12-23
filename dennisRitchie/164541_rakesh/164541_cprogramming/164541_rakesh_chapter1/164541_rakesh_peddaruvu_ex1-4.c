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
	float fFahrenheit,fCelsius;
                //calculating fahrenheit 
		scanf("%f",&fCelsius);
		fFahrenheit=(9.0/5.0*fCelsius)+32.0;

                                      
	
		printf("%2.0f c - %3.1f f\n",fCelsius,fFahrenheit);
	}                          
/* End of main() */
