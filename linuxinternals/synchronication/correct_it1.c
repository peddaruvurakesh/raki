#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared variables
int money = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

// Function to deposit money
void deposit(int amount) {
    pthread_mutex_lock(&m);             // Lock the mutex
    money += amount;                    // Deposit money
    printf("Deposited: %d, Total Money: %d\n", amount, money);
    pthread_cond_signal(&cv);           // Signal waiting threads, if any
    pthread_mutex_unlock(&m);           // Unlock the mutex
}

// Function to withdraw money
void withdraw(int amount) {
    pthread_mutex_lock(&m);             // Lock the mutex
    
    while (money < amount) {            // Use a loop to avoid spurious wakeups
        printf("Waiting to withdraw: %d, Available Money: %d\n", amount, money);
        pthread_cond_wait(&cv, &m);     // Wait for condition (money >= amount)
    }
    
    money -= amount;                    // Withdraw money
    printf("Withdrew: %d, Remaining Money: %d\n", amount, money);
    pthread_mutex_unlock(&m);           // Unlock the mutex
}

// Depositor thread function
void* depositor(void* arg) {
    int amount = *(int*)arg;
    deposit(amount);
    return NULL;
}

// Withdrawer thread function
void* withdrawer(void* arg) {
    	int amount = *(int*)arg;
    withdraw(amount);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3, t4;
    int deposit_amount1 = 100;
    int deposit_amount2 = 50;
    int withdraw_amount1 = 70;
    int withdraw_amount2 = 120;

    // Create withdrawer threads
    pthread_create(&t1, NULL, withdrawer, &withdraw_amount1);
    pthread_create(&t2, NULL, withdrawer, &withdraw_amount2);

    // Sleep to simulate delay before deposit
    sleep(1);

    // Create depositor threads
    pthread_create(&t3, NULL, depositor, &deposit_amount1);
    pthread_create(&t4, NULL, depositor, &deposit_amount2);

    // Wait for all threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&m);
    pthread_cond_destroy(&cv);

    return 0;
}

