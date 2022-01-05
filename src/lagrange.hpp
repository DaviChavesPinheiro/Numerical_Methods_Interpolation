#pragma once

#include <vector>
#include "point.hpp"

using std::vector;

class Lagrange
{
private:
    vector<Point> p;
    double L(int k, double x);
public:
    Lagrange(vector<Point> const &points);
    void print_polynomial();
    double calculate(double x);
};

