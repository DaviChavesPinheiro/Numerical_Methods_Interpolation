#pragma once

#include <vector>
#include "newton.hpp"
#include "point.hpp"
using std::vector;

class InverseInterpolation
{
private:
    Newton *newton;
public:
    InverseInterpolation(vector<Point> points);
    ~InverseInterpolation();
    void print_polynomial();
    double calculate(double x);
};




