#include <stdio.h>
#include <string.h> // needed for strcpy() and strcmp()
#include <stdlib.h> // needed for malloc(), free()
#define STRLEN 64

// Define a structure for the linked list node
typedef struct node {
    char name[STRLEN];  // Store a string (name)
    struct node *next;  // Pointer to the next node
} Node;

void showHelp(void);                 // Function to display help instructions
void add(char *, Node **);            // Function to add a node to the list
void removeElement(char *, Node **);  // Function to remove a node from the list
int isItem(char *, Node *);           // Function to check if a node is in the list
int countItems(Node *);               // Function to count the number of nodes in the list
void removeList(Node **);             // Function to remove all nodes from the list
void showList(Node *);                // Function to display the list
char * trim(char *);                  // Function to remove leading spaces from a string

int main(void) {
    char instruction[STRLEN];  // Store the user instruction
    Node *head = NULL;         // Initialize the head of the linked list to NULL
    char *pi;                  // Pointer to the instruction

    printf("Test program for a single-linked list.\n");
    printf("\nEnter an instruction (h = help)\n");
    printf("\n ");

    memset(instruction, '\0', STRLEN);  // Clear the instruction array
    gets(instruction);  // Get the instruction from the user (deprecated, should use fgets)
    pi = trim(instruction);  // Trim leading spaces from the instruction

    // Loop until the user enters 'q' to quit
    while (*pi != 'q') {
        switch (*pi) {
            case 'i': 
                add(trim(pi + 1), &head);  // Add a node with the string after 'i'
                break;
            case 'd': 
                removeElement(trim(pi + 1), &head);  // Remove the node with the string after 'd'
                break;
            case 'f': 
                if (isItem(trim(pi + 1), head))  // Check if the string is in the list
                    printf("\"%s\" is in the list.\n", trim(pi+1));
                else
                    printf("\"%s\" is NOT in the list.\n", trim(pi+1));
                break;
            case 'l': 
                showList(head);  // Display the list
                break;
            case 'n': 
                printf(" Number of list items: %d\n", countItems(head));  // Display the count of nodes
                break;
            case 'r': 
                removeList(&head);  // Remove the entire list
                break;
            case 'h': 
                showHelp();  // Show help instructions
                break;
            case 'q': 
                break;  // Quit the program
            default: 
                printf(" Unknown instruction (h = help)\n");  // Handle unknown instruction
        }
        printf("\n> ");
        memset(instruction, '\0', STRLEN);  // Clear the instruction array for the next input
        gets(instruction);  // Get the next instruction from the user
        pi = trim(instruction);  // Trim leading spaces from the new instruction
    }

    // Remove the list when the program ends
    removeList(&head);
    return 0;
}

// Function to display the help menu
void showHelp(void) {
    printf("i <string> : inserts the element in <string> alphabetically into the list\n");
    printf("d <string> : removes the element in <string> from the list\n");
    printf("f <string> : searches the list and returns if the string is in the list or not\n");
    printf("l : shows the full list\n");
    printf("n : returns the number of items in the list\n");
    printf("r : removes the full list\n");
    printf("h : shows the help menu (this list)\n");
    printf("q : end of the program (first remove the list)\n");
}

// Function to add a new node to the list in alphabetical order
void add(char *s, Node **b) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // Allocate memory for the new node
    Node *temp = *b, *prev = NULL;  // Initialize temp to traverse the list

    strcpy(newNode->name, s);  // Copy the string into the new node
    newNode->next = NULL;  // Initialize next pointer to NULL

    // Traverse the list to find the correct position (alphabetical order)
    while (temp != NULL && strcmp(temp->name, s) < 0) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {  // Insert at the beginning if the list is empty or s comes before the head
        newNode->next = *b;
        *b = newNode;
    } else {  // Insert in the middle or end of the list
        newNode->next = prev->next;
        prev->next = newNode;
    }

    printf("Inserted \"%s\" into the list.\n", s);
}

// Function to remove a node with the string s from the list
void removeElement(char *s, Node **b) {
    Node *temp = *b, *prev = NULL;  // Initialize temp to traverse the list

    // Traverse the list to find the node to remove
    while (temp != NULL && strcmp(temp->name, s) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {  // Node not found
        printf("Element \"%s\" not found in the list.\n", s);
        return;
    }

    if (prev == NULL) {  // Node to remove is at the head
        *b = temp->next;
    } else {  // Node to remove is in the middle or end
        prev->next = temp->next;
    }

    free(temp);  // Free the memory allocated for the node
    printf("Removed \"%s\" from the list.\n", s);
}

// Function to check if the string s is in the list
int isItem(char *s, Node *b) {
    Node *temp = b;  // Initialize temp to traverse the list

    // Traverse the list to find the node with the string s
    while (temp != NULL) {
        if (strcmp(temp->name, s) == 0) {
            return 1;  // Found the string
        }
        temp = temp->next;
    }

    return 0;  // String not found
}

// Function to count the number of nodes in the list
int countItems(Node *b) {
    int count = 0;  // Initialize count to 0
    Node *temp = b;  // Initialize temp to traverse the list

    // Traverse the list and increment the count for each node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;  // Return the total count of nodes
}

// Function to remove all nodes from the list
void removeList(Node **b) {
    Node *temp = *b;  // Initialize temp to traverse the list

    // Traverse the list and free each node
    while (temp != NULL) {
        *b = temp->next;
        free(temp);
        temp = *b;
    }

    printf("List removed.\n");
}

// Function to display the linked list
void showList(Node *b) {
    if (b == NULL) {  // If the list is empty
        printf("The list is EMPTY\n");
    } else {  // Traverse the list and print each node's string
        printf("The list:\n");
        while (b != NULL) {
            printf("%s ", b->name);
            b = b->next;
        }
        printf("\n");
    }
}

// Function to remove leading spaces from a string
char * trim(char *s) {
    while (*s == ' ') s++;  // Skip spaces
    return s;
}

