//
// Created by ido on 7/22/22.
//

// Chebyshev metric returns the largest difference between two corresponding attributes.

#ifndef ADVANCED_PROGRAMMING_1_CHEBYSHEVMETRIC_H
#define ADVANCED_PROGRAMMING_1_CHEBYSHEVMETRIC_H

#include <list>
#include "Metric.h"

using namespace std;

class ChebyshevMetric : public Metric {
public:
    double metric(vector<double> l1, vector<double> l2) const;
};

#endif //ADVANCED_PROGRAMMING_1_CHEBYSHEVMETRIC_H
