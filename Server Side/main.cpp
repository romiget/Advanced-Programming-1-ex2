#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "FileHandler.h"
#include <exception>
#include "EuclideanMetric.h"

using namespace std;
int main(int argc, char* argv[]) {
    //initializing socket
    const string data = "cmake-build-debug/classified.csv";
    const int server_port = 1234;
    struct sockaddr_in sin;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("couldn't create socket for server");
    }
    //memset
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //binding
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("couldn't bind server socket");
    }
    //waiting for connection of a client
    if (listen(sock, 5) < 0) {
        perror("couldn't listen to socket");
    }
    //accepting the client
    static struct sockaddr_in client_sin;

    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("couldn't accept connection");
    }
    //entering a loop of sending and receiving messages until closing connection with the client.
    while (true) {
        try {
            //trying to receive the data from the client
            char buffer[256];
            int expected_data_len = sizeof(buffer);
            ssize_t read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                close(sock);
                return 0;
            }
            else if (read_bytes < 0) {
                throw exception();
            }
            else {
                //classifying
                char* classification;
                EuclideanMetric eum = EuclideanMetric();
                Flower unclassified = FileHandler::createFlowerFromUnclassified(buffer);
                vector<Flower> flowers = FileHandler::getFlowers( data); // segmentation fault happens here
                fstream stream = fstream(data);
                FileHandler::classify(unclassified, flowers,stream, 9, eum);
                classification = &(unclassified.getType().front());
                size_t data_len = strlen(classification);
                //sending data
                ssize_t sent_bytes = send(client_sock, classification, data_len, 0);
                if (sent_bytes < 0) {
                    throw exception();
                }
            }
        }
        catch (exception&) {
            //closing connection
            close(sock);
            return 0;
        }
    }
}