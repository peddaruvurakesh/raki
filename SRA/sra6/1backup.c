#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PERSONS 3
#define NAME_LENGTH 50
#define TOWN_LENGTH 50

// Define a structure to store person information
struct Person {
    char name[NAME_LENGTH];
    char town[TOWN_LENGTH];
};

// Function prototypes
void readPerson(struct Person *p);
void searchTowns(struct Person persons[], int size, struct Person *searchPerson);
int containsDigits(const char *str);

int main() {
    struct Person persons[MAX_PERSONS];

    // Read information for 3 persons
    for (int i = 0; i < MAX_PERSONS; i++) {
        readPerson(&persons[i]);
    }

    // Search for a person's towns
    struct Person searchPerson;
    printf("==========================================================\n");
    printf("Enter the name of the person you want to search for: ");
    scanf(" %[^\n]%*c", searchPerson.name); // Read until newline

    // Search for the towns
    searchTowns(persons, MAX_PERSONS, &searchPerson);

    return 0;
}

// Function to read a person
void readPerson(struct Person *p) {
    // Read name and validate
    while (1) {
        printf("Enter name: ");
        scanf(" %[^\n]", p->name); // Read until newline

        // Check if the name contains digits
        if (containsDigits(p->name)) {
            printf("Name cannot contain digits. Please enter again.\n");
        } else {
            break; // Valid name, exit loop
        }
    }

    // Read town and validate
    while (1) {
        printf("Enter town or city: ");
        scanf(" %[^\n]%*c", p->town); // Read until newline

        // Check if the town contains digits
        if (containsDigits(p->town)) {
            printf("Town or city cannot contain digits. Please enter again.\n");
        } else {
            break; // Valid town, exit loop
        }
    }
}

// Function to check if the string contains digits
int containsDigits(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            return 1; // Return 1 if a digit is found
        }
    }
    return 0; // Return 0 if no digits are found
}

// Function to search for all towns based on the person's name
void searchTowns(struct Person persons[], int size, struct Person *searchPerson) {
    int found = 0;
//    printf("Towns where %s lives: ", searchPerson->name);

    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, searchPerson->name) == 0) {
            printf("%s ", persons[i].town);
            found = 1;
        }
    }

    if (!found) {
        printf("Person not found.");
    }

    printf("\n");
}

