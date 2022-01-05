#include <vector>
#include "point.hpp"
using std::vector;

class Newton
{
private:
    vector<vector<double>> t;
    vector<Point> p;

    void createTable();

    void addTablePoint(Point point);

    double proterm(double x, int k);

public:
    Newton(vector<Point> const &points);

    double calculate(double x);

    void addPoint(Point point);

    void printTable();

    void print_polynomial();
};
