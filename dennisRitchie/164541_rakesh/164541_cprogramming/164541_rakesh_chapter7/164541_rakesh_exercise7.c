/*Question7-7
Modify the pattern finding program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments, from the standard input. Should the file name be printed when a matching line is found?

Explanation
The task is to modify a pattern-finding program so that it can search for a specified pattern in a set of named files or, if no files are specified, in the standard input (stdin). Additionally, when a matching line is found in a file, the program should print the file name along with the line number and the matching line. If no files are named, the program should search stdin and print the matching lines with "stdin" as the file name*/

/*
AUTHOR : rakesh peaddruvu
created date :08/12/2024
modified date :08/12/2024
*/

// HEADDER FILES 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

void searchPatternInFile(const char *pattern, FILE *file, const char *filename, int *found) {
    char line[MAX_LINE_SIZE];
    int line_number = 1;

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("%s:%d:%s", filename, line_number, line);
            (*found)++;
        }
        line_number++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pattern> [file1 file2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pattern = argv[1];
    int found = 0;

    if (argc == 2) {
        // No files provided, read from stdin
        printf("Reading from stdin (press Ctrl+D to end input):\n");
        searchPatternInFile(pattern, stdin, "stdin", &found);
    } else {
        // Loop through each file argument
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "Error: Could not open file '%s'\n", argv[i]);
                continue;
            }
            searchPatternInFile(pattern, file, argv[i], &found);
            fclose(file);
        }
    }

    if (found == 0) {
        printf("No matching lines found.\n");
    }

    return 0;
}

