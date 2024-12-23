/*
 * This program demonstrates a function called `escape()` that converts certain special characters, like
 * newline (`\n`) and tab (`\t`), into their visible escape sequences (`\\n`, `\\t`) while copying a string.
 * It also works the other way, converting visible escape sequences back into the real characters.
 * 
 * Steps:
 * 1. Read a string input from the user.
 * 2. Call the `escape()` function to convert special characters to visible escape sequences.
 * 3. Print the converted string.
 * 
 * Sample Input:
 * Hello
 * World (newline character)
 * 
 * Sample Output:
 * Hello\nWorld
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 4 July, 2024
 * Modified : 4 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** Macro definitions */
#define CHAR 200  // Maximum character length for input strings

/** FUNCTION PROTOTYPES */
void escape(char[], char[]);

/** MAIN PROGRAM */
int main() {
    char s_Str[CHAR];    // Array to hold the converted string
    char s_tStr[CHAR];   // Array to hold the user input string
    char c_Ch;
    int iNum = 0;

    /* Read input string from user */
    while ((c_Ch = getchar()) != EOF) {
        s_tStr[iNum++] = c_Ch;  // Populate s_tStr with user input
    }
    s_tStr[iNum] = '\0';  // Null terminate the input string

    /* Call escape function to convert special characters to escape sequences */
    escape(s_Str, s_tStr);
    printf("%s", s_Str);  // Print the resulting string after conversion

    return 0;
}
/* End main */

/* escape(): converts characters like newline and tab into visible escape sequences like \n and \t */
void escape(char s[], char t[]) {
    int istart_1, istart_2;

    /* Iterate through each character in input string `t` */
    for (istart_1 = 0, istart_2 = 0; t[istart_1] != '\0'; istart_1++) {
        switch (t[istart_1]) {
            /* If the character is a newline, convert it to '\n' */
            case '\n':
                s[istart_2++] = '\\';
                s[istart_2++] = 'n';
                break;

            /* If the character is a tab, convert it to '\t' */
            case '\t':
                s[istart_2++] = '\\';
                s[istart_2++] = 't';
                break;

            /* By default, copy characters as they are */
            default:
                s[istart_2++] = t[istart_1];
                break;
        }
    }

    /* Null terminate the output string */
    s[istart_2] = '\0';
}
/* End escape() */

/*
 * Explanation:
 * - The `main()` function reads input from the user until EOF and stores it in `s_tStr`.
 * - The `escape()` function converts specific characters into their visible escape sequences
 *   and stores the result in `s_Str`.
 * - Finally, the converted string is printed.
 */

