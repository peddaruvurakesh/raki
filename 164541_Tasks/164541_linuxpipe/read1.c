#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>   // For O_CREAT, O_RDONLY
#include <sys/stat.h> // For mode constants

int main(int argc, char **argv) {
    mqd_t queue;                // Message queue descriptor
    struct mq_attr attrs;       // Attributes of the message queue
    void *msg_ptr;              // Pointer to store the message
    ssize_t recvd;              // Variable to store the received message size

    // Check for correct number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <queuename>\n", argv[0]);
        return 1;
    }

    // Open or create the message queue
    queue = mq_open(argv[1], O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, NULL);
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

    // Allocate memory to receive the message
    msg_ptr = calloc(1, attrs.mq_msgsize);
    if (msg_ptr == NULL) {
        perror("calloc");
        mq_close(queue);
        return 1;
    }

    // Receive the message from the queue
    recvd = mq_receive(queue, msg_ptr, attrs.mq_msgsize, NULL);
    if (recvd == -1) {
        perror("mq_receive");
        free(msg_ptr);
        mq_close(queue);
        return 1;
    }

    // Print the received message
    printf("\nReceived message in message queue: %s\n", (char *)msg_ptr);

    // Free resources and close the message queue
    free(msg_ptr);
    mq_close(queue);

    return 0;
}

