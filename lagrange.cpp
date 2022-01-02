#include <iostream>
#include <vector>

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

double L(int k, double x, vector<Point> const &p) {
    int pts = p.size();
    double lkx = 1; // Lk(x)
    for (int i = 0; i < pts; i++)
        if(k != i) lkx *= (x - p[i].x) / (p[k].x - p[i].x);
    return lkx;    
}

double lagrange(vector<Point> p, double x) {
    int pts = p.size();

    double py = 0;
    for (int i = 0; i < pts; i++)
        py += p[i].y * L(i, x, p);

    return py;
}

int main(int argc, char const *argv[])
{
    vector<Point> p = { // points
        {-5, 3},
        {2, -2},
        {5, 3}, 
        {7, 1}
    };

    double px = 2;
    
    cout << "Pn(x) =";
    for (int i = 0; i < p.size(); i++)
    {
        cout << " y" << i << "L" << i << "(x)";
        if(i < p.size() - 1) cout << " +";
    }
    cout << "\n";

    cout << lagrange(p, px) << "\n";
    return 0;
}
