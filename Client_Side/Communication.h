//
// Created by ido on 8/12/22.
//

#ifndef SERVER_SIDE_COMMUNICATION_H
#define SERVER_SIDE_COMMUNICATION_H
class Communication {
    static const char* ip_address;
    static const int port_no = 5555;
    static int sock;
    static struct sockaddr_in sin;
public:
    static void init();
    static void connectToServer();
    static void sendData(char* message);
    static void recvData(const std::string writeFile);
};
#endif //SERVER_SIDE_COMMUNICATION_H
