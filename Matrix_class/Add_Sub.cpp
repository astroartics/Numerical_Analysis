#include "Matrix.hpp"

using namespace std;

Matrix Matrix::add(Matrix B)
{
    if ((this->rows == B.rows) && (this->cols == B.cols))
    {
        Matrix result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.mat[i][j] = this->mat[i][j] + B.mat[i][j];
            }
        }

        return result;
    }
    else
    {
        cerr << "Matrices cannot be added!" << endl;
        exit(0);
    }
}

Matrix Matrix::operator+(Matrix B)
{
    Matrix result = (*this).add(B);
    return result;
}

Matrix Matrix::subtract(Matrix B)
{
    if ((this->rows == B.rows) && (this->cols == B.cols))
    {
        Matrix result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.mat[i][j] = this->mat[i][j] - B.mat[i][j];
            }
        }

        return result;
    }
    else
    {
        cerr << "Matrices cannot be subtracted!" << endl;
        exit(0);
    }
}

Matrix Matrix::operator-(Matrix B)
{
    Matrix result = (*this).subtract(B);
    return result;
}