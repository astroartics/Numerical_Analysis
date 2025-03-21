#include "Matrix.hpp"

using namespace std;

void Matrix::basicPivoting(int currIndex)
{
    int j = 0;
    int zeroRowFlag = 0;

    for (int i = currIndex; i < rows - 1; i++)
    {
        for (j = i + 1; j < rows; j++)
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

    // Swapping the rows (current zero element row and with corresponding non-zero row)
    int temp[rows + 1];
    for (int i = 0; i <= rows; i++)
    {
        temp[i] = mat[currIndex][i];
    }

    for (int i = 0; i <= rows; i++)
    {
        mat[currIndex][i] = mat[j][i];
    }

    for (int i = 0; i <= rows; i++)
    {
        mat[j][i] = temp[i];
    }
}

Matrix Matrix::backSubstitution()
{
    Matrix x(1, rows);

    for (int i = rows - 1; i >= 0; i--)
    {
        x.mat[0][i] = mat[i][rows];

        for (int j = i + 1; j < rows; j++)
        {
            x.mat[0][i] -= (mat[i][j] * x.mat[0][j]);
        }
    }

    return x;
}

void Matrix::upperTriangular()
{
    for (int i = 0; i < rows; i++)
    {
        if (mat[i][i] == 0)
        {
            basicPivoting(i);
        }

        // Making diagonal element 1 by dividing entire row by that diagonal element
        long double diagonalEle = mat[i][i];
        mat[i][i] = 1;
        for (int m = 1; m < cols; m++)
        {
            mat[i][m] /= diagonalEle;
        }

        for (int j = i + 1; j < rows; j++)
        {
            long double eleBelowDiagonal = mat[j][i];

            for (int k = i; k < cols; k++)
            {
                mat[j][k] -= (eleBelowDiagonal * mat[i][k]);
            }
        }
    }
}

Matrix Matrix::GaussianElimination()
{
    upperTriangular();

    Matrix result = backSubstitution();

    return result;
}

/*
When a local array is declared inside a function, it is created on the stack. Once the function exits, the stack memory is reclaimed, and any reference to that array becomes invalid. Therefore, if you try to return a local array, it would point to a memory location that no longer exists, causing undefined behavior.
By declaring the array as static, the array is moved from the stack to static storage (usually the data segment), meaning that it persists for the lifetime of the program. The function will return a reference to this array, which is valid even after the function exits.
*/