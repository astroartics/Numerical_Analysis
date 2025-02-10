#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix matr;
    matr.rows = 3;
    matr.cols = 3;
    for (int i = 0; i < matr.rows; ++i)
    {
        for (int j = 0; j < matr.cols; ++j)
        {
            matr.mat[i][j] = i + j;
        }
    }
    matr.displayMat();
}