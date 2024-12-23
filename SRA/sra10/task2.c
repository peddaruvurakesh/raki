#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to search for a value in the doubly linked list
Node* searchDLL(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;  // Key found
        }
        temp = temp->next;
    }
    return NULL;  // Key not found
}

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Helper function to insert a node at the end of the doubly linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to take user input and create a doubly linked list
Node* createDoublyList() {
    Node* head = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertEnd(head, data);
    }
    return head;
}

// Main function to demonstrate functionality
int main() {
    printf("Create a doubly linked list:\n");
    Node* head = createDoublyList();

    printf("\nEnter the element to search: ");
    int key;
    scanf("%d", &key);

    Node* result = searchDLL(head, key);
    if (result) {
        printf("Element %d found in the list.\n", key);
    } else {
        printf("Element %d not found in the list.\n", key);
    }
    return 0;
}

