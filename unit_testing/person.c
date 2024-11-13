// person.c
#include "person.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Function to search for the town based on the person's name
void searchTown(struct Person persons[], int size, struct Person *searchPerson) {
    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, searchPerson->name) == 0) {
            strcpy(searchPerson->town, persons[i].town);
            return;
        }
    }
    // If not found, town remains empty
    searchPerson->town[0] = '\0'; // Empty string for town
}

