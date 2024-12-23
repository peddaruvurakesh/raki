/**
 * Program Name: Day of the Year Calculator
 * Author: Rakesh Peddaruvu
 * Date: 28/11/2024
 * 
 * Description:
 * This program calculates the day of the year for a given date (day, month, year).
 * It considers leap years for accurate calculations and validates the input.
 * If the input is invalid (e.g., incorrect month or day), it returns an error message.
 * 
 * Functions:
 * - `day_of_year`: Calculates the day of the year based on the provided date.
 * - `main`: Reads user input and calls `day_of_year` to compute the result.
 * 
 * Sample Input:
 *   Enter day, month, and year: 15 8 2024
 * 
 * Sample Output:
 *   day of the year: 228
 * 
 * Error Examples:
 *   Enter day, month, and year: 30 2 2023
 *   Output: Error: the 2 month has a maximum of 28 days.
 *   
 *   Enter day, month, and year: 32 1 2022
 *   Output: Error: the 1 month has a maximum of 31 days.
 * 
 */

#include <stdio.h>

// Static table of days in months for regular and leap years
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Regular year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // Leap year
};

// Function prototypes
int day_of_year(int year, int month, int day);

int main(void) {
    int d, m, y;
    printf("Enter day, month, and year: ");
    scanf("%d %d %d", &d, &m, &y);

    int day = day_of_year(y, m, d);
    if (day != -1) { // Valid date
        printf("day of the year: %d\n", day);
    }
    return 0;
}

/**
 * Function: day_of_year
 * Description: Computes the day of the year for the given data
 * Returns:
 *   - The day of the year (1-366) if the input is valid.
 *   - -1 or -2 for invalid input with an error message.
 */
int day_of_year(int year, int month, int day) {
    // Determine if the year is a leap year
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // Validate month
    if (month > 12 || month < 1) {
        printf("Invalid Entry!!\n");
        return -1;
    }

    // Validate day
    if (day > daytab[leap][month] || day < 1) {
        printf("Error: the %d month has a maximum of %d days.\n", month, daytab[leap][month]);
        return -2;
    }

    // Calculate the day of the year
    for (int i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

