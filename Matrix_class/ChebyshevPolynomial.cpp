#include "Interpolation.hpp"

using namespace std;

long double Interpolation::ChebyshevApproximation(long double x, int t)
{
    long double T_x_n2 = 1;
    long double T_x_n1 = x;
    long double result = 0.0;

    for (int i = 2; i <= t; i++)
    {
        result = (2 * x * (T_x_n1)-T_x_n2);
        T_x_n2 = T_x_n1;
        T_x_n1 = result;
    }

    return result;
}