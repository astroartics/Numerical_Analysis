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

Matrix Interpolation::SplineInterpolation(long double x, Matrix fi, int splineCount)
{
    int totalPoints = (m.rows > m.cols ? m.rows : m.cols);
    int pointsPerSpline = totalPoints / splineCount;
    int remainder = totalPoints % splineCount;

    Matrix result(1, 1); // Output : single interpolated value

    int startIndex = 0;

    // Find which spline interval x falls into
    for (int s = 0; s < splineCount; s++)
    {
        int endIndex = startIndex + pointsPerSpline - 1;

        // Distributing remaining points among first splines
        if (s < remainder)
            endIndex += 1;

        // So that we don’t go out of bounds
        if (endIndex >= totalPoints)
            endIndex = totalPoints - 1; // Last index of x

        // Checking if x falls in this spline interval, else it cannot be interpolated
        if (x >= m.mat[0][startIndex] && x <= m.mat[0][endIndex])
        {
            // Lagrange's interpolation.
            long double ratio, interpolatedValue = 0.0;

            for (int i = startIndex; i <= endIndex; i++)
            {
                ratio = 1.0;
                for (int j = startIndex; j <= endIndex; j++)
                {
                    if (i != j)
                    {
                        ratio *= (x - m.mat[0][j]) / (m.mat[0][i] - m.mat[0][j]);
                    }
                }
                interpolatedValue += (fi.mat[0][i] * ratio);
            }

            result.mat[0][0] = interpolatedValue;
            break;
        }

        startIndex = endIndex + 1;
    }

    return result;
}