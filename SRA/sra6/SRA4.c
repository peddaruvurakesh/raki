#include <stdio.h>
#include <string.h>

#define SIZE 50

// Define a structure to represent a person's record
struct record {
    char name[SIZE]; // name of the person
    int age;         // age of the person
    int salary;      // salary of the person
};

int main() {
    FILE *fp = fopen("peoples.txt", "r"); // Open file for reading

    // Check if file opening failed
    if (fp == NULL) {
        printf("Failed to open file. Make sure the file exists.\n");
        return 1;
    }

    struct record person;
    char searchName[SIZE];
    int found = 0; // Flag to indicate if the person is found

    // Ask the user for the name to search
    printf("What’s the name of the person you want to search for? ");
    scanf(" %s", searchName);  // Read the name with spaces

    // Loop through the file to find the matching person
    while (fscanf(fp, "Name: %s \tAge: %d\tSalary: %d\n", person.name, &person.age, &person.salary) != EOF) {
        // Compare the name with the user's input
        if (strcmp(person.name, searchName) == 0) {
            found = 1;  // Set flag to indicate person is found
            printf("Name: %s\n", person.name);
            printf("Age: %d\n", person.age);
            printf("Salary: %d\n", person.salary);
            break;  // Exit the loop once the person is found
        }
    }

    // If the person was not found, display a message
    if (!found) {
        printf("Person not found in the file.\n");
    }

    fclose(fp); // Close the file

    return 0;
}

