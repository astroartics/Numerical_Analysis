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
    Matrix(int r, int c);
    Matrix(std::string filename);
    double **createMatrix();
    void displayMat();
    ~Matrix();
};