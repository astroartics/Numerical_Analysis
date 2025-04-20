#include "Matrix.hpp"

using namespace std;

long double **Matrix::createMatrix()
{
    if (rows > 0 && cols > 0)
    {
        mat = new long double *[this->rows]; // Double pointer pointing to the first element of array of pointers -> that points to the rows of the matrix
        for (int i = 0; i < this->rows; i++)
        {
            mat[i] = new long double[this->cols]; // mat[i] pointer points to the first element of the ith row with 'cols' columns.
        }
        if (!mat)
        {
            cerr << "Memory cannot be allocated" << endl;
            exit(0);
        }
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                mat[i][j] = 0;
            }
        }
        return mat;
    }
    else
    {
        cerr << "Number of rows and columns must be greater than 0!" << endl;
        exit(0);
    }
}

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
    mat = nullptr;
}

Matrix::Matrix(int r, int c)
{
    this->rows = r;
    this->cols = c;
    mat = createMatrix();
}

Matrix::Matrix(long double **other, int r, int c) // Constructor for converting a matrix to an object
{
    this->rows = r;
    this->cols = c;
    mat = createMatrix();
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            mat[i][j] = other[i][j];
        }
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

    string firstLine = "";

    getline(matFile, firstLine);

    istringstream sStream(firstLine);
    if (!(sStream >> this->rows >> this->cols)) // 'sStream >> rows >> cols;' extracts the first two integers from the stream and assigns them to rows and cols.
    {
        std::cerr << "Error reading dimensions." << std::endl;
        exit(0);
    }

    mat = createMatrix();

    cout << "Rows : " << this->rows << endl;
    for (int i = 0; i < this->rows; ++i)
    {
        getline(matFile, firstLine);
        istringstream sStream(firstLine);

        for (int j = 0; j < this->cols; ++j)
        {
            sStream >> mat[i][j];
            std::cout << "mat[" << i << "][" << j << "] = " << mat[i][j] << std::endl;
        }
    }
}

void Matrix::outputToFile(string filename)
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Error opening the matrix file!" << endl;
        exit(0);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file << mat[i][j] << endl;
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
Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) // Member initializer list (the part after ':') initializes the data members of the new object
{
    mat = new long double *[rows];
    for (int i = 0; i < rows; ++i)
    {
        mat[i] = new long double[cols];
        copy(other.mat[i], other.mat[i] + cols, mat[i]); // Copying complete ith row (ith row till (i+cols)th column) of 'other' matrix to ith row of mat
        // copy(begin, end, copy_to)
    }
}

// Assignment operator overloading
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other) // Avoiding assigning same object to itself which will create errors after de-allocating memory
    {
        if (mat != nullptr)
        {
            // De-allocating memory for the current object as it is to be filled with new values of the 'other' object
            for (int i = 0; i < this->rows; i++)
            {
                delete[] this->mat[i];
            }
            delete[] this->mat;
            mat = nullptr;
        }

        // Creating new object
        rows = other.rows;
        cols = other.cols;

        mat = new long double *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new long double[cols];
            copy(other.mat[i], other.mat[i] + cols, mat[i]);
        }
    }
    return *this; // Returning a reference to the current object, i.e. the values of the current object (*this has the address of the current object)
}

Matrix::~Matrix()
{
    if (mat != nullptr)
    {
        for (int i = 0; i < this->rows; i++)
        {
            delete[] this->mat[i]; // De-allocating the memory held by row pointers first
        }
        delete[] this->mat; // Then de-allocating the memory held by the double pointer
        mat = nullptr;
    }
}