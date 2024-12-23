#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void display_menu() {
    printf("\nDoubly Linked List Operations:\n");
    printf("1. Append a node at the end\n");
    printf("2. Add a node at the beginning\n");
    printf("3. Add a node after a specific location\n");
    printf("4. Display the list\n");
    printf("5. Count the nodes\n");
    printf("6. Delete a node by value\n");
    printf("7. Exit\n");
    printf("Enter 'h' to display this help menu at any time.\n");
}

int main() {
    struct dnode *p = NULL;  // Initialize an empty doubly linked list
    int choice, num, loc;
    char input[10];  // To store both integer choices and 'h'

    display_menu();  // Display the menu at the start

    while (1) {
        printf("\nEnter your choice (or 'h' for help): ");
        scanf("%s", input);  // Use string input to handle both numbers and 'h'

        // Check if the user entered 'h' for help
        if (input[0] == 'h') {
            display_menu();  // Display the menu if 'h' is entered
            continue;  // Go back to asking for input
        }

        // Convert the input to an integer choice
        choice = atoi(input);

        // Process the user's choice
        switch (choice) {
            case 1:
                printf("Enter the number to append: ");
                scanf("%d", &num);
                d_append(&p, num);
                break;

            case 2:
                printf("Enter the number to add at the beginning: ");
                scanf("%d", &num);
                d_addatbeg(&p, num);
                break;

            case 3:
                printf("Enter the location after which to add: ");
                scanf("%d", &loc);
                printf("Enter the number to add: ");
                scanf("%d", &num);
                d_addafter(p, loc, num);
                break;

            case 4:
                printf("The list is: ");
                d_display(p);
                break;

            case 5:
                printf("No. of Elements in the DLL: %d\n", d_count(p));
                break;

            case 6:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                d_delete(&p, num);
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

