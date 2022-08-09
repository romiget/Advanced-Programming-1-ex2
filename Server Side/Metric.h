//
// Created by ido on 7/22/22.
//

// This class is the generalized metric function. Its child classes are different defined metrics as tasked.

#ifndef ADVANCED_PROGRAMMING_1_METRIC_H
#define ADVANCED_PROGRAMMING_1_METRIC_H

#include <list>
#include <vector>

using namespace std;

class Metric {
public:
    virtual double metric(vector<double> l1, vector<double> l2) const;
};

#endif //ADVANCED_PROGRAMMING_1_METRIC_H
