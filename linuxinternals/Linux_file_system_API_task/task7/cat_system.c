#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For read() and write()

int main(int argc, char **argv) {
    int bufsize = 4096; // Default buffer size (4KB)
    char *buffer;
    int bytesRead;

    // Dynamically allocate memory for the buffer
    buffer = malloc(bufsize);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    // Read from standard input and write to standard output
    while ((bytesRead = read(STDIN_FILENO, buffer, bufsize)) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    free(buffer);
    return 0;
}

