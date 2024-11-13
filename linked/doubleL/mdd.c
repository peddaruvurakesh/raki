#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    struct dnode *p = NULL;  // Initialize an empty doubly linked list
    int choice, num, loc;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Append a node at the end\n");
        printf("2. Add a node at the beginning\n");
        printf("3. Add a node after a specific location\n");
        printf("4. Display the list\n");
        printf("5. Count the nodes\n");
        printf("6. Delete a node by value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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

