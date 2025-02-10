#include "Matrix.hpp"

using namespace std;

double **Matrix::createMatrix()
{
    if (rows > 0 && cols > 0)
    {
        mat = new double *[this->rows]; // Double pointer pointing to the first element of array of pointers -> that points to the rows of the matrix
        for (int i = 0; i < this->rows; i++)
        {
            mat[i] = new double[this->cols]; // mat[i] pointer points to the first element of the ith row with 'cols' columns.
        }
        return mat;
    }
    else
    {
        cerr << "Number of rows and columns mmust be greater than 0!" << endl;
        exit(0);
    }
}

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int r, int c)
{
    this->rows = r;
    this->cols = c;
    mat = createMatrix();
}

Matrix::Matrix(string filename)
{
    ifstream matFile(filename);

    if (!matFile)
    {
        cout << "Error opening the matrix file!" << endl;
        exit(0);
    }

    string firstLine = "";

    getline(matFile, firstLine);

    istringstream sStream(firstLine);
    if (!(sStream >> this->rows >> this->cols)) // sStream >> rows >> cols; extracts the first two integers from the stream and assigns them to rows and cols.
    {
        std::cerr << "Error reading dimensions." << std::endl;
        exit(0);
    }

    mat = createMatrix();

    for (int i = 0; i < this->rows; ++i)
    {
        getline(matFile, firstLine);
        istringstream sStream(firstLine);
        double num = 0.0;
        for (int j = 0; j < this->cols; ++j)
        {
            sStream >> mat[i][j];
        }
    }
}

void Matrix::displayMat()
{
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Copy constructor
// Matrix::Matrix(const Matrix &matrix)
// {
//     mat = new double *[rows];
//     for (int i = 0; i < rows; i++)
//     {
//         mat[i] = new double[cols];
//     }
// }

Matrix::~Matrix()
{
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->mat[i]; // De-allocating the memory held by row pointers first
    }
    delete[] this->mat; // Then de-allocating the memory held by the double pointer
}