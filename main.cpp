#include "RootFinding.hpp"
#include "ComplexNumbers.hpp"

int main()
{
    // RootFinding bisection, newtonRaphson;

    // bisection.BisectionMethod();
    // newtonRaphson.NewtonRaphsonMethod();

    ComplexNumbers complexNum1, complexNum2, addResult, mulResult, conjugateRes;
    complexNum1.ComplexNumFormat();
    complexNum1.complexInput();
    complexNum2.complexInput();

    addResult = complexNum1.add(complexNum2);
    cout << "\nResult : " << addResult.real << " + " << addResult.imaginary << "i\n";

    mulResult = complexNum1.multiply(complexNum2);
    cout << "\nResult : " << mulResult.real << " + " << mulResult.imaginary << "i\n";

    conjugateRes = complexNum1.complexConjugate();
    cout << "\nResult : " << conjugateRes.real << (conjugateRes.imaginary > 0 ? " + " : "") << conjugateRes.imaginary << "i\n";

    double normResult = complexNum1.norm();
    cout << "\nResult : " << normResult << "\n\n";

    return 0;
}