#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>   // For O_WRONLY, O_CREAT
#include <sys/stat.h> // For mode constants

int main(int argc, char **argv) {
    mqd_t queue;             // Message queue descriptor
    struct mq_attr attrs;    // Attributes of the message queue
    size_t msg_len;          // Length of the message

    // Check for correct number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <queuename> <message>\n", argv[0]);
        return 1;
    }

    // Open or create the message queue
    queue = mq_open(argv[1], O_WRONLY | O_CREAT, 0660, NULL);
    if (queue == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    // Get attributes of the message queue
    if (mq_getattr(queue, &attrs) == -1) {
        perror("mq_getattr");
        mq_close(queue);
        return 1;
    }

    // Print message queue attributes
    printf("\nMessage queue attributes:\n");
    printf("  mq_maxmsg  = %ld\n", attrs.mq_maxmsg);
    printf("  mq_msgsize = %ld\n", attrs.mq_msgsize);

    // Calculate the length of the message
    msg_len = strlen(argv[2]);
    printf("\nLength of the provided message: %zu\n", msg_len);

    // Clean up
    mq_close(queue);

    return 0;
}

