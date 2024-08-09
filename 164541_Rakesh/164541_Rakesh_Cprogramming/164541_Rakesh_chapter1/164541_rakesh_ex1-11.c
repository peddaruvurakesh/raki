/* This program is to test the word count program. What kinds of input are most likely to uncover bugs if there are any?
 
Name         : rakesh
Created Date : 24-06-2024
Modified date: 24-06-2024
*/

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include "error_handling.h" // Assuming this is a custom header file for error handling


/* MAIN PROGRAM */
/*
 * main: content of main write here to test the word count program
 */

int main() {
    char ch;
        int word_count = 0, char_count = 0;
        int character = 0;
        int in_word = 0;

       printf("enter input\n");

        // Read characters until newline or EOF
        while ((character = getchar()) != EOF) {
            char_count++;

            // Count the words
            if (character == ' ' || character == '\t' || character == '\n') {
                if (in_word) {
                    word_count++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }

        // If the last character is part of a word, count it
        if (in_word) {
            word_count++;
        }

        printf("Word count: %d\n", word_count);


    return 0;
}
/* End of main() */
