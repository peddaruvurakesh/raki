#include<stdio.h>


void *threadA(void *p){
	printf("\n threadA scheduled first\n");
	sleep(1);
	pthread_mutex_lock(&my_mutex);
	printf("\n threadA: critical section executes always first\n");
	sprintf(buf,"this is data buffer");
	doneflag =1;
	pthread_cond_signal(&convar);
	pthread_mutex_unlock(&my_mutex);
}


void *threadB(void *p){
	 printf("\n threadB scheduled first\n");
	 
        pthread_mutex_lock(&my_mutex);
	if (doneflag ==0)
		pthread_cond_wait(&convar,&my_mutex);

        printf("\n threadA: critical section executes always first\n");
        printf(buf,"the buffer recived ");
        
        pthread_mutex_unlock(&my_mutex);
}







int main(int argc ,char **argv[])
{
	srand(time(0));
	pthread_t pthreadA;
	pthread_create
