#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Number of threads
#define N 5
// Number of iterations for each thread
#define ITERATIONS 3

pthread_mutex_t lock;
pthread_cond_t cond;
int current_thread = 0; // Tracks which thread's turn it is

// Without synchronization: Threads print numbers in any order
void *unsynchronized_print(void *arg) {
    int thread_id = *(int *)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        printf("Unsynchronized: Thread %d\n", thread_id + 1);
        sleep(1);
    }
    return NULL;
}

// With synchronization: Threads print numbers in order
void *synchronized_print(void *arg) {
    int thread_id = *(int *)arg;
    for (int i = 0; i < ITERATIONS; i++) {
//      while(1){
  	  pthread_mutex_lock(&lock);

        // Wait until it's this thread's turn
        while (current_thread != thread_id)
            pthread_cond_wait(&cond, &lock);

        // Print the thread number
        printf("Synchronized: Thread %d\n", thread_id + 1);

        // Update the current thread to the next in sequence
        current_thread = (current_thread + 1) % N;

        // Signal the next thread
        pthread_cond_broadcast(&cond);

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[N];
    int thread_ids[N];

    // Initialize thread IDs
    for (int i = 0; i < N; i++) {
        thread_ids[i] = i;
    }

    // **Phase 1: Unsynchronized threads**
    printf("Phase 1: Unsynchronized threads\n");
    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, unsynchronized_print, &thread_ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // **Phase 2: Synchronized threads**
    printf("\nPhase 2: Synchronized threads\n");
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, synchronized_print, &thread_ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    printf("All threads have finished.\n");
    return 0;
}

