#include "Matrix.hpp"

Matrix::Matrix()
{
    mat = new double *[rows]; // Double pointer pointing to the first element of array of pointers -> that points to the rows of the matrix
    for (int i = 0; i < cols; i++)
    {
        mat[i] = new double[cols]; // mat[i] pointer points to the first element of the ith row with 'cols' columns.
    }
}