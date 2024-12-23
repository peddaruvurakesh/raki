/*Question7-8
Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file. 

Explanation
The task requires writing a program that prints the contents of multiple files, starting each new file on a new page. Additionally, each page should have a title and a running page count.*/




/*
AUTHOR : rakesh peaddruvu
created date :08/12/2024
modified date :08/12/2024
*/



//HEADDER FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for line length and number of lines per page
#define LINELENGTH 80
#define LINESPERPAGE 10

// Function prototype to print pages
void printpages(FILE *, FILE *);

/*
 * Main function:
 * - Accepts file names as command-line arguments.
 * - Prints the content of each file to `stdout` with page breaks after every 10 lines.
 * - If no files are specified, reads input from `stdin`.
 */
int main(int argc, char *argv[]) {
    FILE *fp;
    char *prog = argv[0];

    if (argc == 1) { // No arguments provided; process `stdin`
        fprintf(stderr, "No files given.\n");
        printpages(stdin, stdout);
    } else {
        // Process each file specified as a command-line argument
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                // Print the file name and process the file
                fprintf(stdout, "\n\n\t\t\tFile: %s\n\n", *argv);
                printpages(fp, stdout);
                fclose(fp);
            }
        }
    }

    // Check for errors while writing to `stdout`
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

/*
 * Function `printpages`:
 * - Reads a file and prints its content to the specified output stream.
 * - Adds page breaks after every 10 lines.
 * - Displays the page number at the end of each page.
 */
void printpages(FILE *ifp, FILE *ofp) {
    int c;      // Character read from the file
    int line = 0; // Current line count
    int pg = 1;  // Current page number

    while ((c = getc(ifp)) != EOF) { // Read each character from the file
        putc(c, ofp); // Print the character to the output stream
        if (c == '\n') { // Increment line count on newline
            line++;
            if (line == LINESPERPAGE) { // Check if page limit is reached
                fprintf(stdout, "\n\t\t\tPage %d End.\n\n", pg);
                pg++;  // Increment page number
                line = 0; // Reset line count for the next page
            }
        }
    }
}

