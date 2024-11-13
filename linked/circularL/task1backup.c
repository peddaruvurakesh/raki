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
        fprintf(stderr, "Memory allocation failed\n");
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

// Main function to demonstrate the operations
int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);

    printf("Circular Linked List: ");
    display(head);

    deleteNode(&head, 2);
    printf("Circular Linked List after deleting 2: ");
    display(head);

//    deleteNode(&head, 5); // Trying to delete a non-existent node
  //  printf("Circular Linked List after attempting to delete 5: ");
    display(head);

    return 0;
}

