#include <stdio.h>
#include <pthread.h>
 
// Shared variable
int sum = 0;
 
// Mutex for synchronizing access to 'sum'
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 
// Thread function
void *countgold(void *param)
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex); // Lock the mutex
        sum += 1;
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}
 
int main() {
    pthread_t tid1, tid2;
 
    // Create threads
    pthread_create(&tid1, NULL, countgold, NULL);
    pthread_create(&tid2, NULL, countgold, NULL);
 
    // Wait for threads to complete
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    // Print the final value of sum
    printf("sum is %d\n", sum);
 
    // Destroy the mutex
    pthread_mutex_destroy(&mutex);
 
    return 0;
}
