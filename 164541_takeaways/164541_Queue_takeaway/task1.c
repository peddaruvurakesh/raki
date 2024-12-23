#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Patient Node
typedef struct PTNode {
    char name[100];
    int priority;
    struct PTNode* next;
} PTNode;

// Define the structure for the Priority Queue
typedef struct {
    PTNode* front;
} LinkedListPQ;

// Function prototypes
void initPQ(LinkedListPQ* pq);
void freePQ(LinkedListPQ* pq);
void newPT(LinkedListPQ* pq, const char* name, int priority);
char* processPT(LinkedListPQ* pq);
char* frontName(LinkedListPQ* pq);
int frontPriority(LinkedListPQ* pq);
void upgradePT(LinkedListPQ* pq, const char* name, int newPriority);
int isEmpty(LinkedListPQ* pq);
void clear(LinkedListPQ* pq);
char* toString(LinkedListPQ* pq);

// Initialize the Priority Queue
void initPQ(LinkedListPQ* pq) {
    pq->front = NULL;
}

// Free all allocated memory
void freePQ(LinkedListPQ* pq) {
    clear(pq);
}

// Add a new patient to the queue
void newPT(LinkedListPQ* pq, const char* name, int priority) {
    PTNode* newNode = (PTNode*)malloc(sizeof(PTNode));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;

    if (!pq->front || pq->front->priority > priority) {
        // Insert at the front
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        // Find the correct position to insert
        PTNode* current = pq->front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Process the most urgent patient
char* processPT(LinkedListPQ* pq) {
    if (isEmpty(pq)) {
        return "Error: No patients in the queue.";
    }

    PTNode* temp = pq->front;
    pq->front = pq->front->next;

    char* processedName = (char*)malloc(100 * sizeof(char));
    strcpy(processedName, temp->name);
    free(temp);

    return processedName;
}

// Get the name of the most urgent patient
char* frontName(LinkedListPQ* pq) {
    if (isEmpty(pq)) {
        return "Error: No patients in the queue.";
    }
    return pq->front->name;
}

// Get the priority of the most urgent patient
int frontPriority(LinkedListPQ* pq) {
    if (isEmpty(pq)) {
        fprintf(stderr, "Error: No patients in the queue.\n");
        exit(EXIT_FAILURE);
    }
    return pq->front->priority;
}

// Upgrade the priority of a patient
void upgradePT(LinkedListPQ* pq, const char* name, int newPriority) {
    PTNode* current = pq->front;
    PTNode* prev = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0 && current->priority > newPriority) {
            if (prev) {
                prev->next = current->next;
            } else {
                pq->front = current->next;
            }
            newPT(pq, name, newPriority);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    fprintf(stderr, "Error: Patient not found or priority not more urgent.\n");
}

// Check if the queue is empty
int isEmpty(LinkedListPQ* pq) {
    return pq->front == NULL;
}

// Clear the queue
void clear(LinkedListPQ* pq) {
    while (!isEmpty(pq)) {
        PTNode* temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
    }
}

// Convert the queue to a string
char* toString(LinkedListPQ* pq) {
    char* result = (char*)malloc(1024 * sizeof(char));
    strcpy(result, "{");
    PTNode* current = pq->front;

    while (current) {
        char buffer[128];
        sprintf(buffer, "%d:%s", current->priority, current->name);
        strcat(result, buffer);
        if (current->next) {
            strcat(result, ", ");
        }
        current = current->next;
    }
    strcat(result, "}");
    return result;
}

// Test the Priority Queue
int main() {
    LinkedListPQ pq;
    initPQ(&pq);

    newPT(&pq, "Devansh", 5);
    newPT(&pq, "Taksha", 4);
    newPT(&pq, "Jaypal", 8);
    newPT(&pq, "Arpit", 5);
    newPT(&pq, "Neel", 5);
    newPT(&pq, "Vishal", 2);

    printf("Current patient queue: %s\n", toString(&pq));

    printf("Processing patient: %s\n", processPT(&pq));
    printf("Current patient queue: %s\n", toString(&pq));

    upgradePT(&pq, "Neel", 1);
    printf("After upgrading Neel's priority: %s\n", toString(&pq));

    clear(&pq);
    freePQ(&pq);

    return 0;
}

