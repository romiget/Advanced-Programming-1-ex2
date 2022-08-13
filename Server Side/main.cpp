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
    const int server_port = 1234;
    struct sockaddr_in sin;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("couldn't create socket for server");
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("couldn't bind server socket");
    }

    if (listen(sock, 5) < 0) {
        perror("couldn't listen to socket");
    }

    static struct sockaddr_in client_sin;

    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("couldn't accept connection");
    }

    while (true) {
        try {
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
                char* classification;
                EuclideanMetric eum = EuclideanMetric();
                Flower unclassified = FileHandler::createFlowerFromUnclassified(buffer);
                vector<Flower> flowers = FileHandler::getFlowers(argv[1]); // segmentation fault happens here
                fstream stream = fstream(argv[1]);
                FileHandler::classify(unclassified, flowers,stream, 9, eum);
                classification = &(unclassified.getType().front());
                size_t data_len = strlen(classification);
                ssize_t sent_bytes = send(client_sock, classification, data_len, 0);
                if (sent_bytes < 0) {
                    throw exception();
                }
            }
        }
        catch (exception&) {
            close(sock);
            return 0;
        }
    }
}