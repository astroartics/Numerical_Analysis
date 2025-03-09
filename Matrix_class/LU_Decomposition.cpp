#include "Matrix.hpp"

using namespace std;

int Matrix::CroutsMethod(Matrix &L, Matrix &U)
{
    // Row first
    // A = L * U (where diagonal elements of U are 1)
    for (int i = 0; i < rows; i++)
    {
        U.mat[i][i] = 1; // Unit upper triangular matrix
    }

    double sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < cols; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.mat[j][k] * U.mat[k][i];
            }
            L.mat[j][i] = this->mat[j][i] - sum; // L[j][i] = A[j][i] -  ∑ (L[j][k] * U[k][i]
        }

        for (int j = i; j < cols; j++)
        {
            if (i < j)
            {
                sum = 0;
                for (int k = 0; k < i; k++)
                {
                    sum += L.mat[i][k] * U.mat[k][j];
                }
                if (L.mat[i][i] == 0)
                {
                    cout << "Zero in denominator!" << endl;
                    return -1;
                }
                U.mat[i][j] = (this->mat[i][j] - sum) / L.mat[i][i]; // (U[i][j] = A[i][j] -  ∑ (L[i][k] * U[k][j]) / L[i][i]
            }
        }
    }

    return 1;
}

int Matrix::DooLittlesMethod(Matrix &L, Matrix &U)
{
    // Column first
    // A = L * U (where diagonal elements of L are 1)
    for (int i = 0; i < rows; i++)
    {
        L.mat[i][i] = 1; // Unit lower triangular matrix
    }

    double sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < cols; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.mat[i][k] * U.mat[k][j];
            }
            U.mat[i][j] = this->mat[i][j] - sum; // U[i][j] = A[i][j] -  ∑ (L[i][k] * U[k][j]
        }

        for (int j = i; j < rows; j++)
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
                    return -1;
                }
                L.mat[j][i] = (this->mat[j][i] - sum) / U.mat[i][i]; // (L[j][i] = A[j][i] -  ∑ (L[j][k] * U[k][i]) / U[i][i]
            }
        }
    }
    return 1;
}

int Matrix::CholeskiMethod(Matrix &L)
{
    // A = L * L(transpose)
    if ((*this).isSymmetric())
    {
        double sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j) // Diagonal elements
                {
                    sum = 0;
                    for (int k = 0; k < j; k++)
                    {
                        sum += L.mat[i][k] * L.mat[i][k];
                    }
                    L.mat[j][j] = sqrt(this->mat[j][j] - sum); // L[j][j] = (A[j][j] -  ∑ L[i][k]*L[i][k])^(1/2)
                }
                else
                {
                    if (i > j)
                    {
                        sum = 0;
                        for (int k = 0; k < j; k++)
                        {
                            sum += L.mat[i][k] * L.mat[j][k];
                        }
                        if (L.mat[j][j] == 0)
                        {
                            cout << "Zero in denominator!" << endl;
                            return -1;
                        }
                        L.mat[i][j] = (this->mat[i][j] - sum) / L.mat[j][j]; // L[i][j] = ((A[i][j] -  ∑ L[i][k]*L[j][k])^(1/2)) / L[j][j]
                    }
                }
            }
        }
    }
    else
    {
        cout << "Matrix is not symmetric" << endl;
        exit(0);
    }
    return 1;
}
