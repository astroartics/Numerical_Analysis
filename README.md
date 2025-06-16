<h1 align="center"> This repository contains the libraries that we have created for the Numerical Analysis course for Jan-Apr 2025</h1>

<h3 align="center"> It contains most commonly used matrix related functions, operations on complex numbers, some root finding methods and some interpolation techniques implemented from scratch. </h3>

### Classes and methods those classes contain
- Complex class
  - Addition, subtraction, multiplication, division of complex numbers
  - Complex conjugate
  - Norm
- Root Finding Methods
  - Bisection Method
  - Newton Raphson Method
  - Fixed Point Method
- Matrix class
  - Matrix addition, subtraction, multiplication
  - Determinant
  - Transpose
  - isSymmetric, isIdentity, isDiagonallyDominant
  - LU Decomposition - Choleski, Crout's, DooLittle's
  - Gaussian Elimination
  - Gauss Jacobi and Gauss Seidel methods
- Interpolation class
  - Lagrange's interpolation
  - Chebyshev Approximation
  - Exponential fit
  - Least squares line and parabola

> Interpolation class is included inside Matrix class folder as the equations in interpolation have been solved using matrix class function - Gaussian Elimination, and the interpolation input values are being stored as a matrix using an object of the Matrix class.
