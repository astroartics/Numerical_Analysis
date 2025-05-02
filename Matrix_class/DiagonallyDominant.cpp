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
            if (!(abs(mat[i][i]) > abs(sum)))
            {
                // if (i == rows - 1)
                //     return false;

                if (!makeDiagonallyDominant(i))
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

bool Matrix::makeDiagonallyDominant(int currRow)
{
    // cout << currRow << "\n\n";

    int j = 0, sum = 0;
    int diagonallyDominantRow = 0;

    for (int i = currRow; i < rows - 1; i++)
    {
        for (j = i + 1; j < rows; j++)
        {
            sum = 0;
            for (int k = 0; k < cols; k++)
            {
                if (i != k)
                    sum += mat[j][k];
            }

            // cout << abs(mat[j][i]) << "\n\n";

            if ((abs(mat[j][i]) > abs(sum)))
            {
                // cout << "HERE\n\n";
                diagonallyDominantRow = 1;
                break;
            }
        }
        if (diagonallyDominantRow)
            break;
    }

    if (diagonallyDominantRow == 0)
    {
        // cout << "HERE\n\n";
        return false;
    }

    // Swapping the rows (current zero element row and with corresponding non-zero row)
    Matrix temp(rows + 1, 1);
    for (int i = 0; i <= rows; i++)
    {
        temp.mat[i][0] = mat[currRow][i];
    }

    for (int i = 0; i <= rows; i++)
    {
        mat[currRow][i] = mat[j][i];
    }

    for (int i = 0; i <= rows; i++)
    {
        mat[j][i] = temp.mat[i][0];
    }

    // displayMat();

    return true;
}