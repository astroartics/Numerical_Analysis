#include "Interpolation.hpp"

using namespace std;

long double Interpolation::LagrangesInterpolation(long double x, Matrix fi)
{
    long double ratio = 1.0, result = 0.0;

    for (int i = 0; i < m.cols; i++)
    {
        ratio = 1.0;
        for (int j = 0; j < m.cols; j++)
        {
            if (i != j)
            {
                ratio *= (x - m.mat[0][j]) / (m.mat[0][i] - m.mat[0][j]);
            }
        }
        result += (fi.mat[0][i] * ratio);
    }

    return result;
}