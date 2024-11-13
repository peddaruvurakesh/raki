#include <stdio.h>

#define SIZE 100

// Define a structure to represent a person's record
struct record {
    char name[SIZE];       // First name of the person
    char lastname[SIZE];   // Last name of the person
    int age;               // Age of the person
    int salary;            // Salary of the person
    char street[SIZE];     // Street of the person
    int number;            // House number of the person
    char postalcode[SIZE]; // Postal code of the person
    char state[SIZE];      // State of the person
};

int main() {
    struct record person;  // Declare a variable to store information about a person
    FILE *fp1 = fopen("newfile.txt", "r");  // Open input file for reading (from Task 5 output)
    FILE *fp2 = fopen("addressfile.txt", "a+"); // Open output file for appending and reading

    // Check if file opening failed
    if (fp1 == NULL || fp2 == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // Read person's information from input file and append it to output file along with address info
    while (fscanf(fp1, "Name: %s Last name: %s Age: %d Salary: %d\n", person.name, person.lastname, &person.age, &person.salary) == 4) {
        // Ask for additional address information
        printf("Enter the street name for %s %s: ", person.name, person.lastname);
        scanf(" %[^\n]", person.street);
        printf("Enter the house number: ");
        scanf("%d", &person.number);
        printf("Enter the postal code: ");
        scanf(" %[^\n]", person.postalcode);
        printf("Enter the state: ");
        scanf(" %[^\n]", person.state);

        // Append to the output file
        fprintf(fp2, "Name: %s \t\nLast name: %s\t\n Age: %d Salary: %d\t\n Street: %s\t\n Number: %d\t\n Postal code: %s\t\n State: %s\t\n", 
                person.name, person.lastname, person.age, person.salary, person.street, person.number, person.postalcode, person.state);
    }

    printf("Data appended to addressfile.txt successfully.\n");

    fclose(fp1); // Close the input file
    fclose(fp2); // Close the output file

    return 0;
}

