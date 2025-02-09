#include <cmath>
#include <bits/stdc++.h>
#include <string>
#include <fstream>

class Matrix
{
public:
    int rows, cols;
    double **mat;

    Matrix(int r, int c);
    Matrix();
    Matrix(std::string filename);
    ~Matrix();
};