#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();  // Create a new process

    if (pid == 0) {
        // This block runs in the child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else if (pid > 0) {
        // This block runs in the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    } else {
        // Fork failed
        perror("fork failed");
    }

    return 0;
}

