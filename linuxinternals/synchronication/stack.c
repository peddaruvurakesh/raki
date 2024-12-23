#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define STACK_SIZE 5  

// Structure definition for a thread-safe stack
typedef struct {
    int buffer[STACK_SIZE];       // Array to hold the stack elements
    int top;                     // Index of the top element in the stack 
    pthread_mutex_t mutex;       // Mutex to synchronize access to the stack
    pthread_cond_t not_empty;    // Condition variable to signal that the stack is not empty
    pthread_cond_t not_full;     // Condition variable to signal that the stack is not full
} Stack;

// Global stack initialization
Stack stack = {
    .top = -1,                            // Stack starts empty
    .mutex = PTHREAD_MUTEX_INITIALIZER,   // Initialize the mutex
    .not_empty = PTHREAD_COND_INITIALIZER,// Initialize the not_empty condition variable
    .not_full = PTHREAD_COND_INITIALIZER  // Initialize the not_full condition variable
};

// Push function: Adds an item to the stack
void push(Stack *s, int item)
{
    pthread_mutex_lock(&s->mutex);  

    // Wait if the stack is full
    while (s->top == STACK_SIZE - 1) 
    {
        pthread_cond_wait(&s->not_full, &s->mutex); // Wait for a signal that the stack is not full
    }

    s->buffer[++s->top] = item;   
    pthread_cond_signal(&s->not_empty); // Signal that the stack is not empty
    pthread_mutex_unlock(&s->mutex);   
}

// Pop function: 
int pop(Stack *s)
{
    pthread_mutex_lock(&s->mutex);  

    // Wait if the stack is empty
    while (s->top == -1)
    {
        pthread_cond_wait(&s->not_empty, &s->mutex); // Wait for a signal that the stack is not empty
    }

    int item = s->buffer[s->top--]; 
    pthread_cond_signal(&s->not_full); // Signal that the stack is not full (wakes up waiting producers)
    pthread_mutex_unlock(&s->mutex);  

    return item; 
}

// Producer thread function
void *producer(void *arg)
{
    for (int i = 0; i < 10; i++) 
    {  
        printf("Producer pushed: %d\n", i);
        push(&stack, i);  
        sleep(1);         
    }
    return NULL;
}

// Consumer thread function
void *consumer(void *arg)
{
    sleep(20); 
    for (int i = 0; i < 10; i++) 
    {  
        int item = pop(&stack);  
        printf("Consumer popped: %d\n", item);
    }
    //sleep(1.2)
    return NULL;
}

int main() {
    pthread_t prod, cons;  

    // Create the producer thread
    pthread_create(&prod, NULL, producer, NULL);
    // Create the consumer thread
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for the producer thread to finish
    pthread_join(prod, NULL);
    // Wait for the consumer thread to finish
    pthread_join(cons, NULL);

    return 0;
}

