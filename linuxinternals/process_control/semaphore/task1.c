
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

int main() {
    int flags, sval;
    unsigned int value;
    sem_t *sem;

    sem = sem_open("/sem1", O_CREAT | O_RDWR, 0660, 2);

    if (sem == SEM_FAILED) {
        perror("sem_open fail:");
        return -1;
    } else {
       
        printf("Semaphore created successfully.\n");
    }

    sem_getvalue(sem,&sval);
    printf("\n before sem_wait semaphore value =(%d)\n");

    sem_wait(sem);
    sem_getvalue(sem ,&sval);
    printf("\n after sem_wait semaphore value =(%d)\n");


    printf("\n process 1: executing critical section\n");
    sleep(5);
    sem_post(sem);
    printf("\n critical section executed\n");
    sem_getvalue(sem , &sval);
     printf("\n after sem_post semaphore =(%d)\n,sval");
}


   

