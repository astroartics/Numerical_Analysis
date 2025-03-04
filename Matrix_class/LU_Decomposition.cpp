#include "Matrix.hpp"

using namespace std;

int Matrix::CroutsMethod(Matrix &L, Matrix &U, int n)
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
                    return -1;
                }
                U.mat[i][j] = (this->mat[i][j] - sum) / L.mat[i][i];
            }
        }
    }
    return 1;
}

int Matrix::DooLittlesMethod(Matrix &L, Matrix &U, int n)
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
                    return -1;
                }
                L.mat[j][i] = (this->mat[j][i] - sum) / U.mat[i][i];
            }
        }
    }
    return 1;
}

int Matrix::CholeskiMethod(Matrix &L, int n)
{
    if ((*this).isSymmetric())
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
                {
                    sum = 0;
                    for (int k = 0; k < j; k++)
                    {
                        sum += L.mat[i][k] * L.mat[i][k];
                    }
                    L.mat[j][j] = sqrt(this->mat[j][j] - sum);
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
                        L.mat[i][j] = (this->mat[i][j] - sum) / L.mat[j][j];
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
