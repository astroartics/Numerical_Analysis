#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix m;
    int r, c;

    // cout << "Enter the number of rows and columns for the matrix : ";
    // cin >> r;
    // cin >> c;
    // Matrix matrix(r, c);
    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
        {
            m.mat[i][j] = i + j;
        }
    }
    m.displayMat();
}