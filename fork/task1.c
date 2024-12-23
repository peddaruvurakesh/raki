#include <stdio.h>
#include <unistd.h>  // For fork()

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // Error: fork failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child Process
        printf("This is the child process. My PID is %d, and my parent PID is %d.\n", getpid(), getppid());
    } else {
        // Parent Process
        printf("This is the parent process. My PID is %d, and I created a child process with PID %d.\n", getpid(), pid);
    }

    return 0;
}

