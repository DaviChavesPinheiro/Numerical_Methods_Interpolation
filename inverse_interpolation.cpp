#include <iostream>
#include "inverse_interpolation.hpp"
using std::cout;

InverseInterpolation::InverseInterpolation(vector<Point> points) {
    int pts = points.size();

    // Inversed points (x;y) ---> (y;x)
    vector<Point> p(pts);
    for (int i = 0; i < pts; i++)
        p[i] = {points[i].y, points[i].x};
    newton = new Newton(p);
}

void InverseInterpolation::print_polynomial() {
    newton->print_polynomial();
}

double InverseInterpolation::calculate(double x) {
    return newton->calculate(x);
}

InverseInterpolation::~InverseInterpolation() {
    delete newton;
}