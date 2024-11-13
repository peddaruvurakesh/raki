#include<stdio.h>

char* readperson(void);
searchtown (struct person members);
struct person {
	char name[20];
	char town[20];
 };
int main()
{
        int i;
        char *per; // Pointer to store the name of the person to search for
        struct person members[3]; // Array to store information about 3 persons

        // Input information about each person
        for (i = 0; i < 3; i++) {
                printf("Enter name: ");
                scanf("%s", members[i].name);
                printf("Enter town or city: ");
                scanf("%s", members[i].town);

	}
	per=readperson();

}	
char* readperson(void)
{
	char name2[20];
printf("enter the search name :");
scanf("%s",name2);
return name2;

}
