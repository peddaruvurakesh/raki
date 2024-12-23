#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	pid_t id;
	printF("parent : executed by parent before fork() - PID =(%d)\n",getpid());
	id fork();
	if (id>0){
		sleep(10);
		printf("\n run ps aux | grep Z\n");
		waitpid(id,NULL,0);
		printf("\n parent process : i have \n");
