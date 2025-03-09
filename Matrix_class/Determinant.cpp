#include "Matrix.hpp"

using namespace std;

int Matrix::determinant(vector<double> temp, int m, int n, int det)
{
    if (temp.size() == 1)
    {
        return temp[0];
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i != m && j != n)
                {
                    temp.push_back(mat[i][j]);
                }
            }
        }

        for (int i = 0; i < temp.size(); i++)
            cout << "Temp : " << temp[i] << endl;

        det += (pow(-1, n) * mat[m][n] * determinant(temp, m, n + 1, det));
    }

    return det;
}