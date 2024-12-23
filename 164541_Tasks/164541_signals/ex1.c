#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("Caught SIGINT signal!\n");
        exit(0);
    }
}

int main() {
    // Set up signal handler
    signal(SIGINT, signal_handler);

    printf("Press Ctrl+C to generate a SIGINT signal\n");

    while (1) {
        // Simulate some work
        sleep(1);
    }

    return 0;
}

