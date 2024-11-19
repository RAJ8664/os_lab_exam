#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MESSAGE_LENGTH 1024

int main() {
    int sock = 0;
    struct sockaddr_in server_address;
    char buffer[MAX_MESSAGE_LENGTH] = {0};
    char message[MAX_MESSAGE_LENGTH];

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Send the message to the server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // Read the reversed message from the server
    read(sock, buffer, MAX_MESSAGE_LENGTH);
    printf("Reversed message received: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}
