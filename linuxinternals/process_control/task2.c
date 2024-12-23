#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 15
#define MAX_VALUE 999999999
#define MIN_VALUE -999999999

void PWork(int pipeA[], int pipeC[]);
void CWork(int pipeB[], int pipeA[]);
void GWork(int pipeC[], int pipeB[]);

int main() {
    int pipeA[2], pipeB[2], pipeC[2];

    // Create the pipes
    if (pipe(pipeA) == -1) {
        perror("pipe #1 error");
        exit(-5);
    }
    if (pipe(pipeB) == -1) {
        perror("pipe #2 error");
        exit(-5);
    }
    if (pipe(pipeC) == -1) {
        perror("pipe #3 error");
        exit(-5);
    }

    // Fork the processes
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork #1 error");
        exit(-5);
    } else if (pid1 == 0) {
        // Child process
        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("fork #2 error");
            exit(-5);
        } else if (pid2 == 0) {
            // Grandchild process
            GWork(pipeC, pipeB);
        } else {
            // Child process
            CWork(pipeB, pipeA);
        }
    } else {
        // Parent process
        PWork(pipeA, pipeC);
        wait(NULL); // Wait for child process to finistrtol(Value, NULL, 10);sh
    }

    return 0;
}

void PWork(int pipeA[], int pipeC[]) {
    close(pipeA[0]); // Close read end of Pipe A
    close(pipeC[1]); // Close write end of Pipe C

    char Buffer[BUFFER_SIZE], Value[BUFFER_SIZE] = "1";
    long M = 1;

    printf("The parent process is ready to proceed.\n");

    // Start the ring
    write(pipeA[1], Value, strlen(Value) + 1);
    printf("Parent: Value = %s\n", Value);

    while (M > MIN_VALUE && M < MAX_VALUE) {
        // Read from Pipe C
        int i = 0;
        while (read(pipeC[0], &Value[i], 1) > 0 && Value[i] != '\0') i++;
        Value[i] = '\0';

        M = strtol(Value, NULL, 10);
        M = 200 - 3 * M;

        snprintf(Buffer, BUFFER_SIZE, "%ld", M);
        write(pipeA[1], Buffer, strlen(Buffer) + 1);

        printf("Parent: Value = %s\n", Buffer);
    }

    close(pipeA[1]);
    close(pipeC[0]);
    exit(0);
}

void CWork(int pipeB[], int pipeA[]) {
    close(pipeB[0]); // Close read end of Pipe B
    close(pipeA[1]); // Close write end of Pipe A

    char Buffer[BUFFER_SIZE], Value[BUFFER_SIZE];
    long M;
sleep(1);
    printf("The child process is ready to proceed.\n");

    while (1) {
        // Read from Pipe A
        int i = 0;
        while (read(pipeA[0], &Value[i], 1) > 0 && Value[i] != '\0') i++;
        Value[i] = '\0';

        M = strtol(Value, NULL, 10);
        if (M <= MIN_VALUE || M >= MAX_VALUE) break;

        M = 7 * M - 6;

        snprintf(Buffer, BUFFER_SIZE, "%ld", M);
        write(pipeB[1], Buffer, strlen(Buffer) + 1);

        printf("Child: Value = %s\n", Buffer);
    }

    close(pipeB[1]);
    close(pipeA[0]);
    exit(0);
}

void GWork(int pipeC[], int pipeB[]) {
    close(pipeC[0]); // Close read end of Pipe C
    close(pipeB[1]); // Close write end of Pipe B

    char Buffer[BUFFER_SIZE], Value[BUFFER_SIZE];
    long M;
sleep(2);
    printf("The grandchild process is ready to proceed.\n");

    while (1) {
        // Read from Pipe B
        int i = 0;
        while (read(pipeB[0], &Value[i], 1) > 0 && Value[i] != '\0') i++;
        Value[i] = '\0';

        M = strtol(Value, NULL, 10);
        if (M <= MIN_VALUE || M >= MAX_VALUE) break;

        M = 30 - 4 * M;

        snprintf(Buffer, BUFFER_SIZE, "%ld", M);
        write(pipeC[1], Buffer, strlen(Buffer) + 1);

        printf("Grandchild: Value = %s\n", Buffer);
    }

    close(pipeC[1]);
    close(pipeB[0]);
    exit(0);
}

