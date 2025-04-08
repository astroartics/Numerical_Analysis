#include "Matrix.hpp"

using namespace std;

bool Matrix::isDiagonallyDominant()
{
    if (this->rows == this->cols)
    {
        for (int i = 0; i < rows; i++)
        {
            int sum = 0;
            for (int j = 0; j < cols; j++)
            {
                if (i != j)
                {
                    sum += mat[i][j];
                }
            }
            if (!(abs(mat[i][i]) >= abs(sum)))
            {
                if (makeDiagonallyDominant(i) == -1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        return true;
    }
    else
    {
        cout << "Matrix has to be a square (nxn) matrix!" << endl;
        return false;
    }
}

int Matrix::makeDiagonallyDominant(int currRow)
{
    int j = 0, sum = 0;
    int diagonallyDominantRow = 0;

    for (int i = currRow; i < rows - 1; i++)
    {
        for (j = i + 1; j < rows; j++)
        {
            sum = 0;
            for (int k = 0; k < cols; k++)
            {
                sum += mat[j][k];
            }
            if ((abs(mat[i][i]) >= abs(sum)))
            {
                diagonallyDominantRow = 1;
                break;
            }
        }
        if (diagonallyDominantRow)
            break;
    }

    if (diagonallyDominantRow == 0)
    {
        return -1;
    }

    // Swapping the rows (current zero element row and with corresponding non-zero row)
    int temp[rows + 1];
    for (int i = 0; i <= rows; i++)
    {
        temp[i] = mat[currRow][i];
    }

    for (int i = 0; i <= rows; i++)
    {
        mat[currRow][i] = mat[j][i];
    }

    for (int i = 0; i <= rows; i++)
    {
        mat[j][i] = temp[i];
    }

    return 1;
}