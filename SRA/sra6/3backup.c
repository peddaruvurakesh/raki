#include <stdio.h>
#include <stdlib.h>

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
        return 0;
    }

    // Declare a struct to store each record read from the file
    struct record person;

    // Read and display each person's information from the file
    printf("Data from peoples.txt:\n\n");

    // Loop until the end of the file
    while (1) {
        // Attempt to read the person's information
        int result = fscanf(fp, "Name: %49[^\t]\tAge: %d\tSalary: %d\n", person.name, &person.age, &person.salary);

        // Check for EOF
        if (result == EOF) {
            break; // Exit the loop on EOF
        }

        // Check if all three items were read successfully
        if (result == 3) {
            // Print the person's information
            printf("Name: %s\n", person.name);
            printf("Age: %d\n", person.age);
            printf("Salary: %d\n\n", person.salary);
        } else {
            printf("Error reading data. Only %d items were read.\n", result);
            break; // Exit the loop if there was an error
        }
    }

    fclose(fp); // Close the file

    return 0; // Return success
}

