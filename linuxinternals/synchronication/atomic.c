#include <stdatomic.h>
#include <pthread.h>
#include <stdio.h>

atomic_int counter = 0;

void* increment(void* arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        atomic_fetch_add(&counter, 1); // Thread-safe increment
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

    printf("Counter: %d\n", atomic_load(&counter)); // Result will always be 2000000
    return 0;
}

