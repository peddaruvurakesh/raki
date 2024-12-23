#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_handler(int sig) {
    // This is the custom signal handler function
    printf("Entered signal handler for signal %d\n", sig);
}

int main() {
    int sig;
    struct sigaction sa;

    // Loop through all signals from 1 to NSIG
    for (sig = 1; sig < NSIG; sig++) {
        // Initialize the sigaction structure
        sa.sa_flags = 0;
        sa.sa_handler = my_handler;  // Set the custom handler to my_handler

        // Clear the signal mask (no signals are blocked)
        sigemptyset(&sa.sa_mask);

        // Try to set the signal handler for the current signal
        if (sigaction(sig, &sa, NULL) == -1) {
            // If setting the signal handler fails, print an error message
            perror("sigaction");
            printf("Unable to handle signal %d\n", sig);
        }
    }

    // Manage signal processing for 30 seconds, which will be interrupted by signals
    int delay = 30;
    while (delay != 0) {
        delay = sleep(delay);  // Sleep for a maximum of 30 seconds
        // If a signal was received during sleep, sleep() will return the remaining time
    }

    printf("Program finished after sleep.\n");
    return 0;
}

