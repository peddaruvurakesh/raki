#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *c;
    int fd, sz, i;

    // Allocate memory and check for success
    c = (char *)calloc(100, sizeof(char));
    if (c == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Open the file with read-only access
    fd = open("in1", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file 'in1'");
        free(c);
        exit(1);
   }

    // Read the first 10 bytes
    sz = read(fd, c, 10);
    if (sz < 0) {
        perror("Read error");
        close(fd);
        free(c);
        exit(1);
    }
    printf("Opened 'in1' and called read(%d, c, 10).\n", fd);
    printf("It returned that %d bytes were read.\n", sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);

    // Check current offset using lseek with SEEK_CUR
    i = lseek(fd, 0, SEEK_CUR);
    if (i == -1) {
        perror("lseek error");
        close(fd);
        free(c);
        exit(1);
    }
    printf("lseek(%d, 0, SEEK_CUR) returns current offset of the file as %d\n\n", fd, i);

    // Seek to the beginning and read again
    lseek(fd, 0, SEEK_SET);
    sz = read(fd, c, 10);
    c[sz] = '\0';
    printf("After seeking to beginning, read returns the following bytes: %s\n", c);

    // Move back by 6 bytes from the current position
    printf("Now, we do lseek(%d, -6, SEEK_CUR). It returns %d\n", fd, lseek(fd, -6, SEEK_CUR));
    sz = read(fd, c, 10);
    c[sz] = '\0';
    printf("The read after seeking -6 bytes returns the following bytes: %s\n", c);

    // Attempt to seek to an invalid position (-1 from start)
    printf("Finally, we do lseek(%d, -1, SEEK_SET). This returns -1.\n", fd);
    fflush(stdout);
    i = lseek(fd, -1, SEEK_SET);
    perror("lseek error");

    close(fd);
    free(c);
    return 0;
}

