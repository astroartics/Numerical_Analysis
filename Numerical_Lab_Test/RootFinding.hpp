#include <cmath>
#include <bits/stdc++.h>
// #define TOL 0.000001     // 10^(-6) tolerance for maximum accuracy

using namespace std;

class RootFinding
{
public:
    vector<double> coefficients;
    double TOL;

    RootFinding()
    {
        TOL = 0.000001;
    }

    double f(double x)
    {
        return (pow(x, 4)) - 10 * (pow(x, 2)) + 9;
    }

    void setTolerance(double);
    // double BisectionMethod(int, int, int);
    vector<double> BisectionMethod(int, int, int);
};