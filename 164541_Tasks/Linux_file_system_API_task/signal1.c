#include<stdio.h>

static void signal_handler (int signo)
{
	if (signo )




int main (void)
{
	ptintf("\n process ID is (%d)\n",getpid());
	if (signal(SIGINT,SIG_DFL)==ERR){
		printf(stdr,"(cannot ignore SIGHUP!)\n");
		exit(EXIT_FAILURE);
	}
		if (signal(SIGTERM,siganl_handler)==SIG_ERR){
			 printf(stdr,"(cannot ignore SIGHUP!)\n");
			 exit(EXIT_FAILURE);
		}
