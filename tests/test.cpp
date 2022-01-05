#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lagrange.hpp"
#include <vector>
using std::vector;


TEST_CASE( "Factorials are computed", "[factorial]" ) {

    vector<Point> p = { // points
        {-5, 3},
        {2, -2},
        {5, 3}, 
        {7, 1}
    };

    REQUIRE(lagrange(p, 2) == -2);
}
