#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "point.hpp"
#include "system_equations.hpp"
#include "lagrange.hpp"
#include "newton.hpp"
#include "inverse_interpolation.hpp"
#include <vector>
using std::vector;


TEST_CASE("System Equations: P1 11:40", "[system_equations]") {
    vector<Point> p = { // points
        {0.1, 1.221},
        {0.6, 3.320},
    };

    SystemEquations systemEquations(p);

    CHECK(systemEquations.calculate(0.2) == Approx(1.641).epsilon(0.01));
    CHECK(systemEquations.calculate(0.3) == Approx(2.061).epsilon(0.01));
}

TEST_CASE("Lagrange: P2 7:10", "[lagrange]") {
    vector<Point> p = { // points
        {0.1, 1.221},
        {0.6, 3.320},
    };

    Lagrange lagrange(p);

    CHECK(lagrange.calculate(0.2) == Approx(1.641).epsilon(0.01));
}

TEST_CASE("Lagrange: P2 12:00", "[lagrange]") {
    vector<Point> p = { // points
        {0.1, 1.221},
        {0.6, 3.320},
        {0.8, 4.953},
    };

    Lagrange lagrange(p);

    CHECK(lagrange.calculate(0.2) == Approx(1.417).epsilon(0.01));
}

TEST_CASE("Newton: P3 22:50", "[newton]") {
    vector<Point> p = { // points
        {0.1, 1.221},
        {0.6, 3.320},
        {0.8, 4.953},
    };

    Newton newton(p);

    CHECK(newton.calculate(0.2) == Approx(1.414).epsilon(0.01));
}

TEST_CASE("Inverse: P4 9:10", "[inverse]") {
    vector<Point> p = { // points
        {0.2, 1.2214},
        {0.3, 1.3499},
        {0.4, 1.4918}, 
    };

    InverseInterpolation inverseInterpolation(p);

    CHECK(inverseInterpolation.calculate(1.3165) == Approx(0.27487).epsilon(0.01));
}
