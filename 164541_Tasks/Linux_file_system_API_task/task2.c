#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("Error opening source file");
        return 1;
    }

    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("Error opening destination file");
        close(src);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src);
            close(dest);
            return 1;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    close(src);
    close(dest);

    if (bytes_read == -1) {
        return 1;
    }

    printf("File copied successfully.\n");
    return 0;
}

