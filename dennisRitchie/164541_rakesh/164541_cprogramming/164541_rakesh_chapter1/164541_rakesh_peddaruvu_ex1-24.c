/** This program is to check a C program for rudimentary syntax errors like unmatched parentheses, brackets, braces, quotes, comments, etc. It handles single-line comments, multi-line comments, and skips escape sequences inside quotes. 
 * Author: rakesh
 * Created: 11 July, 2024
 * Modified:11 July, 2024
 */
/** REQUIRED HEADER FILES **/
#include <stdio.h>

/** MACRO DEFINITIONS **/
#define TRUE (1 == 1)
#define FALSE !TRUE
#define MAX 500
/** MAIN PROGRAM */
/** main: Accepts input and checks parentheses, brackets, braces, comments, and quotes */
int main() {
    char cCharacter, sStr[MAX], sno_com_str[MAX];
    int iCount= 0;

    /* To get input from user*/
    while ((cCharacter = getchar()) != EOF) {
        sStr[iCount++] = cCharacter;
    }
    /*Null terminatig the string */
    sStr[iCount]='\0';
	/* Initializing values*/
    int iline_comment = FALSE, iblock_comment = FALSE;
    int iparentheses = 0, ibrackets = 0, ibraces = 0;
    int isingle_quote = FALSE, idouble_quote = FALSE, iescape = FALSE;
    int istart_2 = 0, istart_1 = 0, iminimum = 0;

    while (sStr[iminimum] != '\0') {
        /* Skip characters inside single quotes or double quotes */
        if (iescape) {
            iescape = FALSE;  
	    /* Ignore the next character after a backslash */
        } else if (sStr[iminimum] == '\\') {
            iescape = TRUE;   
	    /* Detect escape sequence */
        } else if (!iblock_comment && !iline_comment && !isingle_quote && sStr[iminimum] == '\'') {
            isingle_quote = !isingle_quote;
        } else if (!iblock_comment && !iline_comment && !idouble_quote && sStr[iminimum] == '\"') {
            idouble_quote = !idouble_quote;
        } else if (isingle_quote || idouble_quote) {
            /* Inside a quote, no need to check for braces or parentheses */
        } else if (!iblock_comment && !iline_comment) {
            if (sStr[iminimum] == '(') {
                ++iparentheses;
            } else if (sStr[iminimum] == ')') {
                --iparentheses;
            } else if (sStr[iminimum] == '{') {
                ++ibraces;
            } else if (sStr[iminimum] == '}') {
                --ibraces;
            } else if (sStr[iminimum] == '[') {
                ++ibrackets;
            } else if (sStr[iminimum] == ']') {
                --ibrackets;
            } else if (sStr[iminimum] == '/' && sStr[iminimum + 1] == '/') {
                iline_comment = TRUE;
                iminimum++;
            } else if (sStr[iminimum] == '/' && sStr[iminimum + 1] == '*') {
                iblock_comment = TRUE;
                iminimum++;
            }
        }

        if (iblock_comment && sStr[iminimum] == '*' && sStr[iminimum + 1] == '/') {
            iblock_comment = FALSE;
            iminimum++;
        } else if (iline_comment && sStr[iminimum] == '\n') {
            iline_comment = FALSE;
        }

        /* Add to no_com_str if not in a comment */
        if (!iblock_comment && !iline_comment) {
            sno_com_str[istart_2++] = sStr[iminimum];
        }

        iminimum++;
    }

    sno_com_str[istart_2] = '\0';

    /* Check for unmatched parentheses, braces, brackets, quotes */
    if (iparentheses != 0) {
        printf("Parentheses error\n");
    }
    if (ibraces != 0) {
        printf("Braces error\n");
    }
    if (ibrackets != 0) {
        printf("Brackets error\n");
    }
    if (isingle_quote) {
        printf("Unmatched single quote\n");
    }
    if (idouble_quote) {
        printf("Unmatched double quote\n");
    }
    if (iblock_comment) {
        printf("Unclosed block comment\n");
    }

    /* print string without comments */
    printf("Code without comments:\n%s\n", sno_com_str);

    return 0;
}

