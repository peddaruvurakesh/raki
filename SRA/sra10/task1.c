#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* clist;

void printCList(clist l, const clist h) {
    if (l->next != h) {
        printCList(l->next, h);  // Recursive call to reach the end
    }
    printf("%d ", l->data);  // Print data while unwinding recursion
}

// Helper function to create a new node
clist createNode(int data) {
    clist newNode = (clist)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper function to insert a node at the end of the circular linked list
clist insertEnd(clist head, int data) {
    clist newNode = createNode(data);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }
    clist temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Helper function to print the list in normal order
void printNormal(clist head) {
    if (!head) return;
    clist temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function to demonstrate functionality
int main() {
    clist head = NULL;
    int n, value;

    printf("Enter the number of nodes in the circular linked list: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Circular linked list in normal order:\n");
    printNormal(head);

    printf("Circular linked list in reverse order:\n");
    printCList(head, head);
    printf("\n");

    return 0;
}

