#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection
    new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (new_sock < 0) {
        perror("Accept failed");
        exit(1);
    }

    printf("Client connected\n");

    // Continuous send and receive loop
    while (1) {
        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        int recv_len = recv(new_sock, buffer, BUFFER_SIZE, 0);
        if (recv_len <= 0) {
            if (recv_len == 0) {
                printf("Client disconnected\n");
            } else {
                perror("Receive failed");
            }
            break;
        }
        printf("Client: %s\n", buffer);

        // Send message to client
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
        send(new_sock, buffer, strlen(buffer), 0);
    }

    // Close sockets
    close(new_sock);
    close(sockfd);
    return 0;
}

