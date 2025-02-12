#include "Matrix.hpp"

using namespace std;

int main()
{
    // Default constructor
    Matrix defMat;
    cout << "Enter the number of rows and columns for the matrix : ";
    cin >> defMat.rows;
    cin >> defMat.cols;
    defMat.createMatrix();
    for (int i = 0; i < defMat.rows; ++i)
    {
        for (int j = 0; j < defMat.cols; ++j)
        {
            defMat.mat[i][j] = i + j;
        }
    }
    // defMat.displayMat();

    // Parameterized constructor with rows and cols as parameters
    int r, c;
    cout << "Enter the number of rows and columns for the matrix : ";
    cin >> r;
    cin >> c;
    Matrix pMat(r, c);
    for (int i = 0; i < pMat.rows; ++i)
    {
        for (int j = 0; j < pMat.cols; ++j)
        {
            pMat.mat[i][j] = i + j;
        }
    }
    // pMat.displayMat();

    // Parameterized constructor with just filename as parameter
    Matrix fMat("Matrix.txt");
    // fMat.displayMat();

    cout << "Addition : \n";
    Matrix result = defMat.add(pMat);
    result.displayMat();

    cout << "Subtraction : \n";
    result = defMat.subtract(pMat);
    result.displayMat();

    // isIdentity
    Matrix identity(3, 3);
    for (int i = 0; i < identity.rows; ++i)
    {
        for (int j = 0; j < identity.cols; ++j)
        {
            i == j ? identity.mat[i][j] = 1 : identity.mat[i][j] = 0;
        }
    }
    identity.displayMat();
    cout << identity.isIdentity() << endl;

    // isSymmetric
    double **sym = new double *[3];
    for (int i = 0; i < 3; i++)
    {
        sym[i] = new double[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            i != j ? (sym[i][j] = sym[j][i] = j + 1) : sym[i][j] = 4;
        }
    }
    Matrix symmetric(sym, 3, 3);
    symmetric.displayMat();
    cout << symmetric.isSymmetric() << endl;

    // Multiply
    cout << "Multiplication : " << endl;
    result = defMat.multiply(symmetric);
    result.displayMat();

    cout << "Multiplication using operator : " << endl;
    result = defMat * symmetric;
    result.displayMat();
}