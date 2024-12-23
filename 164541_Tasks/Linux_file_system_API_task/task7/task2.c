#include <stdio.h>
#include <stdlib.h>

// Function to display the contents of a file
void cat_file(FILE *file) {
    char buffer[1024]; // Buffer to hold each line of the file
    // Read each line from the file and print it to stdout
    while (fgets(buffer, sizeof(buffer), file)) {
        fputs(buffer, stdout); 
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // If no arguments (file names) are given, read from standard input (stdin)
        cat_file(stdin);
    } else {
        // Loop through each file passed as a command-line argument
        for (int i = 1; i < argc; i++) {
            // Open the file in read mode
            FILE *file = fopen(argv[i], "r");
            // Check if the file was opened successfully
            if (file == NULL) {
                perror(argv[i]); // Print an error message if the file can't be opened
                exit(EXIT_FAILURE); 
            }
            // Print the contents of the file
            cat_file(file);
            
            fclose(file);
        }
    }
    return 0; 
}

