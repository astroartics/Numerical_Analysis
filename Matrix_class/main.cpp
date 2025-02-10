#include "Matrix.hpp"

using namespace std;

int main()
{
    // Default constructor
    Matrix defMat;
    for (int i = 0; i < defMat.rows; ++i)
    {
        for (int j = 0; j < defMat.cols; ++j)
        {
            defMat.mat[i][j] = i + j;
        }
    }
    defMat.displayMat();

    // Parameterized constructor with rows and cols as parameters
    int r, c;
    cout << "Enter the number of rows and columns for the matrix : ";
    cin >> r;
    cin >> c;
    Matrix pMat(r, c);
    for (int i = 0; i < pMat.rows; ++i)
    {
        for (int j = 0; j < pMat.cols; ++j)
        {
            pMat.mat[i][j] = i + j;
        }
    }
    pMat.displayMat();

    // Parameterized constructor with just filename as parameter
    Matrix fMat("Matrix.txt");
    fMat.displayMat();
}