#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>

#define LARGE_OUTPUT_SIZE 70000 // Larger than typical pipe buffer size

void blocking_pipeline(const char *cmd1, char *const argv1[], const char *cmd2, char *const argv2[]) {
    int pipefd[2];
    pid_t child1, child2;
char buffer[LARGE_OUTPUT_SIZE];
    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork first child (cmd1: echo foo or a large string)
    child1 = fork();
    if (child1 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        // Child1: Write a large output to the pipe
        close(pipefd[0]); // Close unused read end

        // Simulate large output
        for (int i = 0; i < LARGE_OUTPUT_SIZE; i++) {
            if (write(pipefd[1], "x", 1) == -1) {
                perror("write failed");
                exit(EXIT_FAILURE);
            }
        }

        close(pipefd[1]); // Close the write end
        exit(EXIT_SUCCESS);
    }
    assert(child1 > 0); // Ensure the first child was created successfully

    // Fork second child (cmd2: wc -c)
    child2 = fork();
    if (child2 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
        // Child2: Read from the pipe
        close(pipefd[1]); // Close unused write end

        // Simulate a slow reader (optional delay)
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        while (read(pipefd[0], buffer, sizeof(buffer)) > 0) {
       sleep(1); // Simulate a slow reader
}


        close(pipefd[0]);             // Close read end after duplication
        execvp(cmd2, argv2);          // Execute cmd2 (wc -c)
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    assert(child2 > 0); // Ensure the second child was created successfully

    // Parent process
    close(pipefd[0]); // Close unused read end
    close(pipefd[1]); // Close unused write end
    waitpid(child1, NULL, 0); // Wait for first child (echo) to finish
    waitpid(child2, NULL, 0); // Wait for second child (wc -c) to finish
}

int main() {
    // Commands for the pipeline
    char *cmd1 = "echo";
    char *argv1[] = {"echo", "foo", NULL};

    char *cmd2 = "wc";
    char *argv2[] = {"wc", "-c", NULL};

    // Run the blocking pipeline
    blocking_pipeline(cmd1, argv1, cmd2, argv2);

    return 0;
}                  
