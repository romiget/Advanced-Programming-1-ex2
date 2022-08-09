#include <fstream>
#include "Flower.h"
#include "FileHandler.h"
#include <iostream>

using namespace std;
int main(int argc, char* argv[]) {
    std::vector<Flower> flowers = FileHandler::getFlowers("classified.csv");
    fstream fs;
    fs.open("Unclassified.csv");
    if (!fs)
        throw exception();
    FileHandler::fileReader(flowers, fs, stoi((string)argv[1]));
    fs.close();
}
