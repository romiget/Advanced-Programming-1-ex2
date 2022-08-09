//
// Created by romig on 22/07/2022.
//

#include "Measurable.h"
#include <string>
#include "Metric.h"
#include <sstream>

using namespace std;

Measurable::Measurable() {
    this->attributes = vector<double>();
    this->type = "";
}

Measurable::Measurable(const string& s, string type) {
    stringstream str(s);
    string word;
    this->attributes = vector<double>();

    while (getline(str, word, ',')) {
        try {
            this->addAttribute(stod(word));
        }
        catch (invalid_argument& e) {
            continue;
        }
    }
    this->type.assign(type);
}

string Measurable::toString() {
    string str = string();
    for (double d : this->attributes) {
        str.append(to_string(d));
        str.append(", ");
    }
    str.append(type);
    return str;
}

Measurable::Measurable(const Measurable& measurable) {
    this->type = measurable.getType();
    this->attributes = measurable.getAttributes();
}

void Measurable::addAttribute(double att) {
    this->attributes.push_back(att);
}

double Measurable::distance(Measurable& other, Metric& func) const{
    return func.metric(this->getAttributes(), other.getAttributes());
}

vector<double> Measurable::getAttributes() const {
    vector<double> l = this->attributes;
    return l;
}

string Measurable::getType() const {
    return this->type;
}

void Measurable::setType(basic_string<char> s) {
    this->type.assign(s);
}
