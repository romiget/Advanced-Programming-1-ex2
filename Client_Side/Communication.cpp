//
// Created by ido on 8/12/22.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "Communication.h"

using namespace std;

void Communication::init() {
    ip_address = "127.0.0.1";
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
}

void Communication::connectToServer() {
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

void Communication::sendData(char* message) {
    int data_len = strlen(message);
    int sent_bytes = send(sock, message, data_len, 0);

    if (sent_bytes < 0) {
        perror("can't send message to the server!");
    }
}

void Communication::recvData(const string writeFile) {
    fstream ostream;
    ostream.open(writeFile, ios::out);
    char buffer[256];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        close(sock);
    }
    else if (read_bytes < 0) {
        perror("error reading result from the server.");
    }
    else {
        ostream << buffer << endl;
    }
}
