#include "Matrix.hpp"

using namespace std;

void Matrix::CroutsMethod(Matrix L, Matrix U, int n)
{
    for (int i = 0; i < n; i++)
    {
        U.mat[i][i] = 1; // Unit upper triangular matrix
    }

    double sum = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            sum = 0;
            for (int k = 0; k < j; k++)
            {
                sum += L.mat[i][k] * U.mat[k][j];
            }
            L.mat[i][j] = this->mat[i][j] - sum;
        }
    }
}