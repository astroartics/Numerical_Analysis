#include "Matrix.hpp"

class Interpolation
{
public:
    Matrix m, yi;
    long double RMS;

    Interpolation(std::string filename)
    {
        Matrix temp(filename);
        m = temp;
        RMS = 0.0;
        yi.rows = 1;
        yi.cols = m.cols;
        yi.createMatrix();
    }

    void residualSumSquares(Matrix, Matrix);
    Matrix leastSquaresLine(Matrix);
    Matrix leastSquaresParabola(Matrix);

    long double LagrangesInterpolation(long double, Matrix);
};