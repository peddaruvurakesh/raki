#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 1000000

atomic_int global_counter = 0;

void* thread_function(void* arg)
{
    int local_counter = 0;

    // Increment local variable
    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        local_counter++;
    }

    // Update global counter atomically
    atomic_fetch_add(&global_counter, local_counter);

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Final global counter: %d\n", global_counter);
    return 0;
}

