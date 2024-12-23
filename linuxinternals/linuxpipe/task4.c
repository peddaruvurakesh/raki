#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

void misconfigured_pipeline(const char *cmd1, char *const argv1[], const char *cmd2, char *const argv2[]) {
    int pipefd[2];
    pid_t child1, child2;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork first child (cmd1: echo foo)
    child1 = fork();
    if (child1 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        // Child1: Write directly to the shell's stdout
        close(pipefd[0]); // Close unused read end of the pipe
        close(pipefd[1]); // Close unused write end of the pipe
        execvp(cmd1, argv1); // Execute cmd1 (echo foo)
        perror("execvp failed"); // If execvp fails
        exit(EXIT_FAILURE);
    }
    assert(child1 > 0); // Ensure the first child was created successfully

    // Fork second child (cmd2: wc -c)
    child2 = fork();
    if (child2 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
        // Child2: Read from the pipe (which is empty)
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(pipefd[1]);             // Close unused write end
        close(pipefd[0]);             // Close the read end after duplication
       execvp(cmd2, argv2);          // Execute cmd2 (wc -c)
        perror("execvp failed");      // If execvp fails
        exit(EXIT_FAILURE);
    }
    assert(child2 > 0); // Ensure the second child was created successfully

    // Parent process
    close(pipefd[0]); // Close unused read end
    close(pipefd[1]); // Close unused write end
    waitpid(child1, NULL, 0); // Wait for first child (echo foo) to finish
    waitpid(child2, NULL, 0); // Wait for second child (wc -c) to finish
}

int main() {
    // Commands for the pipeline
    char *cmd1 = "echo";
    char *argv1[] = {"echo", "foo", NULL};

    char *cmd2 = "wc";
    char *argv2[] = {"wc", "-c", NULL};

    // Run the misconfigured pipeline
    misconfigured_pipeline(cmd1, argv1, cmd2, argv2);

    return 0;
}

