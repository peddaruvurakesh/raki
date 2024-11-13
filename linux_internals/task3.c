#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void display_file_type(const char *path, const char *filename) {
    struct stat file_stat;
    char full_path[1024];
    
    // Build the full path to the file
    snprintf(full_path, sizeof(full_path), "%s/%s", path, filename);

    // Get file status
    if (stat(full_path, &file_stat) == -1) {
        perror("stat");
        return;
    }

    // Determine the file type
    printf("%s: ", filename);
    if (S_ISREG(file_stat.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown type\n");
    }
}

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
    while ((entry = readdir(dir)) != NULL) {
        display_file_type(directory_path, entry->d_name);
    }

    closedir(dir);
    return 0;
}

