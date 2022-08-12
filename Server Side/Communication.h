//
// Created by romrom4444 on 8/9/22.
//

#ifndef SERVER_SIDE_COMMUNICATION_H
#define SERVER_SIDE_COMMUNICATION_H

#include <string>
#include <netinet/in.h>

using namespace std;
class Communication {
    private:
        const static int server_port = 1234;
        static int sock;
        static struct sockaddr_in sin;
        static int client_sock;
        static struct sockaddr_in client_sin;
    public:
        static void init();
        static void waitForConnection();
        static string getLine(const string& sourceFile, const string& writeFile);
        static void sendLine(char* message, const string& sourceFile, const string& writeFile);
        static void disconnect();
};

#endif //SERVER_SIDE_COMMUNICATION_H
