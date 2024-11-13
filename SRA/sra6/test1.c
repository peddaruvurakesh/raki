

int main()
{
	int i;
	char ch;
	char *per; // Pointer to store the name of the person to search for
	struct Person members[PERSONS]; // Array to store information about 3 persons

	// Input information about each person
	for (i = 0; i < PERSONS; i++) {
		printf("Enter name: ");

	}

	printf("Enter town or city: ");


}

}


per = readPerson(); // Get the name of the person to search for
i = searchTown(members, per); // Search for the person in the list

// Print the town or city where the person lives, if found
if (i != -1)
	printf("This person lives in: %s\n", members[i].town);
	else
	printf("This person's details were not found in the list.\n");


	}

/* *
 * readPerson(): Function to read the name of the person to search for
 * Author: rakesh peddaruvu
 * Created: 18-sep-2024
 * Modified: 18-sep-2024
 * */
char* readPerson(void) {
	static char name[50]; // Static array to store the name of the person
	printf("Enter the name of the person you want to search for: ");
	scanf("%s", name);
	return name; // Return the name of the person
}

/* *
 * readPerson():  Function to search for a person's details by name
 * Author: rakesh peddaruvu
 * Created: 18-sep-2024
 * Modified: 18-sep-2024
 * */
int searchTown(struct Person members[], char per[]) {
	int i = 0;
	for (; i < 3; i++) {
		// Compare the given name with each person's name in the list
		if (strcmp(members[i].name, per) == 0)
			return i; // Return the index of the person if found
	}
	return -1; // Return -1 if the person is not found in the list
}

~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
