#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// User-defined signal handler
void my_sigaction(int signo, siginfo_t *info, void *context) {
    printf("\nSignal received: %d\n", signo);
    if (info != NULL) {
        printf("Signal sent by process with PID: %d\n", info->si_pid);
    }
}

int main() {
    struct sigaction sa;

    // Configure sa_sigaction
    sa.sa_sigaction = my_sigaction;
    sa.sa_flags = SA_SIGINFO; // Use sa_sigaction instead of sa_handler

    // Register signal handlers
    sigaction(SIGINT, &sa, NULL);  // Ctrl-C
    sigaction(SIGQUIT, &sa, NULL); // Ctrl-\

    printf("Process PID: %d\n", getpid());
    printf("Send signals using Ctrl-C or Ctrl-\\, or use `kill -<signal> %d` from another terminal.\n", getpid());

    // Wait indefinitely
    while (1) {
        pause();
    }

    return 0;
}

