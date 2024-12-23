#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    listen(sockfd, 5);
    printf("Waiting for incoming connections...\n");

    new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (new_sock < 0) {
        perror("Accept failed");
        exit(1);
    }

    recv(new_sock, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    close(new_sock);
    close(sockfd);
    return 0;
}

