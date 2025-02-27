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
            if (i != j)
            {
                sum = 0;
                for (int k = 0; k < i; k++)
                {
                    sum += L.mat[i][k] * U.mat[k][j];
                }
                if (L.mat[i][i] == 0)
                {
                    cout << "Zero in denominator!" << endl;
                    exit(0);
                }
                U.mat[i][j] = (this->mat[i][j] - sum) / L.mat[i][i];
            }
        }
    }
}

void Matrix::DooLittlesMethod(Matrix &L, Matrix &U, int n)
{
    for (int i = 0; i < n; i++)
    {
        L.mat[i][i] = 1; // Unit lower triangular matrix
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.mat[i][k] * U.mat[k][j];
            }
            U.mat[i][j] = this->mat[i][j] - sum;
        }

        for (int j = i; j < n; j++)
        {
            if (i != j)
            {
                sum = 0;
                for (int k = 0; k < i; k++)
                {
                    sum += L.mat[j][k] * U.mat[k][i];
                }
                if (U.mat[i][i] == 0)
                {
                    cout << "Zero in denominator!" << endl;
                    exit(0);
                }
                L.mat[j][i] = (this->mat[j][i] - sum) / U.mat[i][i];
            }
        }
    }
}