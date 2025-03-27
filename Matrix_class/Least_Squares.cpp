#include "Matrix.hpp"

using namespace std;

long double Matrix::residualSumSquares(Matrix fi, Matrix yi)
{
    long double fi_yi_sq = 0;

    for (int i = 0; i < cols; i++)
    {
        fi_yi_sq += pow((fi.mat[0][i] - yi.mat[0][i]), 2);
    }

    long double rms = sqrt(fi_yi_sq / cols);

    return rms;
}

Matrix Matrix::leastSquaresLine(Matrix fi)
{
    ofstream ax_b_mat("ax_b_mat.txt");
    if (!ax_b_mat)
    {
        cout << "Error opening the file!" << endl;
        exit(0);
    }

    ax_b_mat << 2 << " " << 3 << endl;

    long double xi_sum = 0, fi_sum = 0, xi_sq_sum = 0, fi_xi_sum = 0;
    for (int i = 0; i < cols; i++)
    {
        xi_sum += mat[0][i];
        fi_sum += fi.mat[0][i];
        xi_sq_sum += (mat[0][i] * mat[0][i]);
        fi_xi_sum += (fi.mat[0][i] * mat[0][i]);
    }

    ax_b_mat << xi_sq_sum << " ";
    ax_b_mat << xi_sum << " ";
    ax_b_mat << fi_xi_sum << endl;
    ax_b_mat << xi_sum << " ";
    ax_b_mat << cols << " ";
    ax_b_mat << fi_sum << endl;

    Matrix eqn("ax_b_mat.txt");
    Matrix result = eqn.GaussianElimination();

    Matrix yi(1, cols);
    for (int i = 0; i < cols; i++)
    {
        yi.mat[0][i] = (result.mat[0][0] * mat[0][i]) + result.mat[0][1];
    }

    residualSumSquares(fi, yi);

    return result;
}

Matrix Matrix::leastSquaresParabola(Matrix fi)
{
    ofstream ax_b_mat("ax_b_mat.txt");
    if (!ax_b_mat)
    {
        cout << "Error opening the file!" << endl;
        exit(0);
    }

    ax_b_mat << 3 << " " << 4 << endl;

    long double xi_sum = 0, fi_sum = 0, xi_2_sum = 0, xi_3_sum = 0, xi_4_sum = 0, fi_xi_sum = 0, fi_xi_2_sum = 0;
    for (int i = 0; i < cols; i++)
    {
        xi_sum += mat[0][i];
        fi_sum += fi.mat[0][i];
        xi_2_sum += pow(mat[0][i], 2);
        xi_3_sum += pow(mat[0][i], 3);
        xi_4_sum += pow(mat[0][i], 4);
        fi_xi_sum += (fi.mat[0][i] * mat[0][i]);
        fi_xi_2_sum += (fi.mat[0][i] * pow(mat[0][i], 2));
    }

    ax_b_mat << xi_4_sum << " ";
    ax_b_mat << xi_3_sum << " ";
    ax_b_mat << xi_2_sum << " ";
    ax_b_mat << fi_xi_2_sum << endl;
    ax_b_mat << xi_3_sum << " ";
    ax_b_mat << xi_2_sum << " ";
    ax_b_mat << xi_sum << " ";
    ax_b_mat << fi_xi_sum << endl;
    ax_b_mat << xi_2_sum << " ";
    ax_b_mat << xi_sum << " ";
    ax_b_mat << cols << " ";
    ax_b_mat << fi_sum << endl;

    Matrix eqn("ax_b_mat.txt");
    Matrix result = eqn.GaussianElimination();

    Matrix yi(1, cols);
    for (int i = 0; i < cols; i++)
    {
        yi.mat[0][i] = (result.mat[0][0] * pow(mat[0][i], 2)) + (result.mat[0][1] * mat[0][i]) + result.mat[0][2];
    }

    residualSumSquares(fi, yi);

    return result;
}