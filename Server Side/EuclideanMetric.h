//
// Created by ido on 7/22/22.
//

// The euclidean metric, also called the standard metric, returns the square root of the sum of
// squared differences of the attributes.

#ifndef ADVANCED_PROGRAMMING_1_EUCLIDEANMETRIC_H
#define ADVANCED_PROGRAMMING_1_EUCLIDEANMETRIC_H

#include <list>
#include "Metric.h"

using namespace std;

class EuclideanMetric : public Metric {
public:
    double metric(vector<double> l1, vector<double> l2) const;
};

#endif //ADVANCED_PROGRAMMING_1_EUCLIDEANMETRIC_H
