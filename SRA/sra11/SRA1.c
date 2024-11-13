#include <stdio.h>

#define MAX 10000

// Function to find how many employees can't get their preferred dosa
int findUnservedEmployees(int n, int stack[], int queue[]) {
    int front = 0, stackIndex = 0, unservedCount = 0;
    int moves = 0;  // Count of employees that have moved to the back of the queue

    // We simulate until all dosas are checked or the employees stop getting served
    while (moves < n && stackIndex < n) {
        if (queue[front] == stack[stackIndex]) {
            // Employee gets their preferred dosa
            stackIndex++;  // Remove dosa from the stack
            front = (front + 1) % n;  // Remove employee from the queue
            moves = 0;     // Reset moves since a match happened
        } else {
            // Move the employee to the back of the queue
            front = (front + 1) % n;  // Move to the back
            moves++; // Count the number of moves when employee goes to back
        }
    }

    // The unserved employees are those left in the queue after all possible moves
    unservedCount = n - stackIndex;

    return unservedCount;
}

int main() {
    int n, i;

    // Input number of employees and dosas
    printf("Enter the number of employees and dosas: ");
    scanf("%d", &n);

    int stack[MAX], queue[MAX];

    // Input the stack of dosas (top first)
    printf("Enter the stack of dosas (0 for sada, 1 for masala):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }

    // Input the queue of employee preferences
    printf("Enter the queue of employee preferences (0 for sada, 1 for masala):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Calculate the number of unserved employees
    int unserved = findUnservedEmployees(n, stack, queue);
    printf("The number of employees who will not be able to have the breakfast: %d\n", unserved);

    return 0;
}

