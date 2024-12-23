#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "file_with_hole.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC , 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Move the file offset 4KB ahead
    if (lseek(fd, 4096, SEEK_SET) == -1) {
        perror("Error seeking");
        close(fd);
        return 1;
    }

    // Write a single byte at the new position to create the hole
    if (write(fd, "", 1) == -1) {
        perror("Error writing");
        close(fd);
        return 1;
    }

    close(fd);
    printf("File with 4KB hole created successfully.\n");
    return 0;
}

