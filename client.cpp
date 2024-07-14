#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main() {
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address = {};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1234);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (sockaddr *) &server_address, sizeof(server_address));

    if(connection_status == -1) {
        perror("Errrrrrror");
    }

    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    printf("%s", server_response);

    close(network_socket);

    return 0;
}
