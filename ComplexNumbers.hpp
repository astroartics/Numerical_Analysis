#include <cmath>
#include <bits/stdc++.h> // Use to include all the standard libraries

using namespace std;

class ComplexNumbers
{
public:
    double real, imaginary;
    int operation;

    ComplexNumbers()
    {
        real = 0.0;
        imaginary = 0.0;
        operation = 1;
    }

    void ComplexNumFormat()
    {
        cout << "\nFormat of Complex numbers : a + bi (a-Real part, b-imaginary part)\n";
    }

    ComplexNumbers complexInput();
    void displayComplex(string resultType);
    ComplexNumbers add(ComplexNumbers y);
    ComplexNumbers multiply(ComplexNumbers y);
    ComplexNumbers complexConjugate();
    double norm();
};