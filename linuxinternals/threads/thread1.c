#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


static void * threadfunc(void *arg)
{
	char *str =(char *) arg
int count =0;

		//printf ("therad func :arguments passed to thread are : %s,pid=(%d)"\n,s,getpid() );
//	(void)sleep(15);


	printf("\n threadfunc :started now\n");
	for (count =0;count<MAX;count ++);
//	pthread_exit(0);

sleep(5);
 printf("\n threadfunc :exiting now\n");
 if(count<500){
	 return(void *)"count <500>
}


int main (int argc, char *argv[])
{
	pthread_t t1_id;
	void *res;
	int s;
	s = pthread_create(&t1,NULL,threadfunc,"hello world");
	if (s!=0)
		perror("thread create error");
//	printf ("main thread :message")


 s = pthread_join(t1_id,,&res);
	if (s!=0)
                perror("thread join error");
	 printf ("main thread :thread returned%s\n,(char *)"res);


}
