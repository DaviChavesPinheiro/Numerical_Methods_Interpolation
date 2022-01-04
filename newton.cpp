#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct
{
    double x, y;
} Point;

class Newton
{
private:
    vector<vector<double>> t; // Divided Difference Table
    vector<Point> p;

    void createTable() {
        // Initialize the first columns of the table with the values of f(x)
        for (int y = 0; y < p.size(); y++) {
            t.push_back(vector<double>(1));
            t[y][0] = p[y].y;
        }
        
        // Reserve espaco na tabela
        for (int i = 0; i < p.size(); i++)
            t[i].resize(p.size() - i);

        // Calcula o resto dos valores da tabela
        for (int x = 1; x < p.size(); x++)
            for (int y = 0; y < p.size() - x; y++) {
                t[y][x] = (t[y + 1][x - 1] - t[y][x - 1]) / (p[y + x].x - p[y].x);
            }
                
    }

    void addTablePoint(Point point) {
        // Adiciona o f[xn]
        t.push_back(vector<double>(1));
        t[t.size() - 1][0] = point.y;

        // Adiciona as outras diferencas divididas
        for (int i = 1; i < t.size(); i++)
        {
            int x = i;
            int y = t.size() - 1 - i;
            t[y].push_back((t[y + 1][x - 1] - t[y][x - 1]) / (p[y + x].x - p[y].x));
        }
    }

    // Calcula o produtos das diferencas: (x - x0)(x - x1) ... (x - xk-1)
    double proterm(double x, int k) {
        double pro = 1;
        for (int i = 0; i < k; i++)
            pro *= (x - p[i].x);
        return pro;
    }

public:
    Newton(vector<Point> const &points) 
    : p(points) {
        createTable();
    }

    double calculate(double x) {
        double sum = 0;
        for (int i = 0; i < p.size(); i++)
            sum += t[0][i] * proterm(x, i);
        return sum;
    }

    void addPoint(Point point) {
        p.push_back(point);
        addTablePoint(point);
    }

    void printTable() {
        for (int y = 0; y < t.size(); y++)
        {
            for (int x = 0; x < t[y].size(); x++)
                cout << t[y][x] << " ";
            cout << "\n";
        }
    }

    void print_polynomial() {
        cout << "f(x) = " << t[0][0];
        for (int i = 1; i < t.size(); i++) {
            cout << " + " << t[0][i] << "*";
            for (int j = 0; j < i; j++)
                cout << "(x - " << p[j].x << ")";
        }
        cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    vector<Point> p = { // points
        {-5, 3},
        {2, -2},
        {5, 3}, 
        {7, 1}
    };

    Newton newton(p);
    newton.addPoint({15, 0});
    newton.printTable();
    newton.print_polynomial();
    
    return 0;
}
