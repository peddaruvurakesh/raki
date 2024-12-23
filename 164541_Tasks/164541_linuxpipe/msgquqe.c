#include<stdio.h>
#include<mqueue.h>


int main(int argc, char **argv)
{
	mqd_t queue;
	struct mq_attr attrs;
	size_t msg_len;
	if(argc<3)


	{
	fprintf(stderr,"usage:%s <queuename><message>\n,argv");

	}
	queue =mq_open (argv[1],O_WRONLY | O_CREAT,0660,NULL);
	if(QUEUE==(mqd_t)-1)
		if(mq_getattr(queue,&attrs)==-1)
			printf("\n message queue mq_maxmsg = (%d),mq_msgsize os (%d)",(int)attrs.mq_maxmsg,(int)attrs);
	mssg_len =strlen(argv[2]);

	if ((long)msg_len
