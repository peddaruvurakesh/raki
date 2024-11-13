#include <stdio.h>

#define SIZE 100

// Define a structure to represent a person's record
struct record {
    char name[SIZE];      // name of the person
    int age;              // age of the person
    char lastname[SIZE];  // last name of the person
    int salary;           // salary of the person
};

int main() {
    struct record person; // Declare a variable to store information about a person
    FILE *fp1 = fopen("peoples.txt", "r");  // Open input file for reading
    FILE *fp2 = fopen("newfile.txt", "a+"); // Open output file for appending and reading

    // Check if file opening failed
    if (fp1 == NULL || fp2 == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // Read person's information from input file and append it to output file
    while (fscanf(fp1, "Name: %s Age: %d Salary: %d\n", person.name, &person.age, &person.salary) ==3) {
        // Ask for the last name
        printf("Enter the last name of %s: ", person.name);
        scanf(" %[^\n]", person.lastname);  // Read the last name including spaces

        // Append to the output file
        fprintf(fp2, "Name: %s Last name: %s Age: %d Salary: %d\n", person.name, person.lastname, person.age, person.salary);
    }

    printf("Data appended to newfile.txt successfully.\n");

    fclose(fp1); // Close the input file
    fclose(fp2); // Close the output file

    return 0;
}

