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

vector<string> FileHandler::splitLine(string line, char delimiter) {
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

void FileHandler::euclideanScan(const vector<Flower> &flowers, fstream &fs, int k) {
    fstream euclid;
    euclid.open("euclidean_output.csv", ios::out);
    string line;
    while (getline(fs, line)) {
        Flower measured = createFlowerFromUnclassified(line);
        euclideanClassify(measured, flowers, euclid, k);
    }
    euclid.close();
}

void FileHandler::chebyshevScan(const vector<Flower> &flowers, fstream &fs, int k) {
    fstream chebyshev;
    chebyshev.open("euclidean_output.csv", ios::out);
    string line;
    while (getline(fs, line)) {
        Flower measured = createFlowerFromUnclassified(line);
        chebyshevClassify(measured, flowers, chebyshev, k);
    }
    chebyshev.close();
}

void FileHandler::manhattanScan(const vector<Flower> &flowers, fstream &fs, int k) {
    fstream manhattan;
    manhattan.open("euclidean_output.csv", ios::out);
    string line;
    while (getline(fs, line)) {
        Flower measured = createFlowerFromUnclassified(line);
        manhattanClassify(measured, flowers, manhattan, k);
    }
    manhattan.close();
}

void FileHandler::euclideanClassify(Flower measured, const vector<Flower>& flowers, fstream& euclid, int k) {
    EuclideanMetric euclideanMetric;
    vector<Measurable> euclideanKnn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
            euclideanMetric, measured, k);
    measured.setType(FileHandler::knnCheck(euclideanKnn));
    euclid << measured.getType() << endl;
}

void FileHandler::chebyshevClassify(Flower measured, const vector<Flower> &flowers, fstream &chebyshev, int k) {
    ChebyshevMetric chebyshevMetric;
    vector<Measurable> chebyshevKnn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
            chebyshevMetric, measured, k);
    measured.setType(FileHandler::knnCheck(chebyshevKnn));
    chebyshev << measured.getType() << endl;
}

void FileHandler::manhattanClassify(Flower measured, const vector<Flower> &flowers, fstream &manhattan, int k) {
    ManhattanMetric manhattanMetric;
    vector<Measurable> manhattanKnn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
            manhattanMetric, measured, k);
    measured.setType(FileHandler::knnCheck(manhattanKnn));
    manhattan << measured.getType() << endl;
}

string FileHandler::knnCheck(vector<Measurable> measurables) {
    pair<int, string> setosa = {0, "Iris-setosa"};
    pair<int, string> versicolor = {0, "Iris-versicolor"};
    pair<int, string> virginica = {0, "Iris-virginica"};
    for (int i = 0; i < measurables.size(); i++) {
        if (measurables[i].getType() == "Iris-setosa")
            setosa.first++;
        else if (measurables[i].getType() == "Iris-versicolor")
            versicolor.first++;
        else if (measurables[i].getType() == "Iris-virginica")
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
