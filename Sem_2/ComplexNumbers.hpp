#include <cmath>
#include <bits/stdc++.h> // Use to include all the standard libraries

using namespace std;

class ComplexNumbers
{
public:
    double real, imaginary;

    ComplexNumbers()
    {
        real = 0.0;
        imaginary = 0.0;
    }

    void ComplexNumFormat()
    {
        cout << "\n\033[33mFormat of Complex numbers : a + bi (a-Real part, b-imaginary part)\033[0m\n";
    }

    ComplexNumbers complexInput();
    void displayComplex(string resultType);
    ComplexNumbers add(ComplexNumbers y);
    ComplexNumbers subtract(ComplexNumbers y);
    ComplexNumbers multiply(ComplexNumbers y);
    ComplexNumbers division(ComplexNumbers y);
    ComplexNumbers complexConjugate();
    double norm();
};