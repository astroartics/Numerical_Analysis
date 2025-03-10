#include "Matrix.hpp"

using namespace std;

int Matrix::determinant(double **mat, int n)
{
    int det = 0;
    double **temp = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        temp[i] = new double[cols];
    }

    if (n == 1) 
        return mat[0][0];

    for (int x = 0; x < cols; x++) // For covering the first row
    {
        int p = 0;
        // 'i and j for loops' are for getting the minor of the current element
        for (int i = 1; i < rows; i++) // Will start from the next row of the current element so as to avoid the current row
        {
            int q = 0;
            for (int j = 0; j < cols; j++)
            {
                if (j == x) // Will avoid the elements of the current column
                    continue;

                temp[p][q] = mat[i][j]; // Storing the minor in temp
                q++;
            }
            p++;
        }

        determinant(temp, n - 1);
    }
    return det;
}