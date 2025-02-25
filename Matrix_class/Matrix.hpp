#include <bits/stdc++.h>
#include <fstream>

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

    Matrix transpose();

    void basicPivoting(int, int);
    void upperTriangular(int);
    void backSubstitution(int);
    double *GaussianElimination(int);
};