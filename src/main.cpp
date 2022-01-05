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
    SystemEquations systemEquations(p);
    systemEquations.print_polynomial();
    cout << "f(" << 2 << "): " << systemEquations.calculate(2) << "\n";

    cout << "\n";

    // Lagrange
    cout << "Lagrange\n";
    Lagrange lagrange(p);
    lagrange.print_polynomial();
    cout << "f(" << 2 << "): " << lagrange.calculate(2) << "\n";

    cout << "\n";

    // Newton
    cout << "Newton\n";
    Newton newton(p);
    newton.print_polynomial();
    cout << "f(" << 2 << "): " << newton.calculate(2) << "\n";
    
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
