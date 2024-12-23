#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// Function to recursively calculate total file size
unsigned long long calculate_total_size(const char *path) {
    unsigned long long total_size = 0;
    struct dirent *entry; // Directory entry structure
    struct stat buf;      // Stat buffer to store file info
    DIR *dir = opendir(path); // Open the directory

    if (dir == NULL) {
        perror("opendir");
        return 0;
    }

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special directories "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the file/directory
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get file status using stat (not lstat, because we want to ignore soft links)
        if (stat(fullpath, &buf) == -1) {
            perror("stat");
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(buf.st_mode)) {
            // Recursively calculate size for the subdirectory
            total_size += calculate_total_size(fullpath);
        } else if (S_ISREG(buf.st_mode)) {
            // Add the file size if it is a regular file
            total_size += buf.st_size;
        }
    }

    closedir(dir); // Close the directory
    return total_size;
}

int main(int argc, char *argv[]) {
    const char *path = "."; // Default directory is the current directory (.)
    if (argc > 1) {
        path = argv[1]; // If a directory is provided, use that instead
    }

    unsigned long long total_size = calculate_total_size(path);

    // Print the total size in bytes
    printf("Total size of all files in directory '%s': %llu bytes\n", path, total_size);

    return 0;
}

