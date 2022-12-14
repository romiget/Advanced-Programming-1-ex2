//
// Created by ido on 7/29/22.
//

// This class is a static class responsible for (as is suggested) file handling.
// It can split a string according to a given delimiter value, collect flower objects
// from a csv file, convert a string into a flower object, write flower objects to a csv file,
// and decide a type of flower according to the result of the k nearest neighbors.

#ifndef ADVANCED_PROGRAMMING_1_FILEHANDLER_H
#define ADVANCED_PROGRAMMING_1_FILEHANDLER_H
#include "Flower.h"
class FileHandler {
public:
    static std::vector<std::string> splitLine(const std::string& line, char delimiter);
    static std::vector<Flower> getFlowers(const string& fileName);
    static Flower createFlowerFromClassified(const string& line);
    static Flower createFlowerFromUnclassified(const string& line);
    static void scan(const vector<Flower>& flowers, fstream& fs, int k, Metric& func);
    static void classify(Flower& measured, const vector<Flower>& flowers, fstream& euclid, int k, Metric& func);
    static string knnCheck(const vector<Measurable>& flowers);
};
#endif //ADVANCED_PROGRAMMING_1_FILEHANDLER_H
