#include "Matrix.hpp"
#define TOL pow(10, -6)

using namespace std;

double Matrix::vectorDistance(Matrix &vect1, Matrix &vect2, int varCount)
{
    long double sum = 0.0;
    for (int i = 0; i < varCount; i++)
    {
        sum += pow((vect1.mat[0][i] - vect2.mat[0][i]), 2);
    }

    long double dist = sqrt(abs(sum));
    return dist;
}

Matrix Matrix::GaussJacobiMethod(int varCount, Matrix b)
{
    long double eqn = 0.0;
    Matrix curr(1, varCount);
    Matrix temp(1, varCount);
    Matrix prev(1, varCount);

    if (isDiagonallyDominant())
    {
        do
        {
            for (int i = 0; i < varCount; i++)
            {
                eqn = 0.0;
                for (int j = 0; j < varCount; j++)
                {
                    if (i != j)
                    {
                        eqn += (mat[i][j] * curr.mat[0][j]);
                    }
                }

                temp.mat[0][i] = ((b.mat[0][i] - eqn) / mat[i][i]);
            }

            for (int i = 0; i < varCount; i++)
            {
                prev.mat[0][i] = curr.mat[0][i];
                curr.mat[0][i] = temp.mat[0][i];
            }

        } while (vectorDistance(prev, curr, varCount) > TOL);

        // for (int i = 0; i < varCount; i++)
        // {
        //     cout << curr.mat[0][i] << " ";
        // }
        // cout << endl;
    }
    else
    {
        cout << "Matrix cannot be converted to a diagonally dominant matrix" << endl;
        exit(0);
    }
    return curr;
}

Matrix Matrix::GaussSeidelMethod(int varCount, Matrix b)
{
    long double eqn = 0.0;
    Matrix curr(1, varCount);
    Matrix temp(1, varCount);
    Matrix prev(1, varCount);

    if (isDiagonallyDominant())
    {
        do
        {
            for (int i = 0; i < varCount; i++)
            {
                eqn = 0.0;
                for (int j = 0; j < varCount; j++)
                {
                    if (i != j)
                    {
                        eqn += (mat[i][j] * curr.mat[0][j]);
                    }
                }

                prev.mat[0][i] = curr.mat[0][i];
                curr.mat[0][i] = ((b.mat[0][i] - eqn) / mat[i][i]);
            }

        } while (vectorDistance(prev, curr, varCount) > TOL);
    }
    else
    {
        cout << "Matrix cannot be converted to a diagonally dominant matrix" << endl;
        exit(0);
    }
    return curr;
}