#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_INPUT_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portnum;
    socklen_t clilen;
    char buffer[MAX_INPUT_SIZE];
    struct sockaddr_in server_addr, client_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    portnum = atoi(argv[1]);

    /* Create server socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* Fill in server address structure */
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portnum);

    /* Bind the socket to the address */
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR on binding");

    /* Start listening for connections */
    listen(sockfd, 5);
    clilen = sizeof(client_addr);

    printf("Server started. Waiting for clients...\n");

    /* Accept a client connection */
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    printf("Connected with client socket number %d\n", newsockfd);

    while (1) {
        /* Clear the buffer */
        bzero(buffer, MAX_INPUT_SIZE);

        /* Read the message from the client */
        n = read(newsockfd, buffer, MAX_INPUT_SIZE - 1);
        if (n < 0)
            error("ERROR reading from socket");

        /* Log the client's message */
        printf("Client socket %d sent message: %s", newsockfd, buffer);

        /* Determine the response */
        char *response;
        if (strncmp(buffer, "Bye", 3) == 0) {
            response = "Goodbye\n";
        } else {
            response = "OK\n";
        }

        /* Send the response to the client */
        n = write(newsockfd, response, strlen(response));
        if (n < 0)
            error("ERROR writing to socket");

        printf("Replied to client %d\n", newsockfd);

        /* Exit if the client said "Bye" */
        if (strncmp(buffer, "Bye", 3) == 0) {
            printf("Client said bye; finishing\n");
            break;
        }
    }

    /* Close the sockets */
    close(newsockfd);
    close(sockfd);

    return 0;
}

