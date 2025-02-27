#include "Matrix.hpp"

using namespace std;

int main()
{
    int n = 3;

    // double tempMat[4][5] = {{4, 8, 4, 0, 8}, {1, 5, 4, -3, -4}, {1, 4, 7, 2, 10}, {1, 3, 0, -2, -4}};
    double tempMat[3][4] = {{1, 0, 1, 5}, {2, 0, 4, -1}, {0, 3, 1, 2}};
    double **matrix = new double *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n + 1];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            matrix[i][j] = tempMat[i][j];
        }
    }

    Matrix mat(matrix, n, n + 1);
    double *result = mat.GaussianElimination(n);
    for (int i = 0; i < n; i++)
    {
        cout << "x" << (i + 1) << " : " << result[i] << endl;
    }

    n = 2;
    Matrix AMat(2, 2);
    double tempA[2][2] = {{2, 5}, {1, 2}};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            AMat.mat[i][j] = tempA[i][j];
        }
    }
    Matrix L(n, n), U(n, n);
    AMat.CroutsMethod(L, U, n);
    AMat.DooLittlesMethod(L, U, n);
    L.displayMat();
    U.displayMat();
}

/*
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
    defMat.displayMat();

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
            pMat.mat[i][j] = i - j;
        }
    }
    pMat.displayMat();

    // Parameterized constructor with just filename as parameter
    Matrix fMat("Matrix.txt");
    fMat.displayMat();

    cout << "Addition : \n";
    Matrix result = defMat.add(pMat);
    result.displayMat();

    cout << "Addition using operator : \n";
    result = defMat + pMat;
    result.displayMat();

    cout << "Subtraction : \n";
    result = defMat.subtract(pMat);
    result.displayMat();

    cout << "Subtraction using operator : \n";
    result = defMat - pMat;
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

    Matrix mat(m, n);
    for (int i = 0; i < mat.rows; ++i)
    {
        for (int j = 0; j < mat.cols; ++j)
        {
            mat.mat[i][j] = i + j;
        }
    }

    Matrix transpose = mat.transpose();
    transpose.displayMat();
*/