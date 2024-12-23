#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Patient Node
typedef struct node {
    char name[100];
    int priority;
    struct node* next;
} node;

// Define the structure for the Priority Queue
typedef struct {
    node* front;
} priorityqueue;

// Function prototypes
void initPQ(priorityqueue* pq);
void freePQ(priorityqueue* pq);
void newPT(priorityqueue* pq, const char* name, int priority);
char* processPT(priorityqueue* pq);
//char* frontName(priorityqueue* pq);
//int frontPriority(priorityqueue* pq);
void upgradePT(priorityqueue* pq, const char* name, int newPriority);
int isEmpty(priorityqueue* pq);
void clear(priorityqueue* pq);
char* toString(priorityqueue* pq);

// Initialize the Priority Queue
void initPQ(priorityqueue* pq) {
    pq->front = NULL;
}

// Free all allocated memory
void freePQ(priorityqueue* pq) {
    clear(pq);
}

// Add a new patient to the queue
void newPT(priorityqueue* pq, const char* name, int priority) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;

    if (!pq->front || pq->front->priority > priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        node* current = pq->front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Process the most urgent patient
char* processPT(priorityqueue* pq) {
    if (isEmpty(pq)) {
        return "Error: No patients in the queue.";
    }

    node* temp = pq->front;
    pq->front = pq->front->next;

    char* processedName = (char*)malloc(100 * sizeof(char));
    strcpy(processedName, temp->name);
    free(temp);

    return processedName;
}


/* Get the name of the most urgent patient
char* frontName(priorityqueue* pq) {
    if (isEmpty(pq)) {
        return "Error: No patients in the queue.";
    }
    return pq->front->name;
}
*/



/* Get the priority of the most urgent patient
int frontPriority(priorityqueue* pq) {
    if (isEmpty(pq)) {
        fprintf(stderr, "Error: No patients in the queue.\n");
        exit(EXIT_FAILURE);
    }
    return pq->front->priority;
}
*/



// Upgrade the priority of a patient
void upgradePT(priorityqueue* pq, const char* name, int newPriority) {
    node* current = pq->front;
    node* prev = NULL;

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
int isEmpty(priorityqueue* pq) {
    return pq->front == NULL;
}

// Clear the queue
void clear(priorityqueue* pq) {
    while (!isEmpty(pq)) {
        node* temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
    }
}

// Convert the queue to a string
char* toString(priorityqueue* pq) {
    char* result = (char*)malloc(1024 * sizeof(char));
    strcpy(result, "{");
    node* current = pq->front;

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

// Test the Priority Queue with User Input
int main() {
    priorityqueue pq;
    initPQ(&pq);

    int choice;
    char name[100];
    int priority;

    do {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Add a new patient\n");
        printf("2. Process the most urgent patient\n");
        printf("3. Upgrade a patient's priority\n");
        printf("4. Display the patient queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        //scanf("%d", &choice);
	if(scanf("%d",&choice) !=1)
		printf("\n");
    
/*        if(scanf(" %d",&choice)!=1);
        {
                while(getchar()!='\n');
        }
*/
        switch (choice) {
            case 1:
                printf("Enter patient's name: ");
                scanf("%s", name);
                printf("Enter patient's priority: ");
                scanf("%d", &priority);
                newPT(&pq, name, priority);
                printf("Patient added.\n");
                break;

            case 2:
                if (!isEmpty(&pq)) {
                    char* processed = processPT(&pq);
                    printf("Processed patient: %s\n", processed);
                    free(processed);
                } else {
                    printf("No patients in the queue.\n");
                }
                break;

            case 3:
                printf("Enter patient's name to upgrade: ");
                scanf("%s", name);
                printf("Enter new priority: ");
                scanf("%d", &priority);
                upgradePT(&pq, name, priority);
                break;

            case 4:
                if (!isEmpty(&pq)) {
                    char* queueString = toString(&pq);
                    printf("Current patient queue: %s\n", queueString);
                    free(queueString);
                } else {
                    printf("The queue is empty.\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 5);

    freePQ(&pq);
    return 0;
}

