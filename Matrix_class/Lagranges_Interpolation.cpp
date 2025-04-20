#include "Interpolation.hpp"

using namespace std;

long double Interpolation::LagrangesInterpolation(long double x, Matrix fi)
{
    long double ratio = 1.0, result = 0.0;

    long int rows = (m.rows > m.cols ? m.rows : m.cols);

    for (int i = 0; i < rows; i++)
    {
        ratio = 1.0;
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
            {
                ratio *= (x - m.mat[0][j]) / (m.mat[0][i] - m.mat[0][j]);
            }
        }
        result += (fi.mat[0][i] * ratio);
    }

    // cout << result << endl;

    return result;
}