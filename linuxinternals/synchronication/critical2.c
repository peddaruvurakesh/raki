#include <pthread.h>
#include <stdio.h>

int balance = 1000;  // Shared resource

void* deposit(void* arg) {
    for (int i = 0; i < 5000; i++) {
        balance += 1;  // Critical section: modifying shared resource
    }
    return NULL;
}

void* withdraw(void* arg) {
    for (int i = 0; i < 3000; i++) {
        balance -= 1;  // Critical section: modifying shared resource
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Print final balance
    printf("Final balance: %d\n", balance);

    return 0;
}

