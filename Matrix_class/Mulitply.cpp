#include "Matrix.hpp"

using namespace std;

Matrix Matrix::multiply(Matrix B)
{
    if (this->cols == B.rows)
    {
        Matrix result(this->rows, B.cols);
        
    }
}