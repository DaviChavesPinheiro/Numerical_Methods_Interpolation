#include <vector>
#include "point.hpp"

using std::vector;

void print_lagrange_polynomial(vector<double> a);

double L(int k, double x, vector<Point> const &p);

double lagrange(vector<Point> p, double x);
