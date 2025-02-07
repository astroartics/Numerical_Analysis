#include <cmath>
#include <bits/stdc++.h> // Used to include all the standard libraries
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
        // return x + 2;
        // return (2 * x * x) - 1;
        // return (x * x) + (2 * x) - 3;
        // return (x + 2) * (x + 3) * (x + 4);
        return (x * x) - (5 * x) + 5;
        // return (2 * x * x) + (3 * x) - 2;
    }

    double fDerivative(double x)
    {
        // return 1;
        // return (4 * x);
        // return (2 * x) + 2;
        // return (3 * x * x) + (18 * x) + 26;
        return (2 * x) - 5;
        // return (4 * x) + 3;
    }

    double q(double x)
    {
        // return (1 / (sqrt(2) * x));
        // return (3 - (x * x)) / 2;
        return (((x * x) + 5) / 5);
        // return (2 * (sqrt(x - 1)));
    }

    void acceptCoefficients();
    void setTolerance(double tol);
    double HornersRule(double x);
    double BisectionMethod(int lb, int ub, int printItr);
    double NewtonRaphsonMethod(double sp, int printItr);
    double FixedPoint(int printItr);
};