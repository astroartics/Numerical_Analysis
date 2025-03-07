#include "Matrix.hpp"

using namespace std;

void Matrix::basicPivoting(int n, int currIndex)
{
    int j = 0;
    int zeroRowFlag = 0;

    for (int i = currIndex; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (mat[j][i] != 0)
            {
                zeroRowFlag = 1;
                break;
            }
        }
        if (zeroRowFlag == 1)
            break;
    }

    if (zeroRowFlag == 0)
    {
        cout << "\nSystem is not solvable as x" << (j - 1) << " has no corresponding non-zero element in the matrix.\n"
             << endl;
        exit(0);
    }

    int temp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        temp[i] = mat[currIndex][i];
    }

    for (int i = 0; i <= n; i++)
    {
        mat[currIndex][i] = mat[j][i];
    }

    for (int i = 0; i <= n; i++)
    {
        mat[j][i] = temp[i];
    }
}

void Matrix::upperTriangular(int n)
{
    for (int i = 0; i < n - 1; i++) // Going till the last row
    {
        if (mat[i][i] == 0)
        {
            // cout << "\n\n0 on diagonal!\n\n";
            basicPivoting(n, i);
        }

        for (int j = i + 1; j < n; j++) // Going till the last row after ith row
        {
            double ratio = mat[j][i] / mat[i][i]; // Taking the ratio of the element in the row below the diagonal element and the diagonal element so that it can be subtracted with the row elements below the current row (ultimately subtracting the element in row below with itself, as the element on the diagonal will be 1).
            for (int k = 0; k <= n; k++)          // Going from the first column till the last
            {
                mat[j][k] -= (ratio * mat[i][k]); // Multiplying the ratio with the entire previous row elements ans subtracting from the current row to make the elements below current element 0.
            }
        }
    }

    backSubstitution(n);
}

double *Matrix::backSubstitution(int n)
{
    static double *x = new double[n];

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = mat[i][n];

        for (int j = i + 1; j < n; j++)
        {
            x[i] -= (mat[i][j] * x[j]);
        }
        x[i] /= mat[i][i];
    }

    return x;
}

double *Matrix::GaussianElimination(int n)
{
    upperTriangular(n);

    double *result = backSubstitution(n);

    return result;
}

/*
When a local array is declared inside a function, it is created on the stack. Once the function exits, the stack memory is reclaimed, and any reference to that array becomes invalid. Therefore, if you try to return a local array, it would point to a memory location that no longer exists, causing undefined behavior.
By declaring the array as static, the array is moved from the stack to static storage (usually the data segment), meaning that it persists for the lifetime of the program. The function will return a reference to this array, which is valid even after the function exits.
*/