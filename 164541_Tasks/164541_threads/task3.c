#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


pthread_mutex_t lock;


void *write_message(void *arg)
{
    
    pthread_mutex_lock(&lock);

    // Seed the random number generator using the process ID (less ideal for threads, but works here)
    srand(getpid());
    
    // Generate a random number between 0 and 9
    int t = rand() % 10;
    
    
    printf("%d\n", t);

    
    sleep(t);

    // Print the message with the thread ID (thread ID passed via `arg`)
    printf("I am thread %d\n", *(int *)arg + 1);

   
    pthread_mutex_unlock(&lock);

    // Exit the thread
    return NULL;
}

int main()
{
    // Declare an array of 10 threads
    pthread_t thread[10];
    int i;

    
    printf("in main..\n");

    // Initialize the mutex 
    pthread_mutex_init(&lock, NULL);

    // Array to hold thread arguments (thread IDs)
    int arr[10];
    for (i = 0; i < 10; i++)
        arr[i] = i;

    // Create 10 threads, each executing `write_message` with a unique ID
    for (i = 0; i < 10; i++)
        pthread_create(&thread[i], 0, write_message, (void *)&arr[i]);

    // Wait for all threads to finish execution
    for (i = 0; i < 10; i++)
        pthread_join(thread[i], NULL);

    // Destroy the mutex after all threads are done
    pthread_mutex_destroy(&lock);

    
    printf("I am the final thread\n");

    // Exit the program
    return 0;
}

