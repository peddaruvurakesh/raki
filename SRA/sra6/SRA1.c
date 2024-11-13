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
void searchTown(struct Person persons[], int size, struct Person *searchPerson);
int containsDigits(const char *str);

int main() {

	int numPersons;



   // printf("How many people do you want to enter? ");
    //scanf("%d", &n);


//	  printf("How many people do you want to enter? ");
  //  scanf("%d", &numPersons);
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
}

