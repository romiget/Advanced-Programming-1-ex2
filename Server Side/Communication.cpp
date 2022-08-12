//
// Created by romrom4444 on 8/9/22.
//

#include "Communication.h"
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

void Communication::init() {

    sock = socket(AF_INET, SOCK_STREAM, 0);
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
}

void Communication::waitForConnection() {
    if (listen(sock, 5) < 0) {
        perror("couldn't listen to socket");
    }

    unsigned int addr_len = sizeof(client_sin);
    client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("couldn't accept client");
    }
}

string Communication::getLine(const string& sourceFile) {
    char buffer[256];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        disconnect();
    }
    else if (read_bytes < 0) {
        throw exception();
    }
    else {
        sendLine(buffer, sourceFile);
    }
}

void Communication::sendLine(char* message, const string& sourceFile) {
    Flower interpreted = FileHandler::createFlowerFromUnclassified(message);
    char* classification;
    fstream stream = fstream(sourceFile);
    EuclideanMetric eum = EuclideanMetric();
    Flower unclassified = FileHandler::createFlowerFromUnclassified(message);
    FileHandler::classify(FileHandler::createFlowerFromUnclassified(message),
                          FileHandler::getFlowers(sourceFile),stream, 9, eum);
    classification = &(unclassified.getType().front());
    int data_len = strlen(classification);
    int sent_bytes = send(client_sock, classification, data_len, 0);
    if (sent_bytes < 0) {
        throw exception();
    }
}

void Communication::disconnect() {
    close(sock);
}