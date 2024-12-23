#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_cmdline(pid_t pid) {
    char path[256];
    sprintf(path, "/proc/%d/cmdline", pid);

    FILE *f = fopen(path, "r");
    if (!f) {
        perror("Error opening cmdline");
        return;
    }

    char buffer[4096];
    fread(buffer, 1, sizeof(buffer), f);
    fclose(f);

    printf("Command line: %s\n", buffer);
}

void print_times(pid_t pid) {
    char path[256];
    sprintf(path, "/proc/%d/stat", pid);

    FILE *f = fopen(path, "r");
    if (!f) {
        perror("Error opening stat");
        return;
    }

    unsigned long utime, stime;
    fscanf(f, "%*d %*s %*c %*d %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %lu %lu", &utime, &stime);
    fclose(f);

    long ticks = sysconf(_SC_CLK_TCK);
    printf("User time: %lu seconds\n", utime / ticks);
    printf("Kernel time: %lu seconds\n", stime / ticks);
}
/*
void print_environment(pid_t pid) {
    char path[256];
    sprintf(path, "/proc/%d/environ", pid);

    FILE *f = fopen(path, "r");
    if (!f) {
        perror("Error opening environ");
        return;
    }

    char buffer[4096];
    fread(buffer, 1, sizeof(buffer), f);
    fclose(f);

    char *env = buffer;
    while (*env) {
        printf("%s\n", env);
        env += strlen(env) + 1;
    }
}

void print_memory_map(pid_t pid) {
    char path[256];
    sprintf(path, "/proc/%d/maps", pid);

    FILE *f = fopen(path, "r");
    if (!f) {
        perror("Error opening maps");
        return;
    }

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), f)) {
        printf("%s", buffer);
    }

    fclose(f);
}
*/
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    printf("Process information for PID %d\n", pid);

    print_cmdline(pid);
    print_times(pid);
  //  print_environment(pid);
   // print_memory_map(pid);

    return 0;
}

