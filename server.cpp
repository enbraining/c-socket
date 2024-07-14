#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address = {};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1234);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);


    while(1) {
        char server_message[256] = "Hello World!";
        cin >> server_message;

        int client_socket = accept(server_socket, NULL, NULL);
        send(client_socket, server_message, sizeof(server_message), 0);
    }

    close(server_socket);

    return 0;
}
