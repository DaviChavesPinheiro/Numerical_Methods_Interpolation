#include <iostream>
#include "lagrange.hpp"
using std::cout;

void print_lagrange_polynomial(vector<double> a) {
    std::cerr << "No implementation\n";
}

double L(int k, double x, vector<Point> const &p) {
    int pts = p.size();
    double lkx = 1; // Lk(x)
    for (int i = 0; i < pts; i++)
        if(k != i) lkx *= (x - p[i].x) / (p[k].x - p[i].x);
    return lkx;    
}

double lagrange(vector<Point> p, double x) {
    int pts = p.size();

    double py = 0;
    for (int i = 0; i < pts; i++)
        py += p[i].y * L(i, x, p);

    return py;
}
