#include <iostream>
#include <math.h>
#include "system_equations.hpp"

using std::cout;

void SystemEquations::print_polynomial() {
    cout << "f(x) = " << X[0];
    for (int i = 1; i < X.size(); i++)
        cout << " + " << X[i] << "*x^" << i;
    cout << "\n";
}

double SystemEquations::calculate(double x) {
    double sum = 0;
    for (int i = 0; i < X.size(); i++)
        sum += X[i] * pow(x, i);
    return sum;
}

vector<double> SystemEquations::substituicoes_retroativas_superior(vector<vector<double>> const &A, vector<double> const &b) {
    int n = A.size();
    vector<double> x(n);
    x[n - 1] = b[n - 1]/A[(n - 1)][(n - 1)];
    for (int i = n - 2; i >= 0; i--)
    {
        double soma = 0;
        for (int j = i + 1; j < n; j++)
            soma += A[i][j] * x[j];
        x[i] = (b[i] - soma)/A[i][i];
    }
    return x;
}

vector<double> SystemEquations::gauss(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double m = (-A[i][k]) / A[k][k];
            A[i][k] = 0;
            for (int j = k + 1; j < n; j++)
                A[i][j] += m * A[k][j];
            b[i] += m * b[k];
        }
    }
    return substituicoes_retroativas_superior(A, b);
}

SystemEquations::SystemEquations(vector<Point> const &points) : p(points) {
    int pts = p.size();

    vector<vector<double>> A(pts, vector<double> (pts));
    vector<double> b(pts);

    for (int y = 0; y < pts; y++)
        for (int x = 0; x < pts; x++)
            A[y][x] = pow(p[y].x, x);
    for (int y = 0; y < pts; y++)
        b[y] = p[y].y;
    
    X = gauss(A, b);
}