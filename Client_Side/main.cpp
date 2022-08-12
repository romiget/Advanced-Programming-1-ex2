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
int main(int argc, char* argv[]) {
    const char* ip_address = "127.0.0.1";
    static const int port_no = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    fstream fs;
    fs.open(argv[1]);
    string line;
    while (getline(fs, line)) {
        Communication::sendData(sock, &line.front());
        Communication::recvData(sock, argv[2]);
    }
}