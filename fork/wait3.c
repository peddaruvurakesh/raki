#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t cpid;
    int status = 0;

    cpid = fork();
    if (cpid == -1) {
        
        exit(-1);
    }

    if (cpid == 0) {
        // Child process
        printf("\nChild executing first, its pid = %d\n", getpid());
        sleep(20);
        printf("Child pid = %d\n", getpid());
        exit(2);  
    } else {
        // Parent process
        printf("\nParent executing before wait()\n");
        cpid = wait(&status);  
        printf("wait() in parent done\nParent pid = %d\n", getpid());
        printf("\ncpid returned is (%d)\n", cpid);
        printf("\nstatus is (%d)\n", status);
    }

    return 0;
}

