#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define INCREMENTS 1000

int counter = 0;             // Shared global counter
pthread_mutex_t lock;        // Mutex for synchronization

// Thread function
void* increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        pthread_mutex_lock(&lock);  // Lock the mutex
        counter++;      	// Safely increment the counter
        printf("%d\n",counter);
	pthread_mutex_unlock(&lock);  // Unlock the mutex
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);  // Initialize the mutex

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Counter Value (with locks): %d\n", counter);

    pthread_mutex_destroy(&lock);  // Destroy the mutex
    return 0;
}

