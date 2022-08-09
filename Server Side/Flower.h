//
// Created by romig on 22/07/2022.
//

// This class is a child of the Measurable class. It can be initialized with 4 properties:
// cup leaves width and length, and petal width and length.

#pragma once

#ifndef ADVANCED_PROGRAMMING_1_FLOWER_H
#define ADVANCED_PROGRAMMING_1_FLOWER_H

#include "Measurable.h"
#include "Metric.h"
#include <string>

using namespace std;

class Flower : public Measurable {
public:
    Flower(string type, double cwidth, double clength, double pwidth, double plength);
};

#endif //ADVANCED_PROGRAMMING_1_FLOWER_H
