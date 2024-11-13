#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIFF_LINES 10
#define BUFFER_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening one of the files.\n");
        return 1;
    }

    char line1[BUFFER_SIZE], line2[BUFFER_SIZE];
    int lineNumber = 0, diffCount = 0;
    
    while (fgets(line1, BUFFER_SIZE, file1) != NULL && fgets(line2, BUFFER_SIZE, file2) != NULL) {
        lineNumber++;

        if (strcmp(line1, line2) != 0) {
            printf("Difference at line %d:\n", lineNumber);
            printf("File 1: %sFile 2: %s\n", line1, line2);
            diffCount++;

            if (diffCount == MAX_DIFF_LINES) {
                printf("More than %d differences found. Stopping comparison.\n", MAX_DIFF_LINES);
                break;
            }
        }
    }

    if (diffCount == 0) {
        printf("The files are identical.\n");
    }

    fclose(file1);
    fclose(file2);

    return 0;
}

