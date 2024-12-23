#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototype for simple_pipe
void simple_pipe(const char *cmd1, char *const *argv1, const char *cmd2, char *const *argv2);

int main() {
    char *cmd1 = "ls";
    char *argv1[] = {"ls", NULL};

    char *cmd2 = "wc";
    char *argv2[] = {"wc", "-l", NULL};

    simple_pipe(cmd1, argv1, cmd2, argv2); // Equivalent to "ls | wc -l"

    return 0;
}

