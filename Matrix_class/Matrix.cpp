#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int r, int c)
{
    this->rows = r;
    this->cols = c;
}

Matrix::Matrix()
{
    cout << "here";
    mat = new double *[rows]; // Double pointer pointing to the first element of array of pointers -> that points to the rows of the matrix
    for (int i = 0; i < rows; i++)
    {
        mat[i] = new double[cols]; // mat[i] pointer points to the first element of the ith row with 'cols' columns.
    }
}

Matrix::Matrix(string filename)
{
    Matrix();

    ifstream matFile(filename);

    if (!matFile)
    {
        cout << "Error opening the matrix file!" << endl;
        exit(0);
    }

    char fileChar;
    string firstLine;

    getline(matFile, firstLine);
    this->rows = firstLine[0] - '0';
    this->cols = firstLine[2] - '0';

    cout << this->rows << " " << this->cols << endl;

    // Matrix();

    // while (matFile)
    // {
    //     fileChar = matFile.get();
    //     if (fileChar >= '0' && fileChar <= '9')
    //     {
    //         // int num = fileChar - '0';
    //         // cout << num << " ";
    //     }
    // }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i]; // De-allocating the memory held by row pointers first
    }
    delete[] mat; // Then de-allocating the memory held by the double pointer
}