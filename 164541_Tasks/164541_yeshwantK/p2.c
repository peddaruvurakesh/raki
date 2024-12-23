#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

// Bit positions for each custom attribute
#define READ_ONLY        0x01  // Bit 0
#define HIDDEN           0x02  // Bit 1
#define SYSTEM           0x04  // Bit 2
#define VOLUME_LABEL     0x08  // Bit 3
#define SUB_DIRECTORY    0x10  // Bit 4
#define ARCHIVE          0x20  // Bit 5

void displayFileAttributes(const char *filename) {
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

    printf("Attributes:\n");
    printf("  Read-only: %s\n", (fileStat.st_mode & S_IWUSR) ? "No" : "Yes");
    printf("  Hidden: %s\n", (filename[0] == '.') ? "Yes" : "No");
    printf("  System: %s\n", (fileStat.st_mode & S_IXUSR) ? "No" : "Yes");
    printf("  Volume Label: %s\n", (strstr(filename, "VOL") == filename) ? "Yes" : "No");
    printf("  Sub-directory Entry: %s\n", S_ISDIR(fileStat.st_mode) ? "Yes" : "No");
}

void toggleFileAttribute(const char *filename, int choice) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("Could not get file attributes");
        return;
    }

    if (choice == 1) { // Toggle read-only
        if (fileStat.st_mode & S_IWUSR) {
            chmod(filename, fileStat.st_mode & ~S_IWUSR);
            printf("File is now read-only.\n");
        } else {
            chmod(filename, fileStat.st_mode | S_IWUSR);
            printf("File is now writable.\n");
        }
    } else if (choice == 2) { // Toggle hidden
        char newname[256];
        if (filename[0] == '.') {
            snprintf(newname, sizeof(newname), "%s", filename + 1);
        } else {
            snprintf(newname, sizeof(newname), ".%s", filename);
        }
        rename(filename, newname);
        printf("File renamed to %s\n", newname);
    } else if (choice == 3) { // Toggle system attribute
        if (fileStat.st_mode & S_IXUSR) {
            chmod(filename, fileStat.st_mode & ~S_IXUSR);
            printf("File is now marked as system file (no execute permission).\n");
        } else {
            chmod(filename, fileStat.st_mode | S_IXUSR);
            printf("File is now unmarked as system file.\n");
        }
    } else if (choice == 4) { // Toggle volume label
        char newname[256];
        if (strstr(filename, "VOL") == filename) {
            snprintf(newname, sizeof(newname), "%s", filename + 3);
        } else {
            snprintf(newname, sizeof(newname), "VOL%s", filename);
        }
        rename(filename, newname);
        printf("File renamed to %s\n", newname);
    } else if (choice == 5) { // Sub-directory entry
        if (S_ISDIR(fileStat.st_mode)) {
            printf("File is already a directory.\n");
        } else {
            printf("Cannot toggle directory status of a regular file.\n");
        }
    }
}

void displayCustomAttributes(unsigned char attributes) {
    printf("Custom Attributes:\n");
    printf("  Read-only: %s\n", (attributes & READ_ONLY) ? "Yes" : "No");
    printf("  Hidden: %s\n", (attributes & HIDDEN) ? "Yes" : "No");
    printf("  System: %s\n", (attributes & SYSTEM) ? "Yes" : "No");
    printf("  Volume Label: %s\n", (attributes & VOLUME_LABEL) ? "Yes" : "No");
    printf("  Sub-directory Entry: %s\n", (attributes & SUB_DIRECTORY) ? "Yes" : "No");
    printf("  Archive: %s\n", (attributes & ARCHIVE) ? "Yes" : "No");
}

void toggleCustomAttribute(unsigned char *attributes, unsigned char attribute) {
    *attributes ^= attribute;
}

int main() {
    char filename[256];
    unsigned char customAttributes = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Current file attributes:\n");
    displayFileAttributes(filename);

    int choice;
    while (1) {
        printf("\nEnter attribute to toggle (1-5 for file, 6-11 for custom, 12 to exit):\n");
        printf("File Attributes:\n");
        printf("  1. Read-only\n  2. Hidden\n  3. System\n  4. Volume Label\n  5. Sub-directory Entry\n");
        printf("Custom Attributes:\n");
        printf("  6. Custom Read-only\n  7. Custom Hidden\n  8. Custom System\n  9. Custom Volume Label\n");
        printf(" 10. Custom Sub-directory\n 11. Custom Archive\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 12) break;

        if (choice >= 1 && choice <= 5) {
            toggleFileAttribute(filename, choice);
            displayFileAttributes(filename);
        } else if (choice >= 6 && choice <= 11) {
            switch (choice) {
                case 6:
                    toggleCustomAttribute(&customAttributes, READ_ONLY);
                    break;
                case 7:
                    toggleCustomAttribute(&customAttributes, HIDDEN);
                    break;
                case 8:
                    toggleCustomAttribute(&customAttributes, SYSTEM);
                    break;
                case 9:
                    toggleCustomAttribute(&customAttributes, VOLUME_LABEL);
                    break;
                case 10:
                    toggleCustomAttribute(&customAttributes, SUB_DIRECTORY);
                    break;
                case 11:
                    toggleCustomAttribute(&customAttributes, ARCHIVE);
                    break;
            }
            displayCustomAttributes(customAttributes);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nFinal custom attributes:\n");
    displayCustomAttributes(customAttributes);

    return 0;
}

