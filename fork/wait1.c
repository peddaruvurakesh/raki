#include<stdio.h>
#include<stdio.h>
#include<stdioi.h>


int main()
{
	pid_t cpid;
	int status =0;
	cpid =fork();
	if (cpid == -1)
		exit(-1);
	if (cpid == -0)
		printf("\n child executing first its pid =(%d)\n",getpid());
	sleep(20);
	printf("child pid =(%d)",getpid());
	exit(2);
}
else
{
	printf("\n parent executing before wait()\n");
cpid = wait(&status);
printf("wait() in parent done \n parent pid =%d\n",getpid());
printf("\n cpid returned is (%d)\n",cpid);
printf("\n status is (%d\n)",status)
}
