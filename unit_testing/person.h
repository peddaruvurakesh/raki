 /*#include<stdio.h>
#define NAME_LENGTH 50
#define TOWN_LENGTH 50
#define MAX_PERSONS 3




struct person {
	char name[50];
	char town[50];
        };
void readperson(struct person *p);
void searchtown(struct person persons[],int size,struct person *searchperson);
int containdigits(const char *str);
*/     
// person.h
#ifndef PERSON_H
#define PERSON_H

#define NAME_LENGTH 50
#define TOWN_LENGTH 50
#define MAX_PERSONS 3

// Define a structure to store person information
struct Person {
    char name[NAME_LENGTH];
    char town[TOWN_LENGTH];
};

// Function prototypes
void readPerson(struct Person *p);
void searchTown(struct Person persons[], int size, struct Person *searchPerson);
int containsDigits(const char *str);

#endif

