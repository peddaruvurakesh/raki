#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PERSONS 100

// Structure to represent a Date
struct Date {
    int day;
    int month;
    int year;
};

// Structure to represent a Person
struct Person {
    char name[MAX_NAME_LEN];
    struct Date dob; // Date of birth
};

// Function to read the data of 1 person from the file and save it into a struct
int read_person(FILE *file, struct Person *person) {
    return fscanf(file, "%s %d/%d/%d", person->name, &person->dob.day, &person->dob.month, &person->dob.year) == 4;
}

// Function to calculate the age of a person in years, months, and days
void calculate(struct Person person, struct Date current_date, int *years, int *months, int *days) {
    *years = current_date.year - person.dob.year;
    *months = current_date.month - person.dob.month;
    *days = current_date.day - person.dob.day;

    if (*days < 0) {
        *months -= 1;
        *days += 30; // assuming 30 days in a month
    }

    if (*months < 0) {
        *years -= 1;
        *months += 12;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <file_name> <current_day> <current_month> <current_year>\n", argv[0]);
        return 1;
    }

    // Get the current date from command line arguments
    struct Date current_date;
    current_date.day = atoi(argv[2]);
    current_date.month = atoi(argv[3]);
    current_date.year = atoi(argv[4]);

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Person persons[MAX_PERSONS];
    int count = 0;

    // Read the data of all people from the file
    while (read_person(file, &persons[count])) {
        count++;
        if (count >= MAX_PERSONS) {
            break;
        }
    }

    fclose(file);

    int oldest_age_years = 0, oldest_age_months = 0, oldest_age_days = 0;
    char oldest_person[MAX_NAME_LEN] = "";
    char longest_name[MAX_NAME_LEN] = "";
    int max_name_length = 0;

    // Calculate the ages and determine the oldest person and the person with the longest name
    printf("The ages are:\n");
    for (int i = 0; i < count; i++) {
        int years, months, days;
        calculate(persons[i], current_date, &years, &months, &days);

        printf("%s is %d years old\n", persons[i].name, years);

        // Find the oldest person
        if (years > oldest_age_years || (years == oldest_age_years && months > oldest_age_months) || 
            (years == oldest_age_years && months == oldest_age_months && days > oldest_age_days)) {
            oldest_age_years = years;
            oldest_age_months = months;
            oldest_age_days = days;
            strcpy(oldest_person, persons[i].name);
        }

        // Find the person with the longest name
        if (strlen(persons[i].name) > max_name_length) {
            max_name_length = strlen(persons[i].name);
            strcpy(longest_name, persons[i].name);
        }
    }

    printf("\nThe oldest person is: %s\n", oldest_person);
    printf("The person with the longest name is: %s\n", longest_name);

    return 0;
}

