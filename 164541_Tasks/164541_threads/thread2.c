#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
static void *threadfun(void *arg)
{
        int i=0;
        char *str =(char*)arg;
 
        printf("thread fun started\n");
        for(i=0;i<100;i++);
        sleep(5);
        //printf("thread fun exiting now\n");
        if(i<500)
        {
                return (void*) "count<500";
        }
        else{
                return (void*) "count>500";
        }
 printf("thread fun exiting now\n");
}
int main(int argc,char*argv[])
{
        pthread_t t1_id;
        void *res;
        int s;
        s=pthread_create(&t1_id,NULL,threadfun,NULL);
        if(s!=0)
                perror("Thread create error ");
#if 1
        s=pthread_join(t1_id,&res);
        if(s!=0)
                perror("Thread join error ");
 
                printf("main thread pid %s\n",(char*)res);
#endif
 
        //sleep(5);
        printf("main thread exiting now\n");
        //exit(0);
        //pthread_exit(0);
}
