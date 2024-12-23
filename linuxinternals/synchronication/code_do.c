#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void* thread_func(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Thread waiting on condition variable...\n");
    pthread_cond_wait(&cond, &mutex);
    printf("Thread resumed after condition signal.\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread, NULL, thread_func, NULL);

    sleep(1); // Simulate work before signaling
    pthread_mutex_lock(&mutex);
    printf("Signaling condition variable...\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

