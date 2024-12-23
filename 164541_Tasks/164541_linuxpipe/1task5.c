#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

#define LARGE_OUTPUT_SIZE 70000 // Amount of data to write (greater than typical pipe buffer size)

void create_blocking_pipeline() {
    int pipefd[2];
    pid_t child1, child2;

    // [A] Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork the first child (child1: writes to the pipe)
    child1 = fork();
    if (child1 == 0) {
        // [B] Child1: Write a large amount of data into the pipe
        close(pipefd[0]); // Close the read end

        char buffer[] = "x"; // Data to write
        for (int i = 0; i < LARGE_OUTPUT_SIZE; i++) {
            if (write(pipefd[1], buffer, 1) == -1) {
                perror("write failed");
                break; // Stop if the pipe is full
            }
        }
        pause(); // Prevent child1 from exiting to simulate a hanging writer
        exit(EXIT_SUCCESS);
    }
    assert(child1 > 0);

    // Fork the second child (child2: reads from the pipe)
    child2 = fork();
    if (child2 == 0) {
        // [D] Child2: Simulate slow reading
        close(pipefd[1]); // Close the write end

        char buffer[70000];
        while (read(pipefd[0], buffer, sizeof(buffer)) > 0) {
            sleep(1); // Artificial delay to make the pipe fill up
        }

        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    assert(child2 > 0);

    // [E] Parent process: Close both ends and wait for children
    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(child1, NULL, 0); // Wait for child1
    waitpid(child2, NULL, 0); // Wait for child2
}

int main() {
    create_blocking_pipeline();
    printf("Pipeline has completed.\n");
    return 0;
}

