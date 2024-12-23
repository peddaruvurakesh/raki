#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process starts (PID = %d).\n", getpid());
        sleep(10);  // Child sleeps for 2 seconds
        printf("Child process ends.\n");
    } else if (pid > 0) {
        // Parent process
        printf("Parent process starts (PID = %d, Child PID = %d).\n", getpid(), pid);
        sleep(10);  // Parent sleeps for 5 seconds
        printf("Parent process ends.\n");
    } else {
        perror("fork failed");
    }

    return 0;
}

