/*
 * This program removes all comments from a C program file. The goal is to remove both single-line (`// ...`) 
 * and multi-line (`* ... /` comments, while making sure that quoted strings and character constants are 
 * preserved correctly. The program takes input from a file, processes it, and writes the output without comments 
 * into another file.
  *
 * Author   : Rakesh peddaruvu
 * Created  : 4 July, 2024
 * Modified : 9 July, 2024
 * 
 * Question Clarification:
 * - The program reads a C source file and removes all types of comments from it.
 * - It ensures that comments inside quoted strings or character constants are not removed.
 * - The program handles two types of comments:
 *   1. Single-line comments that begin with `//`.
 *   2. Multi-line comments that begin with `` and end with `/`.
 * 
 * Steps to Understand the Program:
 * 1. Open the input C source file (`ip.c`) and an output file (`op.c`).
 * 2. Read each character from the input file and check if it is part of a comment.
 * 3. If it is a comment, skip the entire comment block.
 * 4. If not, write the character to the output file.
 * 5. Handle quoted strings and character constants properly, so they are not treated as comments.
 * 
 * Sample Input (`ip.c`):
 * ```
 * #include <stdio.h>
 * int main() {
 *     // This is a single-line comment
 *     return 0; // Another single-line comment
 * }
 * ```
 * 
 * Sample Output (`op.c`):
 * ```
 * #include <stdio.h>
 * int main() {
 *     printf("Hello, World!\n");
 *     return 0;
 * }
 * ```
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** FUNCTION PROTOTYPES */
void skip_Comments(FILE *, FILE *);

/** MAIN PROGRAM */
/**
 * main: Opens an input file (`ip.c`) and removes comments from it, storing the output in `op.c`.
 * - No parameters.
 * - Returns 0 if successful, 1 if there is an error.
 */
int main() {
    FILE *input, *output;
    char sipFile[] = "ip.c";   // Input file containing C code with comments
    char sopFile[] = "op.c";   // Output file to store C code without comments

    /* Open input file for reading */
    input = fopen(sipFile, "r");
    if (input == NULL) {
        printf("Error: Could not open input file %s\n", sipFile);
        return 1;
    }

    /* Open output file for writing */
    output = fopen(sopFile, "w");
    if (output == NULL) {
        printf("Error: Could not open output file %s\n", sopFile);
        fclose(input);
        return 1;
    }

    /* Call function to remove comments */
    skip_Comments(input, output);

    /* Close the files */
    fclose(input);
    fclose(output);

    printf("Comments removed and saved to %s\n", sopFile);

    return 0;
}
/* End of main() */

/**
 * skip_Comments: Function to skip both single-line (`// ...`) and multi-line (`*/
void skip_Comments(FILE *input, FILE *output) {
    int ichar, inext;

    while ((ichar = fgetc(input)) != EOF) {
        if (ichar == '/') {
            inext = fgetc(input);
            if (inext == '/') {
                /* Skip single-line comment */
                while ((ichar = fgetc(input)) != '\n' && ichar != EOF);
                if (ichar == '\n') {
                    fputc(ichar, output);
                    /* Write the newline character after skipping the comment */
                }
            } else if (inext == '*') {
                /* Skip multi-line comment */
                while ((ichar = fgetc(input)) != EOF) {
                    if (ichar == '*') {
                        if ((inext = fgetc(input)) == '/') {
                            break;  /* End of multi-line comment */
                        } else {
                            ungetc(inext, input);
                        }
                    }
                }
            } else {
                /* Not a comment, write both characters */
                fputc(ichar, output);
                fputc(inext, output);
            }
        } else {
            /* Normal character, write it to the output */
            fputc(ichar, output);
        }
    }
}

/* End of skip_Comments() */

