#include <cmath>
#include <bits/stdc++.h>
#include <string>
#include <fstream>

class Matrix
{
public:
    int rows, cols;
    double **mat;

    Matrix(int, int);
    Matrix();
    Matrix(std::string filename);
    ~Matrix();
};