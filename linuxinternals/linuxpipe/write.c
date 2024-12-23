#include<stdio.h>
#include<stdio.h>
#include<mqueue.h>
#include <string.h>
int main(int argc, char **argv){

mqd_t queue;
struct mq_attr attrs;
size_t msg_len;

queue = mq_open(argv[1], O_WRONLY | O_CREAT, 0660, NULL);

printf("\n messgae queue mq_maxmsg = (%d), mq_msgsize is (%d)\n", (int)attrs.mq_maxmsg, (int)attrs.mq_msgsize);

msg_len = strlen(argv[2]);

return 0;
}
