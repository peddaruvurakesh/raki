/*Question7-9
Functions like isupper can be implemented to save space or to save time. Explore both possibilities. 

Explanation
The question explores the trade-off between space efficiency and time efficiency when implementing functions like isupper.

 

The isupper function in C is used to check whether a given character is an uppercase letter. It is part of the ctype.h header file, which provides functions for character classification and conversion*/
/*
AUTHOR : rakesh peaddruvu
created date :08/12/2024
modified date :08/12/2024
*/


//HEADDER FILES
#include <stdio.h>
#include <ctype.h>
#include <time.h>

// Space-efficient implementation of isupper
int isUpperSpace(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Time-efficient implementation of isupper (uses built-in library)
int isUpperTime(char c) {
    return isupper(c);
}
//MAIN FUNCTION
int main() {
    char testChar = 'A'; // Test character
    int iterations = 1000000; // Number of iterations for benchmarking
    clock_t start, end; // For measuring time
    double timeSpace, timeTime;

    // Measure time for space-efficient implementation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        isUpperSpace(testChar);
    }
    end = clock();
    timeSpace = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Measure time for time-efficient implementation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        isUpperTime(testChar);
    }
    end = clock();
    timeTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("Space-efficient time: %.6f seconds\n", timeSpace);
    printf("Time-efficient time: %.6f seconds\n", timeTime);

    return 0;
}

