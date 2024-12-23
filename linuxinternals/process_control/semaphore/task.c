#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

int main() {
    int sval;
    sem_t *sem;

    // Create or open the semaphore
    sem = sem_open("/sem1", O_CREAT | O_RDWR, 0660, 2);
    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        return -1;
    }

    printf("Semaphore created successfully.\n");

    // Get and print the semaphore value before sem_wait
    if (sem_getvalue(sem, &sval) == -1) {
        perror("sem_getvalue failed");
        return -1;
    }
    printf("\nBefore sem_wait, semaphore value = %d\n", sval);

    // Wait on the semaphore
    if (sem_wait(sem) == -1) {
        perror("sem_wait failed");
        return -1;
    }

    // Get and print the semaphore value after sem_wait
    if (sem_getvalue(sem, &sval) == -1) {
        perror("sem_getvalue failed");
        return -1;
    }
    printf("\nAfter sem_wait, semaphore value = %d\n", sval);

    printf("\nProcess 1: Executing critical section\n");
    sleep(5); // Simulate critical section execution
    printf("\nCritical section executed\n");

    // Post (signal) the semaphore
    if (sem_post(sem) == -1) {
        perror("sem_post failed");
        return -1;
    }

    // Get and print the semaphore value after sem_post
    if (sem_getvalue(sem, &sval) == -1) {
        perror("sem_getvalue failed");
        return -1;
    }
    printf("\nAfter sem_post, semaphore value = %d\n", sval);

    // Close the semaphore
    if (sem_close(sem) == -1) {
        perror("sem_close failed");
        return -1;
    }

    // Optionally, unlink the semaphore if it's no longer needed
//    if (sem_unlink("/sem1") == -1) {
  //      perror("sem_unlink failed");
    //    return -1;
    //}

    return 0;
}

