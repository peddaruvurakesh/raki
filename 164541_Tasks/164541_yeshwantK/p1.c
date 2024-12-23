#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void displayAttributes(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("Could not get file attributes");
        return;
    }

    printf("File: %s\n", filename);
    printf("Permissions: ");
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("Read-only: %s\n", (fileStat.st_mode & S_IWUSR) ? "No" : "Yes");
    printf("Hidden: %s\n", (filename[0] == '.') ? "Yes" : "No");
}

void changeAttribute(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("Could not get file attributes");
        return;
    }

    int choice;
    printf("Enter attribute to toggle:\n");
    printf("1. Read-only\n2. Hidden\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) { // Toggle read-only
        if (fileStat.st_mode & S_IWUSR) {
            // Remove write permission (make read-only)
            if (chmod(filename, fileStat.st_mode & ~S_IWUSR) < 0) {
                perror("Failed to make file read-only");
            } else {
                printf("File is now read-only.\n");
            }
        } else {
            // Add write permission
            if (chmod(filename, fileStat.st_mode | S_IWUSR) < 0) {
                perror("Failed to make file writable");
            } else {
                printf("File is now writable.\n");
            }
        }
    } else if (choice == 2) { // Toggle hidden attribute
        char newname[256];
        if (filename[0] == '.') {
            // Remove the hidden attribute (rename without '.')
            snprintf(newname, sizeof(newname), "%s", filename + 1);
        } else {
            // Add the hidden attribute (rename with '.' prefix)
            snprintf(newname, sizeof(newname), ".%s", filename);
        }

        if (rename(filename, newname) < 0) {
            perror("Failed to change hidden attribute");
        } else {
            printf("File renamed to %s\n", newname);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    char filename[256];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Display current attributes
    printf("Current file attributes:\n");
    displayAttributes(filename);

    // Change attributes interactively
    changeAttribute(filename);

    // Display updated attributes
    printf("Updated file attributes:\n");
    displayAttributes(filename);

    return 0;
}

