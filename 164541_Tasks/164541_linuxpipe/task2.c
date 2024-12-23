#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

void foreground_pipeline(const char *cmd1, char *const argv1[], const char *cmd2, char *const argv2[]) {
    int pipefd[2], status;

    // [A] Set up the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork first child (cmd1)
    pid_t child1 = fork();
    if (child1 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        // [B] Child1: Redirect stdout to pipe write end
        dup2(pipefd[1], STDOUT_FILENO); // stdout -> pipe write end
        close(pipefd[0]);              // Close unused read end
        close(pipefd[1]);              // Close pipe write end after duplication
        execvp(cmd1, argv1);           // Execute cmd1
        perror("execvp failed");       // If execvp fails
        exit(EXIT_FAILURE);
    }
    assert(child1 > 0);

    // Fork second child (cmd2)
    pid_t child2 = fork();
    if (child2 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
        // [D] Child2: Redirect stdin to pipe read end
        dup2(pipefd[0], STDIN_FILENO); // stdin -> pipe read end
        close(pipefd[1]);             // Close unused write end
        close(pipefd[0]);             // Close pipe read end after duplication
        execvp(cmd2, argv2);          // Execute cmd2
        perror("execvp failed");      // If execvp fails
        exit(EXIT_FAILURE);
    }
    assert(child2 > 0);

    // [C] Parent cleans up the pipe
    close(pipefd[0]); // Close unused read end
    close(pipefd[1]); // Close unused write end

    // [E] Parent waits for both children
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
}

int main() {
    // Example: ls | wc -l
    char *cmd1 = "ls";
    char *argv1[] = {"ls", NULL};

    char *cmd2 = "wc";
    char *argv2[] = {"wc", "-l", NULL};

    foreground_pipeline(cmd1, argv1, cmd2, argv2);

    return 0;
}

