#include <iostream>
#include <math.h>
#include "newton.hpp"

using std::cout;

Newton::Newton(vector<Point> const &points) 
: p(points) {
    createTable();
}

void Newton::createTable() {
    // Initialize the first columns of the table with the values of f(x)
    for (int y = 0; y < p.size(); y++) {
        t.push_back(vector<double>(1));
        t[y][0] = p[y].y;
    }
    
    // Allocates space on the table
    for (int i = 0; i < p.size(); i++)
        t[i].resize(p.size() - i);

    // Computes the rest of the table values
    for (int x = 1; x < p.size(); x++)
        for (int y = 0; y < p.size() - x; y++) {
            t[y][x] = (t[y + 1][x - 1] - t[y][x - 1]) / (p[y + x].x - p[y].x);
        }
            
}

double Newton::calculate(double x) {
    double sum = 0;
    for (int i = 0; i < p.size(); i++)
        sum += t[0][i] * proterm(x, i);
    return sum;
}

// Computes the Difference Product: (x - x0)(x - x1) ... (x - xk-1)
double Newton::proterm(double x, int k) {
    double pro = 1;
    for (int i = 0; i < k; i++)
        pro *= (x - p[i].x);
    return pro;
}

void Newton::addPoint(Point point) {
    p.push_back(point);
    addTablePoint(point);
}

void Newton::addTablePoint(Point point) {
    // Adds f[xn]
    t.push_back(vector<double>(1));
    t[t.size() - 1][0] = point.y;

    // Adds the other divided differences
    for (int i = 1; i < t.size(); i++)
    {
        int x = i;
        int y = t.size() - 1 - i;
        t[y].push_back((t[y + 1][x - 1] - t[y][x - 1]) / (p[y + x].x - p[y].x));
    }
}

void Newton::printTable() {
    for (int y = 0; y < t.size(); y++)
    {
        for (int x = 0; x < t[y].size(); x++)
            cout << t[y][x] << " ";
        cout << "\n";
    }
}

void Newton::print_polynomial() {
    cout << "f(x) = " << t[0][0];
    for (int i = 1; i < t.size(); i++) {
        cout << " + " << t[0][i] << "*";
        for (int j = 0; j < i; j++)
            cout << "(x - " << p[j].x << ")";
    }
    cout << "\n";
}