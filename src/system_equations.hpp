#pragma once

#include <vector>
#include "point.hpp"

using std::vector;

class SystemEquations
{
private:
    vector<double> X; // Vetor solucão
    vector<Point> p; // Pontos

    vector<double> substituicoes_retroativas_superior(vector<vector<double>> const &A, vector<double> const &b);
    vector<double> gauss(vector<vector<double>> A, vector<double> b);
public:
    SystemEquations(vector<Point> const &points);
    void print_polynomial();
    double calculate(double x);
};





