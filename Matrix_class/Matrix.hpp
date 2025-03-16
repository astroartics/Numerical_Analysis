#include <bits/stdc++.h>
#include <fstream>
#include <vector>

class Matrix
{
public:
    int rows, cols;
    long double **mat;

    Matrix();
    Matrix(int, int);
    Matrix(long double **, int, int);
    Matrix(std::string);
    Matrix(const Matrix &);
    Matrix &operator=(const Matrix &);
    long double **createMatrix();
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
    Matrix backSubstitution();
    void upperTriangularMat();
    Matrix GaussianElimination();

    int CroutsMethod(Matrix &, Matrix &);
    int DooLittlesMethod(Matrix &, Matrix &);
    int CholeskiMethod(Matrix &);

    int determinant(long double **, int);
    int adjoint(long double **, int);
};