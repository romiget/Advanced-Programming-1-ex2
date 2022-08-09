cmake_minimum_required(VERSION 3.22)
project(Server_Side)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server_Side main.cpp Measurable.cpp Measurable.h Flower.cpp Flower.h Metric.cpp Metric.h EuclideanMetric.cpp EuclideanMetric.h ManhattanMetric.cpp ManhattanMetric.h ChebyshevMetric.cpp ChebyshevMetric.h MeasurableList.cpp MeasurableList.h FileHandler.cpp FileHandler.h Communication.cpp Communication.h)
