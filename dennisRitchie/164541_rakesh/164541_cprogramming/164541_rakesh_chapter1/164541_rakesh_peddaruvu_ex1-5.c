/* 
 * This program modifies the temperature conversion program to print the 
 * Celsius to Fahrenheit table in reverse order, from 300 degrees to 0.
 * 
 * Name         : Rakesh
 * Created Date : 24-06-2024
 * Modified Date: 24-06-2024
 */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define VALUE 300    // Starting value of Celsius
#define STEPS 40     // Step size for decrementing Celsius

/* MAIN PROGRAM */
/*
 * main: Converts temperature from Celsius to Fahrenheit and prints the 
 * conversion table in reverse order.
 */
int main() {
    float fcelsius;       // Variable to store Celsius temperature
    float fFahrenheit;    // Variable to store corresponding Fahrenheit temperature

    // Print table header
    printf(" -----------------------------------\n");
    printf("|    CELSIUS TO FAHRENHEIT TABLE    |\n");
    printf(" -----------------------------------\n");

    // Loop to calculate and print temperature conversions from 300 to 0
    for (fcelsius = VALUE; fcelsius >= 0; fcelsius = fcelsius - STEPS) {
        // Calculate Fahrenheit from Celsius using the formula
        fFahrenheit = (9.0 / 5.0 * fcelsius) + 32.0;

        // Print the Celsius and corresponding Fahrenheit values
        printf("|       %3.0f c - %3.0f f               |\n", fcelsius, fFahrenheit);
    }

    // Print table footer
    printf(" -----------------------------------\n");

    return 0; // Return 0 to indicate successful completion
}
/* End of main */

