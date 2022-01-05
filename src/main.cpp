#include <iostream>
#include <vector>
#include "point.hpp"
#include "system_equations.hpp"
#include "lagrange.hpp"
#include "newton.hpp"
#include "inverse_interpolation.hpp"
using std::vector; using std::cout;

int main(int argc, char const *argv[])
{
    vector<Point> p = { // points
        {-5, 3},
        {2, -2},
        {5, 3}, 
        {7, 1}
    };
    
    // System Equations
    cout << "System Equations\n";
    vector<double> x1 = system_equation(p);
    print_polynomial(x1);

    cout << "\n";

    // Lagrange
    cout << "Lagrange\n";
    double px = 2;
    cout << lagrange(p, px) << "\n";

    cout << "\n";

    // Newton
    cout << "Newton\n";
    Newton newton(p);
    newton.print_polynomial();

    vector<Point> p2 = { // points
        {0.1, 1.221},
        {0.6, 3.320},
        {0.8, 4.953}, 
    };

    cout << "\n";

    // Inverse Interpolation
    cout << "Inverse Interpolation\n";
    InverseInterpolation invInter(p2);
    invInter.print_polynomial();
    return 0;
}