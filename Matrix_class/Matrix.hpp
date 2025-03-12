#include <bits/stdc++.h>
#include <fstream>
#include <vector>

class Matrix
{
public:
    int rows, cols;
    double **mat;

    Matrix();
    Matrix(int, int);
    Matrix(double **, int, int);
    Matrix(std::string);
    Matrix(const Matrix &);
    Matrix &operator=(const Matrix &);
    double **createMatrix();
    void displayMat();
    ~Matrix();

    Matrix add(Matrix);
    Matrix operator+(Matrix);

    Matrix subtract(Matrix);
    Matrix operator-(Matrix);

    Matrix multiply(Matrix);
    Matrix operator*(Matrix);

    bool isIdentity();
    bool isSymmetric();
    bool isDiagonallyDominant();

    Matrix transpose();

    void basicPivoting(int);
    void upperTriangular();
    double *backSubstitution();
    Matrix upperTriangularMat();
    double *GaussianElimination();

    int CroutsMethod(Matrix &, Matrix &);
    int DooLittlesMethod(Matrix &, Matrix &);
    int CholeskiMethod(Matrix &);

    int determinant(double **, int);
    int adjoint(double **, int);
};