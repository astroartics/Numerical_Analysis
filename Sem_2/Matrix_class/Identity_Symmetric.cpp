#include "Matrix.hpp"

using namespace std;

bool Matrix::isIdentity()
{
    if (this->rows == this->cols)
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
    else
    {
        cout << "Identity matrix has to be a square (nxn) matrix!" << endl;
        return false;
    }
}

bool Matrix::isSymmetric()
{
    if (this->rows == this->cols)
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
    else
    {
        cout << "Symmetric matrix has to be a square (nxn) matrix!" << endl;
        return false;
    }
}