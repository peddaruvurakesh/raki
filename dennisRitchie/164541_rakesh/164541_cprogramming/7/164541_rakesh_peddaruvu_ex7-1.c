/* This program is to Write a program that converts upper case to lower or lower case to upper, depending on the name it is invoked with, as found in argv[0].
 *Author: rakesh
* Created: 29,Aug 2024
* Modified:29,Aug 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/** MAIN PROGRAM */
/* lower/upper: convert input to lower/upper case */
int main(int argc, char *argv[]) {
    int ivar;
    char *pProgram_name;
	/* checking command line arguments */
    if (argc > 1) {
        printf("Usage: ./lower or ./upper\n");
        return 1;
    }

    pProgram_name = argv[0];

    if (strcmp(pProgram_name, "./lower") ==0) {
        /* Convert to lowercase */
        while ((ivar = getchar()) != EOF) {
            putchar(tolower(ivar));
        }
    } else if (strcmp(pProgram_name, "./upper") ==0) {
        /* Convert to uppercase */
        while ((ivar = getchar()) != EOF) {
            putchar(toupper(ivar));
        }
    } else {
        printf("Unknown program name. Use 'lower' or 'upper' in the program name.\n");
        return 1;
    }

    return 0;
}

/* End main() */
