#include <pthread.h>

// Shared variables
int money = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

void deposit(int amount) {
    pthread_mutex_lock(&m);             // Lock the mutex
    money += amount;                    // Deposit money
    pthread_cond_signal(&cv);           // Signal waiting threads, if any
    pthread_mutex_unlock(&m);           // Unlock the mutex
}

void withdraw(int amount) {
    pthread_mutex_lock(&m);             // Lock the mutex
    
    while (money < amount) {            // Use a loop to avoid spurious wakeups
        pthread_cond_wait(&cv, &m);     // Wait for condition (money >= amount)
    }
    
    money -= amount;                    // Withdraw money
    pthread_mutex_unlock(&m);           // Unlock the mutex
}

