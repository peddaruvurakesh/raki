#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    const char *directory_path = argv[1];
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    struct stat file;
    char full_path[1024];

    while ((entry = readdir(dir)) != NULL) {
        // Build the full path to the file
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        // Get file status
        if (stat(full_path, &file) == -1) {
            perror("stat");
            continue;
        }

        // Print the file name
        printf("%s: ", entry->d_name);

        // Determine and print the file type
        if (S_ISREG(file.st_mode)) {
            printf("Regular file\n");
        } else if (S_ISDIR(file.st_mode)) {
            printf("Directory\n");
        } else if (S_ISLNK(file.st_mode)) {
            printf("Symbolic link\n");
        } else if (S_ISCHR(file.st_mode)) {
            printf("Character device\n");
        } else if (S_ISBLK(file.st_mode)) {
            printf("Block device\n");
        } else if (S_ISFIFO(file.st_mode)) {
            printf("FIFO/pipe\n");
        } else if (S_ISSOCK(file.st_mode)) {
            printf("Socket\n");
        } else {
            printf("Unknown type\n");
        }
    }

    closedir(dir);
    return 0;
}

