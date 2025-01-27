#include <cmath>
#include <bits/stdc++.h> // Use to include all the standard libraries
#define TOL 0.000001     // 10^6 Tolerance for maximum accuracy

using namespace std;

class RootFinding
{
public:
    // void hornersRule(double x, int count...)
    // {
    //     va_list coeff;
    //     va_start(coeff, count);
    //     for (int i = 0; i < count; i++)
    //         x *= (va_arg(coeff, double) + x);
    //     cout << x << "\n\n";
    //     va_end(coeff);
    // }

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

    void BisectionMethod();
    void NewtonRaphsonMethod();
};