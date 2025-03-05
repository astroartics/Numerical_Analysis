#include "Matrix.hpp"

using namespace std;

void Matrix::determinant(int n)
{
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (k != i && l != j)
                    {
                        cout << mat[k][l] << " ";
                    }
                }
                if (k != i)
                    cout << endl;
            }
            cout << "\n\n";
        }
    }
}