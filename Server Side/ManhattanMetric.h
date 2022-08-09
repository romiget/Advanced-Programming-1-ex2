//
// Created by ido on 7/22/22.
//

// The manhattan metric, also called the sum metric, returns the sum of the differences of the attributes.

#ifndef ADVANCED_PROGRAMMING_1_MANHATTANMETRIC_H
#define ADVANCED_PROGRAMMING_1_MANHATTANMETRIC_H

#include <list>
#include "Metric.h"

using namespace std;

class ManhattanMetric : public Metric {
public:
    double metric(vector<double> l1, vector<double> l2) const;
};

#endif //ADVANCED_PROGRAMMING_1_MANHATTANMETRIC_H
