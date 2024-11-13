// main.c
#include <stdio.h>
#include <string.h>
//#include"Unity/src/unity.h"
#include "person.h"

int main() {
    struct Person persons[MAX_PERSONS];

    // Read information for 3 persons
    for (int i = 0; i < MAX_PERSONS; i++) {
        readPerson(&persons[i]);
    }

    // Search for a person's town
    struct Person searchPerson;
    printf("==========================================================\n");
    printf("Enter the name of the person you want to search for: ");
    scanf(" %[^\n]%*c", searchPerson.name); // Read until newline

    // Search for the town
    searchTown(persons, MAX_PERSONS, &searchPerson);

    if (strlen(searchPerson.town) > 0) {
        printf("This person lives in %s\n", searchPerson.town);
    } else {
        printf("Person not found.\n");
    }

    return 0;
}

