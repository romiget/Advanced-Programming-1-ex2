//
// Created by romig on 22/07/2022.
//

// This class is a general class for objects we want to compare to other objects of similar type.
// It is to be inherited from.
// This class has a vector of attributes, represented by decimal values, and a type. The type will
// correspond to whatever your measurable object is.
// This class can be initialized with no values, two strings depicting its attributes and type,
// and with another object.
// This class can convert itself into a string and a string into itself,
// it allows adding an attribute to it, it can measure its distance (its difference) from another measurable,
// and it allows to show its attributes, and access to change and see its type.

#ifndef ADVANCED_PROGRAMMING_1_MEASURABLE_H
#define ADVANCED_PROGRAMMING_1_MEASURABLE_H

#include <string>
#include <list>
#include <vector>
#include "Metric.h"

using namespace std;
class Measurable {
private:
    string type;
    vector<double> attributes;
public:
    Measurable();
    explicit Measurable(const string& s, string type);
    Measurable(const Measurable& measurable);
    string toString();
    void addAttribute(double att);
    double distance(Measurable& other, Metric& func) const;
    vector<double> getAttributes() const;
    string getType() const;
    void setType(basic_string<char> s);
};

#endif //ADVANCED_PROGRAMMING_1_MEASURABLE_H
