#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void print_file_type(struct stat *buf, const char *filename) {
    if (S_ISDIR(buf->st_mode)) {
        // If it's a directory, append "/"
        printf("%s/\n", filename);
    } else if (S_ISLNK(buf->st_mode)) {
        // If it's a symbolic link, append "@"
        printf("%s@\n", filename);
    } else if (buf->st_mode & S_IXUSR) {
        // If the file is executable by the owner, append "*"
        printf("%s*\n", filename);
    } else {
        // Otherwise, just print the file name
        printf("%s\n", filename);
    }
}

int main(int argc, char *argv[]) {
    const char *path = "."; // Default directory is the current directory (.)
    if (argc > 1) {
        path = argv[1]; // If a directory is provided, use that instead
    }

    DIR *dir = opendir(path); // Open the directory
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry; // Directory entry structure
    struct stat buf;      // Stat buffer to store file info
    char fullpath[1024];  // To hold the full path of the file

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special directories "." and ".."
        if (entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || (entry->d_name[1] == '.' && entry->d_name[2] == '\0'))) {
            continue;
        }

        // Construct the full path to the file
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get file status using stat
        if (lstat(fullpath, &buf) == -1) {
            perror("lstat");
            continue;
        }

        // Print the file name with the appropriate symbol
        print_file_type(&buf, entry->d_name);
    }

    closedir(dir); // Close the directory
    return 0;
}

