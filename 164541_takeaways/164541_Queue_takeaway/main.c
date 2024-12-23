#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Priority Queue Node Definition
 * Each node represents a patient with:
 * - Name: A string representing the patient's name.
 * - Priority: An integer where a lower value indicates higher urgency.
 * - Next: A pointer to the next node in the queue.
 */
typedef struct PQ {
    char name[100];          // Name of the patient
    int priority;            // Priority of the patient
    struct PQ* next;         // Pointer to the next node in the list
} PTNode;

// Global pointers to manage the queue
PTNode *front = NULL, *End = NULL;  

// Function to add/enqueue a new patient to the priority queue
void pq_newPT(char *name, int priority) {
    PTNode *new = NULL, *tmp = NULL, *dup = front;
    new = (PTNode *)malloc(sizeof(PTNode));  // Allocate memory for a new node
    strcpy(new->name, name);                 // Set the patient's name
    new->priority = priority;                // Set the patient's priority
    new->next = NULL;                        // Initialize the next pointer to NULL

    if (front == NULL) {                     // If the queue is empty
        front = new;                         // The new node becomes the front
        return;
    }

    if ((front->priority) > (new->priority)) {  // If new node has a higher priority
        tmp = dup;
        dup = new;
        dup->next = tmp;
        front = dup;                         // The new node becomes the front
        return;
    }

    // Traverse the queue to find the correct position for the new node
    while (dup->next != NULL) {
        if ((dup->next->priority) > (new->priority)) {
            new->next = dup->next;
            dup->next = new;                 // Insert the node at the correct position
            return;
        }
        dup = dup->next;
    }

    dup->next = new;                         // Insert the node at the end of the queue
    return;
}

// Function to remove/dequeue the patient with the highest priority
void pq_processPT(void) {
    if (front == NULL) {                     // If the queue is empty
        return;
    }

    PTNode *tmp = front;
    front = front->next;                     // Move the front pointer to the next node
    free(tmp);                               // Free the memory of the removed node
    return;
}

// Function to retrieve the name of the front patient without removing them
char *pq_frontName() {
    if (front == NULL) {
        printf("Queue doesn't have patients..\n");
        return NULL;
    } else {
        return front->name;
    }
}

/* Function to retrieve the priority of the front patient without removing them
int pq_frontPriority() {
    if (front == NULL) {
        printf("Queue doesn't have patients..\n");
        return 0;
    } else {
        return front->priority;
    }
}
*/
// Function to upgrade a patient's priority in the queue
void pq_upgradePT(char *name, int newPriority) {
    PTNode *tmp = front, *T = NULL;

    // Check if the front node matches the given name
    if (strcmp(tmp->name, name) == 0) {
        T = front;
        front = front->next;                // Remove the node from the queue
        free(T);
        return;
    }

    // Traverse the list to find the node with the given name
    while (tmp->next != NULL) {
        if (strcmp(tmp->next->name, name) == 0) {
            T = tmp->next;
            tmp->next = tmp->next->next;    // Remove the node from the list
            free(T);
            return;
        }
        tmp = tmp->next;
    }
}

// Function to clear all nodes in the priority queue
void pq_clear(void) {
    PTNode *tmp = NULL;
    while (front != NULL) {
        tmp = front;
        front = front->next;                // Move the front pointer to the next node
        free(tmp);                          // Free the memory of the removed node
    }
    return;
}

// Function to check if the queue is empty
int pq_isEmpty() {
    return (front == NULL) ? 0 : 1;         // Return 0 if empty, 1 otherwise
}

// Function to display the current state of the queue
void display(void) {
    PTNode *tmp = front;
    printf("Current patient queue:");
    if (tmp == NULL) {
        printf(" (empty)\n");
        return;
    }
    while (tmp != NULL) {
        printf(" %d:%s", tmp->priority, tmp->name);
        tmp = tmp->next;
        if (tmp != NULL)
            printf(", ");
    }
    printf(" (not empty)\n");
}

// Main function to handle user interactions and queue operations
int main() {
    char choice;
    char name[100];
    int priority;
    char *nam;

    while (1) {
        display();  // Print the current state of the queue
        printf("Options: N)newPT, F)frontPT, U)upgradePT, P)processPT, C)clear, Q)quit?\n");
        scanf(" %c", &choice);  // Read the user's choice

        switch (choice) {
            case 'N': // Add a new patient to the queue
                printf("Enter the Name: ");
                scanf(" %s", name);
                printf("Enter the Priority: ");
                scanf("%d", &priority);
                pq_newPT(name, priority);
                break;

            case 'F': // Display the front patient's details
                nam = pq_frontName();
                //priority = pq_frontPriority();
                if (nam) {
                    printf("Front patient: %s with priority %d\n", nam, priority);
                }
                break;

            case 'U': // Upgrade a patient's priority
                printf("Enter the Name: ");
                scanf(" %s", name);
                printf("Enter the New Priority: ");
                scanf("%d", &priority);
                pq_upgradePT(name, priority);
                pq_newPT(name, priority);
                break;

            case 'P': // Process the front patient
                pq_processPT();
                break;

            case 'C': // Clear the queue
                pq_clear();
                break;

            case 'Q': // Quit the program
                printf("\nExiting.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

