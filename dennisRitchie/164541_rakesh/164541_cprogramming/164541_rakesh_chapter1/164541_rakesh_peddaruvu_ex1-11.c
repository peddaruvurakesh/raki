/*
 * This program is to test the word count program. The goal is to determine
 * the robustness of the word counting logic by experimenting with different
 * types of input that could potentially uncover bugs.
 * 
 * Name         : Rakesh
 * Created Date : 24-06-2024
 * Modified Date: 24-06-2024
 */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include "error_handling.h" // Assuming this is a custom header file for error handling

/* MAIN PROGRAM */
/*
 * main: Reads input from the user, counts the number of words, lines, and characters.
 */
int main() {
    char cCh; // Placeholder character variable (not used further in this version)
    int iword_count = 0, ichar_count = 0; // Variables to store word count and character count
    int icharacter = 0; // Variable to hold each input character
    int iIn_word = 0, inew_line = 0; // Flags to track whether we are in a word and count the new lines

    // Prompt the user for input
    printf("Enter input (press CTRL+D to end):\n");

    /* Read characters until EOF */
    while ((icharacter = getchar()) != EOF) {
        ichar_count++; // Increment character count for each character read

        if (icharacter == '\n') {
            inew_line++; // Count new lines
        }

        /* Count words by checking for space, tab, or newline */
        if (icharacter == ' ' || icharacter == '\t' || icharacter == '\n') {
            if (iIn_word) {
                iword_count++; // If currently in a word and a delimiter is found, complete the word
                iIn_word = 0; // Reset in-word flag since we are no longer in a word
            }
        } else {
            iIn_word = 1; // Set in-word flag when a non-delimiter character is found
        }
    }

    /* If the last character is part of a word, count it */
    if (iIn_word) {
        iword_count++; // Count the last word if EOF occurs while still inside a word
    }

    /* Print the obtained data */
    printf("Lines: %d | Words: %d | Characters: %d\n", inew_line, iword_count, ichar_count);

    return 0; // Return 0 to indicate successful completion
}
/* End of main() */

