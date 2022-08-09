//
// Created by romig on 22/07/2022.
//

#include "MeasurableList.h"
#include <algorithm>

using namespace std;

vector<pair<double, Measurable>> MeasurableList::kSmallestValues(vector<pair<double, Measurable>> l, int k) {
    std::sort(l.begin(), l.end(), [](pair<double, Measurable>& left, pair<double, Measurable>& right) {
        return left.first <= right.first;
    });
    vector<pair<double, Measurable>> res;
    for (int i = 0; i < k; i++) {
        res.push_back(l[i]);
    }
    return res;
}

vector<Measurable> MeasurableList::KNN(vector<Measurable>& measurables, Metric& metric, Measurable m, int k) {
    if (k >= measurables.size())
        return measurables;
    vector<pair<double, Measurable>> l = MeasurableList::createDistanceList(measurables, metric, m);
    l = MeasurableList::kSmallestValues(l, k);
    vector<Measurable> knn;
    for (int i = 0; i < k; i++) {
        knn.push_back(l[i].second);
    }
    return knn;
}

vector<pair<double, Measurable>> MeasurableList::createDistanceList(vector<Measurable> &l, Metric& func, Measurable &m){
    vector<pair<double, Measurable>> distances;
    for (auto & i : l) {
        distances.emplace_back(i.distance(m, func), i);
    }
    return distances;
}
