//
// Created by ido on 7/29/22.
//
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "FileHandler.h"
#include "EuclideanMetric.h"
#include "ChebyshevMetric.h"
#include "ManhattanMetric.h"
#include "MeasurableList.h"
#include <utility>

using namespace std;

vector<string> FileHandler::splitLine(const string& line, char delimiter) {
    vector<string> res;
    stringstream stringStream(line);
    string attribute;
    while (getline(stringStream, attribute, delimiter)) {
        res.push_back(attribute);
    }
    return res;
}

std::vector<Flower> FileHandler::getFlowers(const string& fileName) {
    fstream fs;
    fs.open(fileName);
    if (!fs) {
        throw exception();
    }
    vector<Flower> flowers;
    string line;
    while (getline(fs, line)) {
        flowers.push_back(FileHandler::createFlowerFromClassified(line));
    }
    fs.close();
    return flowers;
}

Flower FileHandler::createFlowerFromClassified(const string &line) {
    vector<string> flower = splitLine(line, ',');
    vector<double> flowerData;
    for (int i = 0; i < flower.size() - 1; i++) {
        flowerData.push_back(stod(flower[i]));
    }
    return Flower(flower[4], flowerData[0], flowerData[1], flowerData[2], flowerData[3]);
}

Flower FileHandler::createFlowerFromUnclassified(const string& line) {
    vector<string> flowerString = FileHandler::splitLine(line, ',');
    vector<double> flowerData;
    for (auto & i : flowerString) {
        flowerData.push_back(stod(i));
    }
    Flower measured = Flower("", flowerData[0], flowerData[1], flowerData[2], flowerData[3]);
    return measured;
}

void FileHandler::scan(const vector<Flower> &flowers, fstream &fs, int k, Metric& func) {
    fstream scan;
    scan.open("euclidean_output.csv", ios::out);
    string line;
    while (getline(fs, line)) {
        Flower measured = createFlowerFromUnclassified(line);
        classify(measured, flowers, scan, k, func);
    }
    scan.close();
}

void FileHandler::classify(Flower& measured, const vector<Flower>& flowers, fstream& euclid, int k, Metric& func) {
    vector<Measurable> knn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
            func, measured, k);
    measured.setType(FileHandler::knnCheck(knn));
    //euclid << measured.getType() << endl;
}

string FileHandler::knnCheck(const vector<Measurable>& flowers) {
    pair<int, string> setosa = {0, "Iris-setosa"};
    pair<int, string> versicolor = {0, "Iris-versicolor"};
    pair<int, string> virginica = {0, "Iris-virginica"};
    for (auto & flower : flowers) {
        if (flower.getType() == "Iris-setosa")
            setosa.first++;
        else if (flower.getType() == "Iris-versicolor")
            versicolor.first++;
        else if (flower.getType() == "Iris-virginica")
            virginica.first++;
    }
    pair<int, string> maximum;
    if (setosa > versicolor)
        maximum = setosa;
    else
        maximum = versicolor;
    if (virginica > maximum)
        maximum = virginica;
    return maximum.second;
}
