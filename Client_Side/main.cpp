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
    fs.open(argv[1]);
    string line;
    while (getline(fs, line)) {
        Communication::sendData(&line.front());
        Communication::recvData(argv[2]);
    }
}