/*   search and replace in text file (in the same file it should be modified)  
* author : Rakesh Peddaruvu
* created date : 08/10/2024
* modified date : 08/10/2024
*/

/*HEADDERFILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* MACROS DEFINATIONS*/
#define BUFFER_SIZE 1000

void replaceWordInFile(const char* filePath, const char* oldWord, const char* newWord) {
    FILE *file, *tempFile;
    char buffer[BUFFER_SIZE];
    char *pos;

    // Open the file for reading
    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filePath);
        return;
    }

    // Open a temporary file to store the modified content
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Could not open temporary file\n");
        fclose(file);
        return;
    }

    // Read the file line by line and replace the word
    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL) {
        // Search for the occurrence of the old word in the current line
        while ((pos = strstr(buffer, oldWord)) != NULL) {
            // Write the part before the old word
            fwrite(buffer, sizeof(char), pos - buffer, tempFile);
            // Write the new word
            fwrite(newWord, sizeof(char), strlen(newWord), tempFile);
            // Move the buffer pointer to the end of the old word and continue processing
            strcpy(buffer, pos + strlen(oldWord));
        }
        // Write the remaining part of the line
        fputs(buffer, tempFile);
    }

    // Close both files
    fclose(file);
    fclose(tempFile);

    // Replace the original file with the modified one
    remove(filePath);
    rename("temp.txt", filePath);

    printf("The word '%s' has been replaced with '%s' successfully.\n", oldWord, newWord);
}
/* MAIN FUNCTION */
int main() {
    char filePath[100], oldWord[100], newWord[100];

    // Get file name and words from the user
    printf("Enter the file path: ");
    scanf("%s", filePath);
    printf("Enter the word to replace: ");
    scanf("%s", oldWord);
    printf("Enter the new word: ");
    scanf("%s", newWord);

    // Call the function to replace the word in the file
    replaceWordInFile(filePath, oldWord, newWord);

    return 0;
}
/* END MAIN */
