#include "Matrix.hpp"

using namespace std;

void Matrix::determinant(int n)
{
    int sum = 0;
    int M = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            sum += (mat[i][j] * M);
        }
    }
}