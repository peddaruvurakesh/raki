#include <stdio.h>
#include <unistd.h>  
#include <sys/wait.h>  // For wait()

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child Process
        printf("This is the child process. My PID is %d.\n", getpid());
        _exit(0);  // Child exits
    } else {
        // Parent Process
        int status;
        wait(&status);  // Wait for child to finish
        printf("This is the parent process. My PID is %d. Child terminated.\n", getpid());
    }

    return 0;
}

