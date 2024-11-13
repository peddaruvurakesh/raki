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

// Function prototypes to validate the name and age
int isValidName(const char name[]);
int isValidAge(const char ageStr[]);

int main() {
    int n, i;
    char ageStr[SIZE];  // Temporary string to store age input as string
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
        // Name validation
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

        // Age validation
        while (1) {
            printf("Enter age: ");
            scanf("%s", ageStr);  // Read age as string

            // Validate the age input (must be digits only)
            if (isValidAge(ageStr)) {
                persons[i].age = atoi(ageStr);  // Convert the valid age string to integer
                break; // If valid, exit the loop
            } else {
                printf("Age should contain only digits. Please try again.\n");
            }
        }

        // Read salary
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

// Function to validate if the age contains only digits
int isValidAge(const char ageStr[]) {
    for (int i = 0; i < strlen(ageStr); i++) {
        if (!isdigit(ageStr[i])) {
            return 0; // Return 0 if any non-digit character is found
        }
    }
    return 1; // Return 1 if all characters are digits
}

