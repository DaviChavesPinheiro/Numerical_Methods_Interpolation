#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct
{
    double x, y;
} Point;

void print_polynomial(vector<double> a) {
    cout << "f(x) = " << a[0];
    for (int i = 1; i < a.size(); i++)
        cout << " + " << a[i] << "*x^" << i;
    cout << "\n";
}

vector<double> substituicoes_retroativas_superior(vector<vector<double>> const &A, vector<double> const &b) {
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

vector<double> gauss(vector<vector<double>> A, vector<double> b) {
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

vector<double> system_equation(vector<Point> p) {
    int pts = p.size();

    vector<vector<double>> A(pts, vector<double> (pts));
    vector<double> b(pts);

    for (int y = 0; y < pts; y++)
        for (int x = 0; x < pts; x++)
            A[y][x] = pow(p[y].x, x);
    for (int y = 0; y < pts; y++)
        b[y] = p[y].y;
    
    return gauss(A, b);
}

int main(int argc, char const *argv[])
{
    vector<Point> p = { // points
        {-5, 3},
        {2, -2},
        {5, 3}, 
        {7, 1}
    };
    
    vector<double> x = system_equation(p);
    print_polynomial(x);
    return 0;
}
