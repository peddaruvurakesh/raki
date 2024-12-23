#include <pthread.h>
#include <stdio.h>

int counter = 0;

void* increment(void* arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        counter++; // Not thread-safe
    }
    return NULL;
}

int main() 
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter: %d\n", counter); // Result will be inconsistent
    return 0;
}
