//
// Created by ido on 8/12/22.
//
#include <fstream>
#include "Communication.h"
using namespace std;
int main(int argc, char* argv[]) {
    Communication::init();
    Communication::connectToServer();
    fstream fs;
    string line;
    while (getline(fs, line)) {
        Communication::sendData(argv[1]);
        Communication::recvData(argv[2]);
    }
}