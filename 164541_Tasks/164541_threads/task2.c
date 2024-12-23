#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 5  // Number of threads

// Function executed by each thread
void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("I am thread %d\n", thread_id);
    free(arg); // Free dynamically allocated memory
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N]; // Array to hold thread IDs
    int i;

    // Create N threads
    for (i = 0; i < N; i++) {
        int* thread_id = malloc(sizeof(int)); // Allocate memory for thread ID
        if (thread_id == NULL) {
            perror("Failed to allocate memory");
            exit(1);
        }
        *thread_id = i; // Pass thread index as argument
        if (pthread_create(&threads[i], NULL, thread_function, thread_id) != 0) {
            perror("Failed to create thread");
            exit(1);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < N; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(1);
        }
    }

    // Main thread message
    printf("I am the main thread\n");
    return 0;
}

