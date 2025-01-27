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
        cout << "\nFormat of Complex numbers : a + bi (a-Real part, b-imaginary part)\n";
    }

    ComplexNumbers complexInput();
    ComplexNumbers add(ComplexNumbers y);
    ComplexNumbers multiply(ComplexNumbers y);
    ComplexNumbers complexConjugate();
    double norm();
};