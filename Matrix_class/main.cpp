#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix DMat("GaussMatrix.txt");
    DMat.displayMat();
    double *ans = DMat.GaussianElimination();
    for (int i = 0; i < DMat.rows; i++)
    {
        cout << "x" << (i + 1) << " : " << ans[i] << endl;
    }
    Matrix upperT = DMat.upperTriangularMat();
    upperT.displayMat();

    // LU Decomposition
    Matrix AMat("LUMatrix.txt");
    cout << endl;
    Matrix L(AMat.rows, AMat.rows), U(AMat.rows, AMat.rows);
    if (AMat.CroutsMethod(L, U, 2) != -1)
    {
        L.displayMat();
        U.displayMat();
    }
    if (AMat.DooLittlesMethod(L, U, 2) != -1)
    {
        L.displayMat();
        U.displayMat();
    }

    // n = 3;
    // Matrix BMat(n, n), L2(n, n);
    // double tempB[3][3] = {{6, 15, 55}, {15, 55, 225}, {55, 225, 979}};

    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         BMat.mat[i][j] = tempB[i][j];
    //     }
    // }
    // cout << endl;
    // if (BMat.CholeskiMethod(L2, n) != -1)
    // {
    //     L2.displayMat();
    //     L2 = L2.transpose();
    //     L2.displayMat();
    // }

    // n = 4;
    // double tempD[4][5] = {{10, 7, 8, 7, 32}, {7, 5, 6, 5, 23}, {8, 6, 10, 9, 33}, {7, 5, 9, 10, 31}};
    // double tempD[4][5] = {{10, 7, 8.1, 7.2, 32}, {7.08, 5.04, 6, 5, 23}, {8, 5.98, 9.89, 9, 33}, {6.99, 4.99, 9, 9.92, 31}};
    // double tempD[4][5] = {{10, 7, 8, 7, 32.1}, {7, 5, 6, 5, 22.9}, {8, 6, 10, 9, 33.1}, {7, 5, 9, 10, 30.9}};
    // double **matb = new double *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     matb[i] = new double[n + 1];
    // }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n + 1; ++j)
    //     {
    //         matb[i][j] = tempD[i][j];
    //     }
    // }
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