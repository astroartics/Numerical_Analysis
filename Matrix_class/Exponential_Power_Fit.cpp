#include "Interpolation.hpp"

using namespace std;

Matrix Interpolation::exponentialFit(Matrix fi)
{
    ofstream ax_b_mat("ax_b_mat.txt");
    if (!ax_b_mat)
    {
        cout << "Error opening the file!" << endl;
        exit(0);
    }

    ax_b_mat << 2 << " " << 3 << endl;

    long double xi_sum = 0, zi_lny_sum = 0.0, xi_sq_sum = 0, xi_zi_sum = 0;
    for (int i = 0; i < m.cols; i++)
    {
        xi_sum += m.mat[0][i];
        zi_lny_sum += log(fi.mat[0][i]);
        xi_sq_sum += (m.mat[0][i] * m.mat[0][i]);
        xi_zi_sum += (log(fi.mat[0][i]) * m.mat[0][i]);
    }

    // cout << xi_sq_sum << " ";
    // cout << xi_sum << " ";
    // cout << xi_zi_sum << endl;
    // cout << xi_sum << " ";
    // cout << m.cols << " ";
    // cout << fi_sum << endl;

    ax_b_mat << xi_sq_sum << " ";
    ax_b_mat << xi_sum << " ";
    ax_b_mat << xi_zi_sum << endl;
    ax_b_mat << xi_sum << " ";
    ax_b_mat << m.cols << " ";
    ax_b_mat << zi_lny_sum << endl;

    Matrix eqn("ax_b_mat.txt");
    Matrix result = eqn.GaussianElimination();
    long double c = pow(M_E, result.mat[0][1]);

    Matrix y(1, m.cols);
    for (int i = 0; i < m.cols; i++)
    {
        y.mat[0][i] = (c * pow(M_E, (result.mat[0][0] * m.mat[0][i])));
    }

    yi = y;

    residualSumSquares(fi, y);

    return result;
}

Matrix Interpolation::powerFit(Matrix fi)
{
    ofstream ax_b_mat("ax_b_mat.txt");
    if (!ax_b_mat)
    {
        cout << "Error opening the file!" << endl;
        exit(0);
    }

    ax_b_mat << 2 << " " << 3 << endl;

    long double xi_sum = 0, zi_lny_sum = 0.0, xi_sq_sum = 0, xi_zi_sum = 0;
    for (int i = 0; i < m.cols; i++)
    {
        xi_sum += m.mat[0][i];
        zi_lny_sum += log(fi.mat[0][i]);
        xi_sq_sum += (m.mat[0][i] * m.mat[0][i]);
        xi_zi_sum += (log(fi.mat[0][i]) * m.mat[0][i]);
    }

    // cout << xi_sq_sum << " ";
    // cout << xi_sum << " ";
    // cout << xi_zi_sum << endl;
    // cout << xi_sum << " ";
    // cout << m.cols << " ";
    // cout << fi_sum << endl;

    ax_b_mat << xi_sq_sum << " ";
    ax_b_mat << xi_sum << " ";
    ax_b_mat << xi_zi_sum << endl;
    ax_b_mat << xi_sum << " ";
    ax_b_mat << m.cols << " ";
    ax_b_mat << zi_lny_sum << endl;

    Matrix eqn("ax_b_mat.txt");
    Matrix result = eqn.GaussianElimination();
    long double c = pow(M_E, result.mat[0][1]);

    Matrix y(1, m.cols);
    for (int i = 0; i < m.cols; i++)
    {
        y.mat[0][i] = (c * pow(M_E, (result.mat[0][0] * m.mat[0][i])));
    }

    yi = y;

    residualSumSquares(fi, y);

    return result;
}