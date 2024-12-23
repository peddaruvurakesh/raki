#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "event.h"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// Global Variables
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t visitor_ready = PTHREAD_COND_INITIALIZER;
pthread_cond_t doctor_ready = PTHREAD_COND_INITIALIZER;

int current_time = 0;
int patient_count = 0, salesrep_count = 0, reporter_count = 0;
int visitor_available = 0; // Flag for visitor availability
int patient_quota = 25, salesrep_quota = 3;
int doctor_available = 1;
eventQ event_queue;

// Visitor Data Structure
typedef struct {
    char type;
    int arrival_time;
    int duration;
    int id;
} Visitor;

// Time Conversion
void format_time(int minutes, char *buffer) {
    int hours = 9 + minutes / 60; // Starts from 9:00am
    int mins = minutes % 60;
    char period[] = "am";
    if (hours >= 12) {
        if (hours > 12) hours -= 12;
        strcpy(period, "pm");
    }
    sprintf(buffer, "%02d:%02d%s", hours, mins, period);
}

// Print Events
void print_event(const char *prefix, char *color, int start_time, int end_time, const char *message) {
    char start_buffer[10], end_buffer[10];
    format_time(start_time, start_buffer);
    if (end_time != -1) format_time(end_time, end_buffer);

    if (end_time == -1)
        printf("%s[%s] %s%s\n", prefix, start_buffer, message, RESET);
    else
        printf("%s[%s - %s] %s%s\n", prefix, start_buffer, end_buffer, message, RESET);
}

// Doctor Thread
void *doctor(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        while (doctor_available && !visitor_available) {
            pthread_cond_wait(&doctor_ready, &lock);
        }

        if (!doctor_available) {
            pthread_mutex_unlock(&lock);
            break;
        }

        visitor_available = 0; // Reset visitor availability
        pthread_cond_signal(&visitor_ready); // Notify visitor
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

// Visitor Thread
void *visitor(void *arg) {
    Visitor *v = (Visitor *)arg;

    pthread_mutex_lock(&lock);
    while (!visitor_available) {
        pthread_cond_wait(&visitor_ready, &lock);
    }

    print_event("", BLUE, v->arrival_time, v->arrival_time + v->duration, 
                v->type == 'P' ? "Patient is in doctor's chamber" :
                v->type == 'R' ? "Reporter is in doctor's chamber" : 
                "Sales representative is in doctor's chamber");

    visitor_available = 0;
    pthread_cond_signal(&doctor_ready); // Notify doctor is free
    pthread_mutex_unlock(&lock);

    free(v);
    return NULL;
}

// Process Events
void process_event(event e) {
    pthread_mutex_lock(&lock);

    if (e.type == 'P' && patient_count < patient_quota) {
        patient_count++;
        Visitor *v = malloc(sizeof(Visitor));
        v->type = 'P';
        v->arrival_time = e.time;
        v->duration = e.duration;
        pthread_t thread;
        pthread_create(&thread, NULL, visitor, v);
    } else if (e.type == 'R') {
        Visitor *v = malloc(sizeof(Visitor));
        v->type = 'R';
        v->arrival_time = e.time;
        v->duration = e.duration;
        pthread_t thread;
        pthread_create(&thread, NULL, visitor, v);
    } else if (e.type == 'S' && salesrep_count < salesrep_quota) {
        salesrep_count++;
        Visitor *v = malloc(sizeof(Visitor));
        v->type = 'S';
        v->arrival_time = e.time;
        v->duration = e.duration;
        pthread_t thread;
        pthread_create(&thread, NULL, visitor, v);
    } else {
        char time_buffer[10];
        format_time(e.time, time_buffer);
        printf("[%s] Visitor %c denied service.\n", time_buffer, e.type);
    }

    visitor_available = 1; // Set visitor ready
    pthread_cond_signal(&doctor_ready); // Notify doctor
    pthread_mutex_unlock(&lock);
}

// Main Thread
int main() {
    pthread_t doctor_thread;

    // Initialize Event Queue
    event_queue = initEQ("ARRIVAL.txt");

    // Create Doctor Thread
    pthread_create(&doctor_thread, NULL, doctor, NULL);

    // Process Events
    while (!emptyQ(event_queue)) {
        pthread_mutex_lock(&lock);

        // Get next event
        event e = nextevent(event_queue);
        event_queue = delevent(event_queue);
        current_time = e.time;

        // Print Arrival
        char time_buffer[10];
        format_time(e.time, time_buffer);
        printf("[%s] %s arrives\n", time_buffer,
               e.type == 'P' ? "Patient" : 
               e.type == 'R' ? "Reporter" : 
               "Sales representative");

        // Process Event
        process_event(e);

        pthread_mutex_unlock(&lock);
    }

    // Notify Doctor to Exit
    pthread_mutex_lock(&lock);
    doctor_available = 0;
    pthread_cond_signal(&doctor_ready);
    pthread_mutex_unlock(&lock);

    // Wait for Doctor Thread to Finish
    pthread_join(doctor_thread, NULL);

    printf("Doctor's session ended.\n");
    return 0;
}

