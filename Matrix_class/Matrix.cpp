#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
}

Matrix::Matrix()
{
    mat = new double *[rows]; // Double pointer pointing to the first element of array of pointers -> that points to the rows of the matrix
    for (int i = 0; i < cols; i++)
    {
        mat[i] = new double[cols]; // mat[i] pointer points to the first element of the ith row with 'cols' columns.
    }
}

Matrix::Matrix(string filename)
{
    ifstream matFile(filename);

    if (!matFile)
    {
        cout << "Error opening the matrix file!" << endl;
        exit(0);
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i]; // De-allocating the memory held by row pointers first
    }
    delete[] mat; // Then de-allocating the memory held by the double pointer
}