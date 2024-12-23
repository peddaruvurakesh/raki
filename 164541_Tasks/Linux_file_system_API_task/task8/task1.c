#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Structure to store file name and size
typedef struct {
    char filename[256];  // Filename
    off_t size;          // File size
} FileInfo;

// Comparison function to sort files by size
int compare_size(const void *a, const void *b) {
    FileInfo *file1 = (FileInfo *)a;
    FileInfo *file2 = (FileInfo *)b;
    return (file1->size - file2->size);  // Sort by size (ascending order)
}

int main() {
    DIR *dir;                   // Directory pointer
    struct dirent *entry;       // Directory entry
    struct stat file_stat;      // Structure to store file stats
    FileInfo files[1024];       // Array to store file names and sizes
    int file_count = 0;         // Counter for number of files

    // Open current directory
    dir = opendir(".");
    if (dir == NULL) {  // Check if directory could not be opened
        perror("opendir");
        return 1;
    }

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get file status using stat()
        if (stat(entry->d_name, &file_stat) == -1) {
            perror("stat");
            closedir(dir);  // Close the directory before exiting
            return 1;
        }

        // Store file name and size in the array
        strncpy(files[file_count].filename, entry->d_name, sizeof(files[file_count].filename));
        files[file_count].size = file_stat.st_size;
        file_count++;  // Increment the file count
    }

    // Close the directory
    closedir(dir);

    // Sort files by size using qsort()
    qsort(files, file_count, sizeof(FileInfo), compare_size);

    // Print the sorted list of files with their sizes
    printf("Files in the current directory sorted by size:\n");
    for (int i = 0; i < file_count; i++) {
        printf("%-50s %10ld bytes\n", files[i].filename, files[i].size);
    }

    return 0;
}

