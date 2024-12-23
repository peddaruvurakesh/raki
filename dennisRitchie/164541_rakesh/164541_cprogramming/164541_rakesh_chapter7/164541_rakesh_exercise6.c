/*Question7-6
Write a program to compare two files, printing the first line where they differ. 

Explanation
The task is to write a program that compares two files line by line and prints the first line where they differ. If the files are identical, the program should indicate that. If the files have different lengths, it should also detect and report that.*/






/*
AUTHOR : rakesh peaddruvu
created date :07/12/2024
modified date :07/12/2024
*/



//HEADDER FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

void compare_files(const char *file1_path, const char *file2_path) {
    FILE *file1 = fopen(file1_path, "r");
    FILE *file2 = fopen(file2_path, "r");

    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error: Unable to open one or both files.\n");
        exit(EXIT_FAILURE);
    }

    char line1[MAX_LINE_SIZE];
    char line2[MAX_LINE_SIZE];
    int lineNum = 1;

    while (1) {
        char *line1_status = fgets(line1, MAX_LINE_SIZE, file1);
        char *line2_status = fgets(line2, MAX_LINE_SIZE, file2);

        if (line1_status == NULL || line2_status == NULL) {
            // Handle end of file cases
            if (line1_status == NULL && line2_status == NULL) {
                printf("Files are identical.\n");
            } else if (line1_status == NULL) {
                printf("Files have different lengths.\n[file1 ends at line %d.]\n", lineNum - 1);
            } else {
                printf("Files have different lengths.\n[file2 ends at line %d.]\n", lineNum - 1);
            }
            break;
        }

        // Compare lines
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", lineNum);
            printf("[file1.txt:] %s", line1);
            printf("[file2.txt:] %s", line2);
            break;
        }

        lineNum++;
    }

    fclose(file1);
    fclose(file2);
}
// MAIN FUNCTION
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    compare_files(argv[1], argv[2]);
    return 0;
}

