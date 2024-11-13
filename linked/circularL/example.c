#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the circular linked list
void addAtBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to add a node at the end of the circular linked list
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("HEAD\n");  // Indicates the circular nature of the list
    } else {
        printf("List is empty.\n");
    }
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL)
        return;

    struct Node *temp = *head, *prev;

    // Case: only one node in the list
    if ((*head)->data == key && (*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    // Case: deleting the head node
    if ((*head)->data == key) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
    } else {
        // Deleting any other node
        while (temp->next != *head && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next->data == key) {
            struct Node* delNode = temp->next;
            temp->next = delNode->next;
            free(delNode);
        }
    }
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL;

    addAtEnd(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtBegin(&head, 5);

    printf("Circular Linked List: ");
    displayList(head);

    deleteNode(&head, 20);
    printf("After deletion of 20: ");
    displayList(head);

    deleteNode(&head, 5);
    printf("After deletion of 5 (beginning node): ");
    displayList(head);

    return 0;
}

