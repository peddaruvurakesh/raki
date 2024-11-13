#include <stdio.h>
#include <string.h>

// Define a structure to store person's details
struct Person {
    char name[50];
    char town[50];
};

// Function to read details of a person
void readPerson(struct Person* p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter town or city: ");
    scanf("%s", p->town);
}

// Function to search for a town by person's name
int searchTown(struct Person arr[], int size, struct Person* searchPerson) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, searchPerson->name) == 0) {
            strcpy(searchPerson->town, arr[i].town);  // Copy the town found into the searchPerson's town member
            return 1;  // Found
        }
    }
    return 0;  // Not found
}

int main() {
    struct Person people[3];  // Array of 3 persons

    // Reading the details of 3 persons
    for (int i = 0; i < 3; i++) {
        readPerson(&people[i]);
    }

    // Input the name of the person to search for
    struct Person searchPerson;
    printf("==========================================================\n");
    printf("Enter the name of the person you want to search for: ");
    scanf("%s", searchPerson.name);

    // Searching the town by name
    if (searchTown(people, 3, &searchPerson)) {
        printf("This person lives in %s\n", searchPerson.town);
    } else {
        printf("Person not found.\n");
    }

    return 0;
}

