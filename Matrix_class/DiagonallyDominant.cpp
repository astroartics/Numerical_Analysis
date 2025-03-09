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
                return false;
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