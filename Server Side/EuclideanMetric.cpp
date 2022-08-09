//
// Created by ido on 7/22/22.
//

#include "EuclideanMetric.h"
#include <cmath>

using namespace std;

double EuclideanMetric::metric(vector<double> l1, vector<double> l2) const {
    if (l1.size() != l2.size())
        throw exception();
    double distance = 0;
    for (int i = 0; i < l1.size(); i++) {
        distance += pow(l1[i] - l2[i], 2);
    }
    int x = 2;
    return sqrt(distance);
}
