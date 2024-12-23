#include <stdio.h>
#include <assert.h>

int main() {
    // Try to open a file for reading
    FILE *file = fopen("example.txt", "r");

    // Use assert to check if the file opened successfully
    assert(file != NULL);

    printf("File opened successfully.\n");

    // Close the file
    fclose(file);

    return 0;
}

