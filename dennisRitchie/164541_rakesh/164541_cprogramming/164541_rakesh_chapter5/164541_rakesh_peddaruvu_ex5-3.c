/*
 * This program implements a pointer version of the `strcat` function.
 * The `strcat` function concatenates the string `t` to the end of `s`.
 * Author: Rakesh
 * Created: 25 July, 2024
 * Modified: 26 July, 2024
 */

/*
 * SAMPLE INPUT AND OUTPUT
 
Enter the first string: hello
Enter the second string: world

Before concatenation:
s: hello
t: world

After concatenation:
s: helloworld 
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
#include "error_handling.h"
#include <string.h>

#include <stdio.h>

/* strcat: concatenate string t to the end of string s */
void my_strcat(char s[], const char t[]) {
    int i = 0, j = 0;

    // Find the end of the string `s`
    while (s[i] != '\0') {
        i++; // Move to the end of `s`
    }

    // Copy characters from `t` to `s`
    while (t[j] != '\0') {
        s[i++] = t[j++]; // Append `t[j]` to `s` and move indices
    }

    s[i] = '\0'; // Null-terminate the concatenated string
}

int main() {
    char s[100]; // Array large enough to hold both strings
    char t[50];

    // Input the first string
    printf("Enter the first string: ");
    fgets(s, sizeof(s), stdin);

    // Remove the newline character if present
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        i++;
    }

    // Input the second string
    printf("Enter the second string: ");
    fgets(t, sizeof(t), stdin);

    // Remove the newline character if present
    i = 0;
    while (t[i] != '\0') {
        if (t[i] == '\n') {
            t[i] = '\0';
            break;
        }
        i++;
    }

    // Display strings before concatenation
    printf("\nBefore concatenation:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Concatenate `t` to `s`
    my_strcat(s, t);

    // Display the result after concatenation
    printf("\nAfter concatenation:\n");
    printf("s: %s\n", s);

    return 0;
}

