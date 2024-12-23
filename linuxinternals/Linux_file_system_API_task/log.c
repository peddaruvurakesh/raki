#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define logfile "/home/rakesh/linux_internals/logfile"

void write_to_fill_log() {
    char *username;
    long t;
    int fd;
    FILE *f;

    username = getenv("USER");
    t = time(0);

    // Open the log file using open() with O_APPEND and O_SYNC flags
    fd = open(logfile,O_CREAT | O_WRONLY | O_APPEND | O_SYNC, 0644);
    if (fd < 0) {
        perror("Failed to open log file");
        return;
    }

    // Use fdopen to get a FILE* stream from the file descriptor
    f = fdopen(fd, "a");
    if (f == NULL) {
        perror("Failed to open file stream");
        close(fd);
        return;
    }

    // Write username and timestamp to the log file
    fprintf(f, "%s %ld\n", username, t);

    // Close the file stream and the file descriptor
    fclose(f);  // This will also close the fd from fdopen
}

int main() {
    write_to_fill_log();
    return 0;
}

