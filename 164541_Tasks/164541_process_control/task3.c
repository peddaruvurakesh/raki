#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 1024
#define MAXARGS 100

void execute_pipe(char *cmd1, char *cmd2);
void execute_command(char *cmd);

int main() {
    char input[MAXLINE];
    char *command1, *command2;
    char *separator = "||";

    while (1) {
        // Print prompt
        printf("EIC> ");
        fflush(stdout);

        // Read input
        if (fgets(input, MAXLINE, stdin) == NULL) {
            break;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        // Check for exit commands
        if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) {
            break;
        }

        // Check for pipe symbol (||)
        command1 = strtok(input, separator);
        command2 = strtok(NULL, separator);

        if (command2 != NULL) {
            // Execute piped commands
            execute_pipe(command1, command2);
        } else {
            // Execute single command
            execute_command(command1);
        }
    }

    return 0;
}

void execute_pipe(char *cmd1, char *cmd2) {
    int pipefd[2];
    pid_t pid1, pid2;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child for cmd1
    if ((pid1 = fork()) == 0) {
        // Redirect stdout to pipe write end
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute first command
        execute_command(cmd1);
        exit(EXIT_FAILURE);
    }

    // Fork the second child for cmd2
    if ((pid2 = fork()) == 0) {
        // Redirect stdin to pipe read end
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Execute second command
        execute_command(cmd2);
        exit(EXIT_FAILURE);
    }

    // Close pipe in parent process
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both children to complete
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void execute_command(char *cmd) {
    char *args[MAXARGS];
    int i = 0;

    // Tokenize the command into arguments
    args[i] = strtok(cmd, " ");
    while (args[i] != NULL && i < MAXARGS - 1) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Execute the command
    if (execvp(args[0], args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

