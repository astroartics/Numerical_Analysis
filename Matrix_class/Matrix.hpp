#include <cmath>
#include <bits/stdc++.h>
#include <string>
#include <fstream>

class Matrix
{
public:
    int rows, cols;
    double **mat;

    Matrix();
    Matrix(int, int);
    Matrix(std::string);
    Matrix(const Matrix &);
    double **createMatrix();
    void displayMat();
    ~Matrix();

    Matrix add(Matrix);
};