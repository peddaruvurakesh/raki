
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("the process pid =(%d)\n",getpid());


    
    execl("./p2","arg1","arg2","arg3", NULL);
printf("this line will not be printed...");

 
    
    return 0;
}

