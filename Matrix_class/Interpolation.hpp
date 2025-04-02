#include "Matrix.hpp"

class Interpolation
{
public:
    Matrix m;

    Interpolation(std::string filename)
    {
        Matrix temp(filename);
        m = temp;
    }

    long double residualSumSquares(Matrix, Matrix);
    Matrix leastSquaresLine(Matrix);
    Matrix leastSquaresParabola(Matrix);
};