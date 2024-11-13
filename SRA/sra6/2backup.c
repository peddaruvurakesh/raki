#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

// Define a structure to represent a person's record
struct record {
    char name[SIZE]; // name of the person
    int age;         // age of the person
    int salary;      // salary of the person
};

// Function prototype to validate the name
int isValidName(const char name[]);

int main() {
    int n, i;
    FILE *fp = fopen("peoples.txt", "a+"); // Open file for appending and reading

    // Check if file opening failed
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    // Input the number of people
    printf("How many people do you want to enter? ");
    scanf("%d", &n);

    // Declare an array of 'n' records
    struct record persons[n];

    // Input information about each person and write it to the file
    for (i = 0; i < n; i++) {
        while (1) {
            printf("Enter name: ");
            scanf("%s", persons[i].name);  // Read name
            
            // Validate the name
            if (isValidName(persons[i].name)) {
                break; // If valid, exit the loop
            } else {
                printf("Name should contain only alphabets. Please try again.\n");
            }
        }

        printf("Enter age: ");
        scanf("%d", &persons[i].age);  // Read age

        printf("Enter salary: ");
        scanf("%d", &persons[i].salary); // Read salary

        // Write the person's information to the file
        fprintf(fp, "Name: %s\tAge: %d\tSalary: %d\n", persons[i].name, persons[i].age, persons[i].salary);
    }

    fclose(fp); // Close the file

    printf("Data saved to peoples.txt.\n");

    return 0; // Return success
}

// Function to validate if the name contains only alphabetic characters
int isValidName(const char name[]) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; // Return 0 if any non-alphabetic character is found
        }
    }
    return 1; // Return 1 if all characters are alphabetic
}

