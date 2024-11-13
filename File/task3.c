#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the word contains digits
int containsDigits(const char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (isdigit(word[i])) {
            return 1; // Return 1 if a digit is found
        }
    }
    return 0; // Return 0 if no digits are found
}

// Function to replace a word in a file
void replaceWordInFile(const char* filename, const char* oldWord, const char* newWord) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Temporary file to store modified content
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temp file.\n");
        fclose(file);
        return;
    }

    char buffer[1000];

    // Read file line by line
    while ((fgets(buffer, 1000, file)) != NULL) {
        // Replace occurrences of oldWord with newWord
        char *pos = strstr(buffer, oldWord);
        if (pos != NULL) {
            while (pos != NULL) {
                // Write everything before the oldWord
                fwrite(buffer, 1, pos - buffer, tempFile);
                
                // Write the new word
                fprintf(tempFile, "%s", newWord);

                // Move the buffer pointer to after the oldWord
                buffer[0] = '\0'; // Reset buffer
                strcpy(buffer, pos + strlen(oldWord));

                pos = strstr(buffer, oldWord);
            }
        }
        // Write the rest of the buffer
        fprintf(tempFile, "%s", buffer);
    }

    fclose(file);
    fclose(tempFile);

    // Replace original file with modified content
    remove(filename);
    rename("temp.txt", filename);

    printf("Replacement complete.\n");
}

int main() {
    char filename[100], oldWord[100], newWord[100];

    // Ask the user for the filename, old word, and new word
    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the word to replace: ");
    scanf("%s", oldWord);

    while (1) {
        printf("Enter the new word: ");
        scanf("%s", newWord);

        // Check if the new word contains digits
        if (containsDigits(newWord)) {
            printf("The new word contains digits. Please enter a word without digits.\n");
        } else {
            break;
        }
    }

    // Replace the word in the file
    replaceWordInFile(filename, oldWord, newWord);

    return 0;
}

