#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
 
static int glob = 0;
static int mtx;
static void *threadFunc1(void *arg)
{
        int loop = 10;
        int loc, j,ret;
	printf("\n threadfunc1 executed first\n");
	ret=pthread_mutex_lock(&mtx);
	if(ret !=0)
		printf("pthread_mutex_lock");

        for (j = 0; j < loop; j++) {
                loc = glob;
                loc++;
                glob = loc;
        }
        ret=NULL;

}
 
static void *threadFunc2(void *arg)
{
        int loop = 10;
        int loc, j,ret;
 printf("\n threadfunc1 executed second\n");

 //       ret=pthread_mutex_lock(&mtx);
        if(ret !=0)
                printf("pthread_mutex_lock");
        for (j = 0; j < loop; j++) {
                loc = glob;
                loc++;
                glob = loc;
        }
        return NULL;
}
 
int main(int argc, char *argv[])
{
        pthread_t t1, t2;
        int loops, s;
        s = pthread_create(&t1, NULL, threadFunc1, NULL);
        if (s != 0)
                perror("pthread_create");
        s = pthread_create(&t2, NULL, threadFunc2, NULL);
        if (s != 0)
                perror("pthread_create");
        s = pthread_join(t1, NULL);
        if (s != 0)
                perror("pthread_join");
        s = pthread_join(t2, NULL);
        if (s != 0)
                perror("pthread_join");
        printf("glob = %d\n", glob);
        exit(0);
}

