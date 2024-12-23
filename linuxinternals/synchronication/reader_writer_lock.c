#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;          // Mutex to protect shared state
    pthread_cond_t readers_ok;      // Condition for readers
    pthread_cond_t writer_ok;       // Condition for writers
    int readers;                    // Number of active readers
    int writers;                    // Number of active writers (0 or 1)
    int waiting_writers;            // Number of writers waiting
} rw_lock_t;

// Initialize the reader-writer lock
void rw_lock_init(rw_lock_t* lck) {
    pthread_mutex_init(&lck->mutex, NULL);
    pthread_cond_init(&lck->readers_ok, NULL);
    pthread_cond_init(&lck->writer_ok, NULL);
    lck->readers = 0;
    lck->writers = 0;
    lck->waiting_writers = 0;
}

// Reader lock
void reader_lock(rw_lock_t* lck) {
    pthread_mutex_lock(&lck->mutex);

    // Wait if there is an active writer or writers waiting
    while (lck->writers > 0 || lck->waiting_writers > 0) {
        pthread_cond_wait(&lck->readers_ok, &lck->mutex);
    }

    lck->readers++;  // Increment the reader count
    pthread_mutex_unlock(&lck->mutex);
}

// Writer lock
void writer_lock(rw_lock_t* lck) {
    pthread_mutex_lock(&lck->mutex);

    // Indicate that a writer is waiting
    lck->waiting_writers++;

    // Wait if there are active readers or a writer
    while (lck->readers > 0 || lck->writers > 0) {
        pthread_cond_wait(&lck->writer_ok, &lck->mutex);
    }

    // Indicate that this writer is active
    lck->waiting_writers--;
    lck->writers = 1;
    pthread_mutex_unlock(&lck->mutex);
}

// Reader unlock
void reader_unlock(rw_lock_t* lck) {
    pthread_mutex_lock(&lck->mutex);

    lck->readers--;  // Decrement the reader count

    // If no more readers, signal a waiting writer
    if (lck->readers == 0) {
        pthread_cond_signal(&lck->writer_ok);
    }

    pthread_mutex_unlock(&lck->mutex);
}

// Writer unlock
void writer_unlock(rw_lock_t* lck) {
    pthread_mutex_lock(&lck->mutex);

    lck->writers = 0;  // Mark the writer as inactive

    // Prefer signaling waiting writers, then readers
    if (lck->waiting_writers > 0) {
        pthread_cond_signal(&lck->writer_ok);
    } else {
        pthread_cond_broadcast(&lck->readers_ok);
    }

    pthread_mutex_unlock(&lck->mutex);
}

// Destroy the reader-writer lock
void rw_lock_destroy(rw_lock_t* lck) {
    pthread_mutex_destroy(&lck->mutex);
    pthread_cond_destroy(&lck->readers_ok);
    pthread_cond_destroy(&lck->writer_ok);
}

