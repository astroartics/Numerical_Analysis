#include <bits/stdc++.h>
#include <fstream>
#include <vector>

class Matrix
{
public:
    long int rows, cols;
    long double **mat;

    Matrix();
    Matrix(int, int);
    Matrix(long double **, int, int);
    Matrix(std::string);
    void outputToFile(std::string);
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
    int makeDiagonallyDominant(int);

    Matrix transpose();

    void basicPivoting(int);
    void upperTriangular();
    Matrix backSubstitution();
    Matrix GaussianElimination();

    int CroutsMethod(Matrix &, Matrix &);
    int DooLittlesMethod(Matrix &, Matrix &);
    int CholeskiMethod(Matrix &);

    double determinant(long double **, int);
    void lowerTriangular();
    double det(long double **);
    int adjoint(long double **, int);

    double vectorDistance(Matrix &, Matrix &, int);
    Matrix GaussJacobiMethod(int, Matrix);
    Matrix GaussSeidelMethod(int, Matrix);

    long double leastSquaresLine(Matrix);
};