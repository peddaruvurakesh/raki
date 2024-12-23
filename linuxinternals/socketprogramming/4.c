#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server\n");

    // Continuous send and receive loop
    while (1) {
        // Send message to server
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive message from server
        memset(buffer, 0, BUFFER_SIZE);
        int recv_len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (recv_len <= 0) {
            if (recv_len == 0) {
                printf("Server disconnected\n");
            } else {
                perror("Receive failed");
            }
            break;
        }
        printf("Server: %s\n", buffer);
    }

    // Close socket
    close(sockfd);
    return 0;
}

