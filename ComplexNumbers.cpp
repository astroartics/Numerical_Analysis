#include "ComplexNumbers.hpp"

ComplexNumbers ComplexNumbers::complexInput()
{
    cout << "\nEnter real part : ";
    cin >> this->real;
    cout << "Enter imaginary part : ";
    cin >> this->imaginary;

    return *this;
}

ComplexNumbers ComplexNumbers::add(ComplexNumbers y)
{
    ComplexNumbers result;
    result.real = this->real + y.real;
    result.imaginary = this->imaginary + y.imaginary;

    return result;
}

ComplexNumbers ComplexNumbers::multiply(ComplexNumbers y)
{
    // (ac - bd) + i(ad + bc)
    ComplexNumbers result;
    result.real = (this->real * y.real) - (this->imaginary * y.imaginary);
    result.imaginary = (this->real * y.imaginary) + (this->imaginary * y.real);

    return result;
}

ComplexNumbers ComplexNumbers::complexConjugate()
{
    ComplexNumbers conjugate;
    conjugate.real = this->real;
    conjugate.imaginary = -(this->imaginary);

    return conjugate;
}

double ComplexNumbers::norm()
{
    double result;
    result = sqrt((this->real * this->real) + (this->imaginary * this->imaginary));

    return result;
}