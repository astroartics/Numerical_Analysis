#include "Matrix.hpp"

using namespace std;

Matrix Matrix::multiply(Matrix B)
{
    if (this->cols == B.rows)
    {
        Matrix result(this->rows, B.cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < B.rows; j++)
            {
                result.mat[i][j] = 0;
                for (int k = 0; k < this->cols; k++)
                {
                    result.mat[i][j] += this->mat[i][k] * B.mat[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        cerr << "Matrices cannot be multiplied!" << endl;
        exit(0);
    }
}

Matrix Matrix::operator*(Matrix B)
{
    Matrix result = (*this).multiply(B);
    return result;
}