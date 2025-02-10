#include "Matrix.hpp"

using namespace std;

bool Matrix::isIdentity()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if ((i == j && (mat[i][j] != 1)) || (i != j && (mat[i][j] != 0)))
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetric()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (i != j && (mat[i][j] != mat[j][i]))
            {
                return false;
            }
        }
    }
    return true;
}