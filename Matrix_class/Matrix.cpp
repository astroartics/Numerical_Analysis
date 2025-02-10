#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int r, int c)
{
    this->rows = r;
    this->cols = c;
}

Matrix::Matrix()
{
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
    string firstLine = "";

    getline(matFile, firstLine);

    istringstream sStream(firstLine);
    int rows, cols;
    if (!(sStream >> rows >> cols)) // sStream >> rows >> cols; extracts the first two integers from the stream and assigns them to rows and cols.
    {
        std::cerr << "Error reading dimensions." << std::endl;
        exit(0);
    }
    cout << rows << " " << cols << endl;

    Matrix();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
        }
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