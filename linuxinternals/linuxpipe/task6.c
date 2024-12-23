#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the command structure
struct command {
    struct command *next; // Pointer to the next command
    int argc;             // Number of arguments
    int ispipe;           // Indicates if a pipe follows this command
    char **argv;          // Command arguments
    pid_t pid;            // PID of the process running this command
};

// Function to execute the pipeline
void do_pipes(struct command *c) {
    pid_t newpid;
    int havepipe = 0;      // Indicates if there was a pipe on the previous command
    int lastpipe[2] = {-1, -1}; // File descriptors for the last pipe
    int curpipe[2];        // File descriptors for the current pipe

    do {
        // Create a new pipe if this command is followed by a pipe
        if (c->ispipe) {
            int r = pipe(curpipe);
            assert(r == 0); // Ensure pipe creation is successful
        }

        // Fork a new process for the current command
        newpid = fork();
        assert(newpid >= 0); // Ensure fork was successful
        if (newpid == 0) { // Child process
            if (havepipe) {
                // Part A: Redirect stdin to the last pipe's read end
                dup2(lastpipe[0], STDIN_FILENO);
                close(lastpipe[0]); // Close the read end after redirection
                close(lastpipe[1]); // Close the write end of the last pipe
            }
            if (c->ispipe) {
                // Part B: Redirect stdout to the current pipe's write end
                dup2(curpipe[1], STDOUT_FILENO);
                close(curpipe[0]); // Close the read end of the current pipe
                close(curpipe[1]); // Close the write end after redirection
            }

            execvp(c->argv[0], c->argv); // Execute the command
            fprintf(stderr, "Exec failed\n");
            _exit(1); // Exit if exec fails
        }

        // Part C: Cleanup in the parent process
        if (havepipe) {
            close(lastpipe[0]); // Close the read end of the last pipe
            close(lastpipe[1]); // Close the write end of the last pipe
        }

        // Prepare for the next command
        havepipe = c->ispipe;
        if (c->ispipe) {
            lastpipe[0] = curpipe[0];
            lastpipe[1] = curpipe[1];
        }
        c->pid = newpid;
        c = c->next;
    } while (newpid != -1 && havepipe);
}


int main() {
    // Example commands: "echo foo | wc -c"
    char *argv1[] = {"echo", "foo", NULL};
    char *argv2[] = {"wc", "-c", NULL};

    struct command cmd1 = {NULL, 2, 1, argv1, 0};
    struct command cmd2 = {NULL, 2, 0, argv2, 0};
    cmd1.next = &cmd2;

    do_pipes(&cmd1);
sleep (20);
    // Wait for child processes to finish
    wait(NULL);

    wait(NULL);

    return 0;
}

