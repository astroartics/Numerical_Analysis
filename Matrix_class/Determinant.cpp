#include "Matrix.hpp"

using namespace std;

int Matrix::determinant(long double **mat, int n)
{
    int det = 0;
    long double **temp = new long double *[rows];
    for (int i = 0; i < rows; i++)
    {
        temp[i] = new long double[cols];
    }

    if (n == 1) // If minors for all elements have been found, return the last element
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

        det += (pow(-1, x) * mat[0][x] * determinant(temp, n - 1));
    }
    return det;
}