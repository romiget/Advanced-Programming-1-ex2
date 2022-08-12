#include "Communication.h"

using namespace std;
int main(int argc, char* argv[]) {
    Communication::init();
    Communication::waitForConnection();
    while (true) {
        try {
            Communication::getLine(argv[2], argv[1]);
        }
        catch (exception) {
            Communication::disconnect();
            return 0;
        }
    }
}