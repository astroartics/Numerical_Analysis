#include "Matrix.hpp"

using namespace std;

void Matrix::upperTriangular(int n)
{
    for (int i = 0; i < n - 1; i++) // Going till the last row
    {
        if (mat[i][i] == 0)
        {
            cout << "\n\n0 on diagonal!\n\n";
            exit(0);
        }

        for (int j = i + 1; j < n; j++) // Going till the last row after ith row
        {
            double firstEleBelow = mat[j][i];
            double ratio = firstEleBelow / mat[i][i];
            for (int k = 0; k <= n; k++) // Going from the first column till the last
            {
                mat[j][k] -= (ratio * mat[i][k]);
            }
        }
    }

    // Making the diagonal elements 1
    for (int i = 0; i < n; i++)
    {
        int diagonalEle = mat[i][i];
        for (int j = i; j <= n; j++)
        {
            mat[i][j] /= diagonalEle;
        }
    }

    displayMat();
}

void Matrix::backSubstitution(int n)
{
    
}

double *Matrix::GaussianElimination(int rows, int cols)
{
    // double *ans = new double[n]; // static keyword is used to ensure that the array's lifetime extends beyond the scope of the function, which would otherwise be limited to the function's execution.
    // for (int i = 0; i < 3; i++)
    // {
    //     ans[i] = i + 1;
    // }

    upperTriangular(rows);
    return 0;
}

/*
When a local array is declared inside a function, it is created on the stack. Once the function exits, the stack memory is reclaimed, and any reference to that array becomes invalid. Therefore, if you try to return a local array, it would point to a memory location that no longer exists, causing undefined behavior.
By declaring the array as static, the array is moved from the stack to static storage (usually the data segment), meaning that it persists for the lifetime of the program. The function will return a reference to this array, which is valid even after the function exits.
*/