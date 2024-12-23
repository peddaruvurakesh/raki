#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Utility function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Utility function to print the linked list
void PrintList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Add node at the beginning
void AddBegin(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Add node at the end
void Append(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Count occurrences of a value
int Count(struct node* head, int searchFor) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == searchFor) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Get data at a specific index
int GetNth(struct node* head, int index) {
    struct node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == index)
            return temp->data;
        count++;
        temp = temp->next;
    }
    return -1;  // If the index is out of bounds
}

// Pop the first node and return its data
int Pop(struct node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return -1;
    }
    struct node* temp = *headRef;
    int data = temp->data;
    *headRef = temp->next;
    free(temp);
    return data;
}

// Delete the entire list
void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

// Insert a node in sorted order
void SortedInsert(struct node** headRef, struct node* newNode) {
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct node* current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Sort the list using insertion sort
void InsertSort(struct node** headRef) {
    struct node* sorted = NULL;
    struct node* current = *headRef;
    while (current != NULL) {
        struct node* next = current->next;
        SortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}

// Remove duplicates from a sorted list
void RemoveDuplicates(struct node* head) {
    struct node* current = head;
    if (current == NULL) return;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// Move the node from source to destination list
void MoveNode(struct node** destRef, struct node** sourceRef) {
    if (*sourceRef == NULL) {
        printf("Source list is empty.\n");
        return;
    }
    struct node* newNode = *sourceRef;
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

int main() {
    struct node* head = NULL;
    struct node* sourceList = NULL;
    int choice, data, index, count;

    do {
        printf("\nInstructions:\n");
        printf("1. Add at Beginning\n");
        printf("2. Append at End\n");
        printf("3. Display List\n");
        printf("4. Count Occurrences\n");
        printf("5. Get Nth Node Data\n");
        printf("6. Pop First Node\n");
        printf("7. Delete Entire List\n");
        printf("8. Sorted Insert\n");
        printf("9. Insert Sort\n");
        printf("10. Remove Duplicates\n");
        printf("11. Move Node from Source to Destination\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                AddBegin(&head, data);
                break;

            case 2:
                printf("Enter data to append at end: ");
                scanf("%d", &data);
                Append(&head, data);
                break;

            case 3:
                printf("The list is: ");
                PrintList(head);
                break;

            case 4:
                printf("Enter the data to count occurrences: ");
                scanf("%d", &data);
                count = Count(head, data);
                printf("The data %d occurs %d times in the list.\n", data, count);
                break;

            case 5:
                printf("Enter the index to get data: ");
                scanf("%d", &index);
                data = GetNth(head, index);
                if (data != -1) {
                    printf("Data at index %d is %d.\n", index, data);
                } else {
                    printf("Invalid index!\n");
                }
                break;

            case 6:
                data = Pop(&head);
                if (data != -1) {
                    printf("Popped data: %d\n", data);
                }
                break;

            case 7:
                DeleteList(&head);
                printf("The list is deleted.\n");
                break;

            case 8:
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                struct node* newNode = createNode(data);
                SortedInsert(&head, newNode);
                break;

            case 9:
                InsertSort(&head);
                printf("List sorted using insertion sort.\n");
                break;

            case 10:
                RemoveDuplicates(head);
                printf("Duplicates removed from sorted list.\n");
                break;

            case 11:
                printf("Enter data : ");
                scanf("%d", &data);
                AddBegin(&sourceList, data);
                printf("Moving node\n");
                MoveNode(&head, &sourceList);
                break;

            case 12:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 12);

    return 0;
}

