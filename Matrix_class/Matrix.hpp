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

    double vectorDistance(Matrix &, Matrix &, int);
    Matrix GaussJacobiMethod(int, Matrix);
    Matrix GaussSeidelMethod(int, Matrix);
    // double xn(double y, double z)
    // {
    //     return ((7 + y - z) / 4);
    // }
    // double yn(double x, double z)
    // {
    //     return ((-21 - (4 * x) - z) / (-8));
    // }
    // double zn(double x, double y)
    // {
    //     return ((15 + (2 * x) - y) / 5);
    // }
};