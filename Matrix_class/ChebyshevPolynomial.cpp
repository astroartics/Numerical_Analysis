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

long double f(long double x)
{
    return (1.0 / (1 + (12 * pow(x, 2))));
}

Matrix Interpolation::ChebyshevCoefficients(int N)
{
    Matrix fi(1, N);

    for (int i = 0; i < N; i++)
    {
        m.mat[0][i] = cos(((2.0 * i + 1.0) / N) * (M_PI / 2.0));
        fi.mat[0][i] = f(m.mat[0][i]);
    }

    return fi;
}