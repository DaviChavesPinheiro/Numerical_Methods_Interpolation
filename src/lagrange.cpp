#include <iostream>
#include "lagrange.hpp"
using std::cout;

void Lagrange::print_polynomial() {
    cout << "f(x) = ";
    for (int i = 0; i < p.size(); i++) {
        cout << " + " << p[i].y << " * (";

        cout << "(";
        int k = i;
        for (int j = 0; j < p.size(); j++)
            if(k != j) cout << "(x - " << p[j].x << ")";
        cout << ")";
        cout << "/";
        cout << "(";
        for (int j = 0; j < p.size(); j++)
            if(k != j) cout << "(" << p[k].x << " - " << p[j].x << ")";
        cout << ")";
        cout << ")";
    }
    cout << "\n";
}

double Lagrange::calculate(double x) {
    double py = 0;
    for (int i = 0; i < p.size(); i++)
        py += p[i].y * L(i, x);

    return py;
}

double Lagrange::L(int k, double x) {
    double lkx = 1; // Lk(x)
    for (int i = 0; i < p.size(); i++)
        if(k != i) lkx *= (x - p[i].x) / (p[k].x - p[i].x);
    return lkx;    
}

Lagrange::Lagrange(vector<Point> const &points) : p(points) {}
