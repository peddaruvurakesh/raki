#include <pthread.h>
#include <stdio.h>

int balance = 1000; // Shared variable
//pthread_mutex_t lock;

void* deposit(void* arg) 
{
    pthread_mutex_lock(&lock);
    balance += 500; // Deposit 500
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* withdraw(void* arg) 
{
    pthread_mutex_lock(&lock);
    balance -= 300; // Withdraw 300
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    //pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final balance: %d\n", balance);

    //pthread_mutex_destroy(&lock);
    return 0;
}

