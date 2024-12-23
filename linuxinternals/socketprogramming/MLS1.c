#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFFER_SIZE 1024

// Function to handle the arithmetic expression
int evaluate_expression(char *expr) {
    int operand1, operand2, result;
    char operator;

    // Parsing the arithmetic expression
    sscanf(expr, "%d %c %d", &operand1, &operator, &operand2);

    // Perform the appropriate arithmetic operation
    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                result = -1; // Error: Division by zero
            }
            break;
        default:
            result = -1; // Error: Invalid operator
            break;
    }

    return result;
}

int main(int argc, char *argv[]) {
    int sockfd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 1) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Waiting for connections...\n");

    while (1) {
        // Accept a client connection
        new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (new_sock < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected\n");

        // Handle client communication
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int n = recv(new_sock, buffer, BUFFER_SIZE, 0);
            if (n <= 0) {
                if (n == 0) {
                    printf("Client disconnected\n");
                } else {
                    perror("Receive failed");
                }
                break;
            }

            printf("Client: %s\n", buffer);

            // Evaluate the arithmetic expression
            int result = evaluate_expression(buffer);
            if (result == -1) {
                strcpy(buffer, "Error: Invalid expression or division by zero");
            } else {
                sprintf(buffer, "%d", result);
            }

            // Send the result back to the client
            send(new_sock, buffer, strlen(buffer), 0);
        }

        // Close the connection with the current client
        close(new_sock);
    }

    // Close the listening socket
    close(sockfd);
    return 0;
}

