#include "Matrix.hpp"

using namespace std;

void Matrix::CroutsMethod(Matrix &L, Matrix &U, int n)
{
    for (int i = 0; i < n; i++)
    {
        U.mat[i][i] = 1; // Unit upper triangular matrix
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.mat[j][k] * U.mat[k][i];
            }
            L.mat[j][i] = this->mat[j][i] - sum;
        }

        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.mat[i][k] * U.mat[k][j];
            }
            if (L.mat[i][i] == 0)
            {
                cout << "Determinant of L is zero." << endl;
                exit(0);
            }
            U.mat[i][j] = (this->mat[i][j] - sum) / L.mat[i][i];
        }
    }

    L.displayMat();
    U.displayMat();
}

void Matrix::DooLittlesMethod(Matrix &L, Matrix &U, int n)
{
    for (int i = 0; i < n; i++)
    {
        L.mat[i][i] = 1; // Unit upper triangular matrix
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += U.mat[j][k] * L.mat[k][i];
            }
            U.mat[j][i] = this->mat[j][i] - sum;
        }

        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += U.mat[i][k] * L.mat[k][j];
            }
            if (U.mat[i][i] == 0)
            {
                cout << "Determinant of L is zero." << endl;
                exit(0);
            }
            L.mat[i][j] = (this->mat[i][j] - sum) / U.mat[i][i];
        }
    }

    L.displayMat();
    U.displayMat();
}