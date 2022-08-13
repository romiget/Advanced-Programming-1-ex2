//
// Created by ido on 8/12/22.
//
#include <string>

#ifndef SERVER_SIDE_COMMUNICATION_H
#define SERVER_SIDE_COMMUNICATION_H
class Communication {
public:
    static void sendData(int sock, char* message);
    static void recvData(int sock, const std::string writeFile);
};
#endif //SERVER_SIDE_COMMUNICATION_H
