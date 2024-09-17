/*This program is to  modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. 
 
Name         :rakesh
Created Date :24-06-2024
Modified date:24-06-2024
 */
/*REQUIRED HEADER FILES*/
#include<stdio.h>
/*MACRO DEFINITIONS*/
#define VALUE 300
#define STEPS 40

/* MAIN PROGRAM */
/*
 * main:converts temperature from 300 degrees to 0 degrees.
*/
int main(){
float celsius;
float fahrenheit;
	printf(" -----------------------------------\n");
	printf("|    CELSIUS TO FAHRENHEIT TABLE    |\n");
	printf(" -----------------------------------\n");
	
for(celsius=VALUE;celsius>=0;celsius=celsius-STEPS){
	//calculating celsius 
		fahrenheit=(9.0/5.0*celsius)+32.0;

	printf("|       %3.0f c - %3.0f f               |\n",celsius,fahrenheit);
	}
	printf(" -----------------------------------\n");
}
