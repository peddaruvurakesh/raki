#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
bool condition = false;

void *thread_func(void *arg) {
    pthread_mutex_lock(&mtx);

    while (!condition) {  // Correct: Recheck condition after waking up
        printf("Thread is waiting...\n");
        pthread_cond_wait(&cv, &mtx);  // Wait until condition is true
    }
    printf("Thread proceeds as condition is true!\n");

    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    // Simulate some work before signaling
    sleep(1);

    pthread_mutex_lock(&mtx);
    condition = true;
    pthread_cond_signal(&cv);  // Wake up the waiting thread
    pthread_mutex_unlock(&mtx);

    pthread_join(thread, NULL);
    return 0;
}

