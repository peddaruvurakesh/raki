#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sig;
    struct sigaction sa;
	
    printf("Process PID : %d\n",getpid());
    // Loop through all signals from 1 to NSIG (number of signals)
    for (sig = 1; sig < NSIG; sig++) {
        // Initialize the sigaction structure
        sa.sa_flags = 0;
        sa.sa_handler = SIG_IGN;  // Set the signal handler to SIG_IGN (ignore the signal)

        // Clear the signal mask (no signals are blocked)
        sigemptyset(&sa.sa_mask);

        // Try to set the signal handler for the current signal
        if (sigaction(sig, &sa, NULL) == -1) {
            // If setting the signal handler fails, print an error message
            printf("sigaction failed");
            printf("Unable to ignore signal %d\n", sig);
        }
    }

    // Manage signal processing for 30 seconds (you can change this delay to 60 for a full 60-second wait)
    int delay = 30;
    //while (delay != 0) delay = sleep(delay);  // Sleep for 30 seconds, or until interrupted

    printf("Program finished after sleep.\n");
    return 0;
}

