/*
 * This program extends atof to handle scientific notation of the form 123.45e-6,
 * where a floating-point number may be followed by 'e' or 'E' and an optionally signed exponent.
 * 
 * Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 16 July, 2024
 *
 * Sample Input/Output:
 * 1.
 *   Input:
 *     Enter the number in scientific notation: 123.45e-6
 *   Output:
 *     x = 0.000123
 * 2.
 *   Input:
 *     Enter the number in scientific notation: 3.14e2
 *   Output:
 *     x = 314.000000
 * 3.
 *   Input:
 *     Enter the number in scientific notation: -7.5E+3
 *   Output:
 *     x = -7500.000000
 * 4.
 *   Input:
 *     Enter the number in scientific notation: 42
 *   Output:
 *     x = 42.000000
 */

/** REQUIRED HEADER FILES **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** MACRO DEFINITIONS **/
#define RANGE 100

/** FUNCTION PROTOTYPES **/
double my_atof(char *);

/** MAIN PROGRAM **/
/* main(): Accepts inputs and calls my_atof function to convert string to double */
int main() {
    double dvarx; // Variable to store the converted double value
    char sStr[RANGE], cCh; // Input string and character to continue or quit
    
    do {
        // Prompt user for input
        printf("Enter the number in scientific notation: ");
        
        // Read input using fgets for robustness
        if (fgets(sStr, RANGE, stdin) == NULL) {
            printf("Error reading input.\n");
            return 1; // Exit with an error code if input fails
        }
        
        // Remove trailing newline character, if present
        size_t len = strlen(sStr);
        if (len > 0 && sStr[len - 1] == '\n') {
            sStr[len - 1] = '\0';
        }

        // Convert string to double using my_atof()
        dvarx = my_atof(sStr);

        // Print the result
        printf("x = %lf\n", dvarx);

        // Ask the user if they want to check another string
        printf("Do you want to check another string? (y / n): ");
        scanf(" %c", &cCh);

        // Clear input buffer
        while (getchar() != '\n');

    } while (cCh == 'y' || cCh == 'Y'); // Repeat if user says 'y' or 'Y'

    return 0;
}
/* End of main() */

/* my_atof(): Converts a string to a double with support for scientific notation */
/* Author: Rakesh
 * Created: 8 July, 2024
 * Modified: 16 July, 2024
 */
double my_atof(char *pvar) {
    int ipos = 0; // Current index position in the string
    int iexp = 0; // Exponent value
    int isign = 1; // Sign of the number (1 for positive, -1 for negative)
    double dsum1 = 0; // Accumulator for integer part
    double dsum2 = 0; // Accumulator for fractional part
    double dfloat = 0.1; // Multiplier for fractional part

    // Handle optional sign (+ or -)
    if (pvar[ipos] == '-' || pvar[ipos] == '+') {
        if (pvar[ipos] == '-') {
            isign = -1; // Set sign to negative
        }
        ipos++;
    }

    // Convert integer part of the input
    while (pvar[ipos] != 'e' && pvar[ipos] != 'E' && pvar[ipos] != '.' && pvar[ipos] != '\0') {
        if (pvar[ipos] >= '0' && pvar[ipos] <= '9') {
            dsum1 = dsum1 * 10 + (pvar[ipos] - '0'); // Accumulate digit value
        } else {
            printf("Invalid character encountered: %c\n", pvar[ipos]);
            return 0; // Indicate an error
        }
        ipos++;
    }

    // Convert fractional part of the input (if present)
    if (pvar[ipos] == '.') {
        ipos++; // Move past the decimal point
        while (pvar[ipos] != 'e' && pvar[ipos] != 'E' && pvar[ipos] != '\0') {
            if (pvar[ipos] >= '0' && pvar[ipos] <= '9') {
                dsum2 = dsum2 + dfloat * (pvar[ipos] - '0'); // Accumulate fractional value
                dfloat *= 0.1; // Reduce the multiplier
            } else {
                printf("Invalid character encountered: %c\n", pvar[ipos]);
                return 0; // Indicate an error
            }
            ipos++;
        }
    }

    // Combine integer and fractional parts, considering the sign
    double dresult = (dsum1 + dsum2) * isign;

    // Handle scientific notation (if present)
    if (pvar[ipos] == 'e' || pvar[ipos] == 'E') {
        ipos++; // Move past 'e' or 'E'
        int esign = 1; // Exponent sign (1 for positive, -1 for negative)

        // Handle optional exponent sign
        if (pvar[ipos] == '-') {
            esign = -1; // Set exponent sign to negative
            ipos++;
        } else if (pvar[ipos] == '+') {
            ipos++;
        }

        // Convert exponent part
        while (pvar[ipos] != '\0') {
            if (pvar[ipos] >= '0' && pvar[ipos] <= '9') {
                iexp = iexp * 10 + (pvar[ipos] - '0'); // Accumulate exponent value
            } else {
                printf("Invalid character encountered: %c\n", pvar[ipos]);
                return 0; // Indicate an error
            }
            ipos++;
        }

        // Apply the exponent to the result
        dresult *= pow(10, esign * iexp);
    }

    // Return the final result
    return dresult;
}
/* End of my_atof() */

