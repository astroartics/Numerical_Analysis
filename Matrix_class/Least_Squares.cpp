#include "Matrix.hpp"

using namespace std;

long double Matrix::leastSquaresLine(Matrix fi)
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
    result.displayMat();

    return 0;
}