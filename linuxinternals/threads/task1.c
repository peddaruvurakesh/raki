#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define INCREMENTS 1000

int counter = 0;  // Shared global counter

// Thread function
void* increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS; i++) {
     
	
	    counter++;  // Increment the shared counter
     printf("%d\n ",counter);
    }


    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Counter Value (without locks): %d\n", counter);

    return 0;
}

