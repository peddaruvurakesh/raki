#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
int main()
{
	printf("process PID=%d  parent process PID=%d\n",getpid(),getppid());
	printf("Your are about o do\n");
	int child=fork();
	if(child==-1)
	{
		printf("the first fork failed.");
		exit(-1);
	}
	if(child==0)
	{
		printf("I am in child process, child pid=%d and its parent pid=%d\n",getpid(),getppid());
		int grand_child=fork();
		if(grand_child==-1)
		{
			printf("the second fork failed.");
			exit(-1);
		}
		if(grand_child==0)
		{
			printf("I am in grand child process, grand child pid=%d and its parent pid=%d\n",getpid(),getppid());

			sleep(3);
			printf("grand child should now be an orphan and providing its pid=%d and its parent ppid=%d\n",getpid(),getppid());
			printf("it is about to do something\n");
			system("ps");
			printf("grand child is about to exit\n");
			exit(0);
		}
		else
		{
			printf("I am in child process, child pid=%d and its parent pid=%d\n",getpid(),getppid());
			sleep(2);
			printf("child is about to exit\n");
			exit(0);
		}
	}
	else
	{
		printf("I am in parent process, parent pid=%d and its parent pid=%d\n",getpid(),getppid());
		sleep(2);
		printf("parent is about to call ps and that the child shild appear as a zombie\n");
		system("ps");
		sleep(3);
		wait(0);
		printf("parent is having waited on child ,it is to call ps as again\n");
		system("ps");
		printf("parent is ready to terminate\n");
		exit(0);
	}
}




