#include "Interpolation.hpp"

using namespace std;

long double Interpolation::LagrangesInterpolation(long double x, Matrix fi)
{
    long double numerator = 1.0, denominator = 1.0, fi_add = 0.0, result = 0.0;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != j)
            {
                numerator *= (x - mat[0][j]);
                denominator *= (mat[0][i] - mat[0][j]);
                cout << (x - mat[0][j]) << "\t" << (mat[0][i] - mat[0][j]) << endl;
            }
        }
        fi_add += fi.mat[0][i] * (numerator / denominator);
    }

    // result = numerator / denominator;
    cout << fi_add << endl;
    return result;
}