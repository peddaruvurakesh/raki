#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int bufsize = 4096; // Default buffer size (4KB)
    char *buffer;
    size_t bytesRead;

    // Dynamically allocate memory for the buffer
    buffer = malloc(bufsize);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    // Read from standard input and write to standard output using buffered I/O
    while ((bytesRead = fread(buffer, 1, bufsize, stdin)) > 0) {
        fwrite(buffer, 1, bytesRead, stdout);
    }

    free(buffer);
    return 0;
}

