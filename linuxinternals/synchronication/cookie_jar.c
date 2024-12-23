#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define TOTAL_COOKIES 5  // Number of cookies in the jar
#define NUM_CHILDREN 8   // Number of children trying to take cookies

sem_t cookie_jar;  // Semaphore to track available cookies

void* child(void* arg) {
    int id = *(int*)arg;

    printf("Child %d wants a cookie.\n", id);

    // Wait for a cookie to become available
    sem_wait(&cookie_jar);

    printf("Child %d is taking a cookie!\n", id);
    sleep(1);  // Simulate time to eat the cookie
    printf("Child %d has finished the cookie and left.\n", id);

    // Release the cookie back to the jar
    sem_post(&cookie_jar);

    return NULL;
}

int main() {
    pthread_t children[NUM_CHILDREN];
    int child_ids[NUM_CHILDREN];

    // Initialize the semaphore with the number of cookies
    sem_init(&cookie_jar, 0, TOTAL_COOKIES);

    // Create threads for each child
    for (int i = 0; i < NUM_CHILDREN; i++) {
        child_ids[i] = i + 1;
        pthread_create(&children[i], NULL, child, &child_ids[i]);
    }

    // Wait for all children to finish
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pthread_join(children[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&cookie_jar);

    printf("All children have had their cookies.\n");
    return 0;
}

