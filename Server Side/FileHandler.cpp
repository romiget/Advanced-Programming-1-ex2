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
        throw runtime_error("mila");
    }
    vector<Flower> flowers;
    string line;
    while (getline(fs, line)) {
        flowers.push_back(FileHandler::createFlower(line));
    }
    fs.close();
    return flowers;
}

Flower FileHandler::createFlower(const string &line) {
    vector<string> flower = splitLine(line, ',');
    vector<double> flowerData;
    for (int i = 0; i < flower.size() - 1; i++) {
        flowerData.push_back(stod(flower[i]));
    }
    return Flower(flower[4], flowerData[0], flowerData[1], flowerData[2], flowerData[3]);
}

void FileHandler::fileReader(const vector<Flower>& flowers, fstream& fs, int k) {
    fstream euclid;
    fstream manhattan;
    fstream chebyshev;
    euclid.open("euclidean_output.csv", ios::out);
    manhattan.open("manhattan_output.csv", ios::out);
    chebyshev.open("chebyshev_output.csv", ios::out);
    string line;
    while(getline(fs, line)) {
        vector<string> flowerString = FileHandler::splitLine(line, ',');
        vector<double> flowerData;
        for (auto & i : flowerString) {
            flowerData.push_back(stod(i));
        }
        Flower measured = Flower("", flowerData[0], flowerData[1], flowerData[2], flowerData[3]);
        EuclideanMetric euclideanMetric;
        vector<Measurable> euclideanKnn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
                euclideanMetric, measured, k);
        measured.setType(FileHandler::knnCheck(euclideanKnn));
        euclid << measured.getType() << endl;
        ChebyshevMetric chebyshevMetric;
        vector<Measurable> chebyshevKnn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
                chebyshevMetric, measured, k);
        measured.setType(FileHandler::knnCheck(chebyshevKnn));
        chebyshev << measured.getType() << endl;
        ManhattanMetric manhattanMetric;
        vector<Measurable> manhattanKnn = MeasurableList::KNN((vector<struct Measurable> &) flowers,
                manhattanMetric, measured, k);
        measured.setType(FileHandler::knnCheck(manhattanKnn));
        manhattan << measured.getType() << endl;
    }
    euclid.close();
    manhattan.close();
    chebyshev.close();
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