/*
 * This program rewrites the temperature conversion program from Section 1.2 to use a function for conversion.
 * The program takes temperature in Celsius and converts it to Fahrenheit.
 *
 * Author: Rakesh
 * Created: 25 June, 2024
 * Modified: 25 June, 2024
 *
 * SAMPLE INPUT:
 *   Enter temperature in Celsius:
 *   C = 100
 *
 * SAMPLE OUTPUT:
 *   F = 212
 *
 * FUNCTION PARAMETERS:
 *   - `temp_Conv(int icelsius)`: Accepts an integer `icelsius` representing the temperature in Celsius.
 *     Returns the equivalent temperature in Fahrenheit as an integer.
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** MACRO DEFINITIONS */
#define MAX 100

/** FUNCTION PROTOTYPES */
int temp_Conv(int icelsius);  /* Converts Celsius to Fahrenheit */

/** MAIN PROGRAM */
/** main: Accepts input from the user and calls `temp_Conv()` for conversion */
int main() {
    int ifahrenheit, icelsius;  // Variables to store Fahrenheit and Celsius temperatures
    char sInput[MAX];  // Buffer to store user input

    /* Prompt user for temperature in Celsius */
    printf("C = ");
    scanf("%s", sInput);

    /* Validate if input is a number */
    for (int ivar = 0; sInput[ivar] != '\0'; ivar++) {
        if (!isdigit(sInput[ivar])) {
            printf("Please enter a valid number\n");
            return 1;  // Exit the program if the input is not a number
        }
    }

    /* Convert input string to an integer */
    icelsius = atoi(sInput);

    /* Call the function to convert Celsius to Fahrenheit */
    ifahrenheit = temp_Conv(icelsius);

    /* Print the result */
    printf("F = %d\n", ifahrenheit);

    return 0;
}

/* End of main() */

/** temp_Conv(): Converts Celsius to Fahrenheit */
/*
 * Parameters:
 *   - `icelsius`: The temperature in Celsius (as an integer).
 * Returns:
 *   - The equivalent temperature in Fahrenheit (as an integer).
 */
int temp_Conv(int icelsius) {
    return (9 * icelsius) / 5 + 32;  // Using integer division to calculate Fahrenheit
}

/* End of temp_Conv() */

