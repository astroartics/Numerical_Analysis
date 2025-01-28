#include <cmath>
#include <bits/stdc++.h> // Use to include all the standard libraries
#define TOL 0.000001     // 10^6 Tolerance for maximum accuracy

using namespace std;

class RootFinding
{
public:
    vector<double> coefficients;

    double f(double x)
    {
        return (2 * x * x) - 1;
        // return (x * x) + (2 * x) - 3;
        // return (x + 2) * (x + 3) * (x + 4);
    }

    double fDerivative(double x)
    {
        return (4 * x);
        // return (2 * x) + 2;
        // return (3 * x * x) + (18 * x) + 26;
    }

    void acceptCoefficients();
    double HornersRule(double x);
    void BisectionMethod();
    void NewtonRaphsonMethod();
};