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

/**
 * This function sends a message to the server using socket.
 * @param sock is the socket.
 * @param message is the message.
 */
void Communication::sendData(int sock, char* message) {
    int data_len = strlen(message);
    int sent_bytes = send(sock, message, data_len, 0);

    if (sent_bytes < 0)
        perror("can't send message to the server!");
}

/**
 * This function receives a message from the server using socket and writes it to a file.
 * @param sock is the socket.
 * @param writeFile is the file.
 */
void Communication::recvData(int sock, const string writeFile) {
    fstream ostream;
    ostream.open(writeFile, ios::app);
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
