#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096  // Define a buffer size for efficiency

void cat(const char *filename) {
    int fd = open(filename, O_RDONLY);  // Open the file in read-only mode
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read and write in chunks until EOF
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("Error writing to stdout");
            close(fd);
            return;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading file");
    }

    close(fd);  // Close the file descriptor
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        cat(argv[i]);  // Call the custom `cat` function for each file
    }

    return 0;
}

