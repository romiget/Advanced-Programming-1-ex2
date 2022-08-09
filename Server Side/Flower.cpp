//
// Created by romig on 22/07/2022.
//

#include "Flower.h"
#include <string>
#include <list>

#include "Measurable.h"
#include "Metric.h"

using namespace std;

Flower::Flower(string type, double cwidth, double clength, double pwidth, double plength) {
    this->setType(type);
    this->addAttribute(cwidth);
    this->addAttribute(clength);
    this->addAttribute(pwidth);
    this->addAttribute(plength);
}
