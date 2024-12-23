#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ITEMS 5

// Shared resource
int buffer = 0;
pthread_mutex_t lock; // Mutex for synchronization

// Producer function
void* producer(void* arg)
{
    for (int i = 0; i < MAX_ITEMS; i++) 
    {
        pthread_mutex_lock(&lock); // Lock the mutex
        buffer++; // Produce an item
        printf("Produced: %d\n", buffer);
        pthread_mutex_unlock(&lock); // Unlock the mutex
        usleep(120000); 
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_mutex_lock(&lock); // Lock the mutex
        if (buffer > 0) {
            printf("Consumed: %d\n", buffer);
//            buffer--; // Consume an item
        } else {
            printf("Buffer empty, waiting for producer...\n");
        }
        pthread_mutex_unlock(&lock); // Unlock the mutex
       usleep(150000); 
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);
    
    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    
    // Wait for both threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    
    // Destroy the mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}

