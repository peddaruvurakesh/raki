#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

void simple_pipe(const char *cmd1, char *const *argv1, const char *cmd2, char *const *argv2) {
    int pipefd[2], r, status;

    // [A] Set up the pipe
    pipe(pipefd);

    // Fork first child (cmd1)
    pid_t child1 = fork();
    if (child1 == 0) {
        // [B] Setup redirection for cmd1
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(pipefd[0]);              // Close unused read end
        close(pipefd[1]);              // Close the write end after duplication
        execvp(cmd1, argv1);           // Execute cmd1
        perror("execvp failed");       // In case execvp fails
        exit(EXIT_FAILURE);
    }
    assert(child1 > 0);

    // [C] Parent cleans up pipe write end
    close(pipefd[1]); // Close the write end of the pipe in the parent

    // Fork second child (cmd2)
    pid_t child2 = fork();
    if (child2 == 0) {
        // [D] Setup redirection for cmd2
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(pipefd[0]);             // Close the read end after duplication
        execvp(cmd2, argv2);          // Execute cmd2
        perror("execvp failed");      // In case execvp fails
        exit(EXIT_FAILURE);
    }
    assert(child2 > 0);

    // [E] Parent waits for both children to complete
    close(pipefd[0]);             // Close unused read end in parent
    waitpid(child1, &status, 0);  // Wait for first child
    waitpid(child2, &status, 0);  // Wait for second child
}

int main() {
    char *cmd1 = "ls";
    char *argv1[] = {"ls", NULL};

    char *cmd2 = "grep";
    char *argv2[] = {"grep", "main", NULL};

    simple_pipe(cmd1, argv1, cmd2, argv2); // Equivalent to "ls | wc -l"

    return 0;
}
