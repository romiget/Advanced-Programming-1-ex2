cmake_minimum_required(VERSION 3.22)
project(Advanced_Programming_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Advanced_Programming_1 main.cpp Measurable.cpp Measurable.h Flower.cpp Flower.h Metric.cpp Metric.h EuclideanMetric.cpp EuclideanMetric.h ManhattanMetric.cpp ManhattanMetric.h ChebyshevMetric.cpp ChebyshevMetric.h MeasurableList.cpp MeasurableList.h FileHandler.cpp FileHandler.h)
