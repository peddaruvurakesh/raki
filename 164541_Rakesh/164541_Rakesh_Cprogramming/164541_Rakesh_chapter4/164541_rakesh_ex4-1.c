/*
 * This program is to write a function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none. 

 * Author: Rakesh Peddaruvu
 * Created: 8 July, 2024
 * Modified:11 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include"error_handling.h"
/** MACRO DEFINITIONS*/
#define RANGE 100
/** FUNCTION PROTOTYPES */
int strindex(char[],char[]);

/* Main Program */
/* main(): finds the occurence of string and prints its index */
int main() {
    char str[RANGE], t[RANGE];
    int value, val;
    char ch, c;

    /* do-while loop: to repeat the loop based on condition */
    do {
	    /*initialization*/
        value = 0;
        val = 0;
        /*Entering main first string s */
        printf("Enter the main string: ");
        while ((ch = getchar()) != EOF && ch != '\n') {
            /* Error handling: if given range is more */
            if (value < RANGE - 1) {
                str[value++] = ch;
            } else {
                /* Handle error */
                printf("Error: Input string exceeds range.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                /* Clear input buffer */
                return 0;
            }
        }
        str[value] = '\0';  // Null-terminate the string
        /* Entering second string t */
        printf("Enter the substring to match: ");
        while ((ch = getchar()) != EOF && ch != '\n') {
            if (val < RANGE - 1) {
                t[val++] = ch;
            } else {
                printf("Error: Substring exceeds range.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                return 0;
            }
        }
        t[val] = '\0';  // Null-terminate the substring

        /* Calling strindex function to find rightmost index */
        int index = strindex(str, t);
        if (index != -1) {
            printf("Substring \"%s\" found in \"%s\" at position: %d\n", t, str, index);
        } else {
            printf("Match not found in the string.\n");
        }
        /*To do and check another time*/
        printf("Do you want to find another substring in a string? (y / n): ");
        scanf(" %c", &c);
        while ((ch = getchar()) != '\n' && ch != EOF);

    } while (c == 'y' || c == 'Y');
    /* End of do-while */
}
/* End of main() */
/* strindex function to find the rightmost occurrence of a substring in a string */
int strindex(char s[], char t[]) {
    int i, j, k;
    /* strlen : it is used to find length of string */
    int slen = strlen(s);
    int tlen = strlen(t);
    for (i = slen - tlen; i >= 0; i--) {
        for (j = i, k = 0; k < tlen && tolower(s[j]) == tolower( t[k]); j++, k++);
        if (k == tlen) {
		/*return index */
            return i+1;
        }
    }

    /* If substring is not found */
    return -1;
}
/* End of strindex()*/

