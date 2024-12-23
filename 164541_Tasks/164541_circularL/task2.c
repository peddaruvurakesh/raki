#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf( "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with a specific data value from the circular linked list
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // If the head node is the node to be deleted
    if (temp->data == data) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (*head == (*head)->next) { // Only one node in the list
            free(*head);
            *head = NULL;
        } else {
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        return;
    }

    // Traverse the list to find the node to delete
    temp = *head;
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != data);

    // If the node is found, delete it
    if (temp->data == data) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Node with data %d not found.\n", data);
    }
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("HEAD\n");
}

// Function to calculate the sum of all even numbers in the circular linked list
int sumEvenNumbers(Node* head) {
    int sum = 0;
    if (head == NULL) {
        return sum;
    }

    Node* current = head;
    do {
        if (current->data % 2 == 0) {
            sum += current->data;
        }
        current = current->next;
    } while (current != head);

    return sum;
}

// Main function to demonstrate the operations
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Display list\n");
        printf("5. Sum of all even numbers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Circular Linked List: ");
                display(head);
                break;
            case 5:
                printf("Sum of all even numbers in the list: %d\n", sumEvenNumbers(head));
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

