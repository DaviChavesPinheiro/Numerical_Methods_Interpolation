#pragma once

#include <vector>
#include "point.hpp"

using std::vector;

vector<double> substituicoes_retroativas_superior(vector<vector<double>> const &A, vector<double> const &b);

vector<double> gauss(vector<vector<double>> A, vector<double> b);

vector<double> system_equation(vector<Point> p);

void print_polynomial(vector<double> a);
