//
// Created by ido on 7/22/22.
//

#include "ManhattanMetric.h"
#include <cmath>

double ManhattanMetric::metric(vector<double> l1, vector<double> l2) const {
    if (l1.size() != l2.size())
        throw exception();
    double distance = 0;
    for (int i = 0; i < l1.size(); i++) {
        distance += abs(l1[i] - l2[i]);
    }
    return distance;
}
