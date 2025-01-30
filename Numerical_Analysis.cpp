#include "Numerical_Analysis.hpp"

void Numerical_Analysis::roots()
{
    RootFinding findRoot;

    findRoot.BisectionMethod();
    findRoot.NewtonRaphsonMethod();
    findRoot.FixedPoint();
}

void Numerical_Analysis::complex()
{
    ComplexNumbers complexNum1, complexNum2, addResult, mulResult, conjugateRes;
    complexNum1.ComplexNumFormat();
    complexNum1.complexInput();
    complexNum2.complexInput();

    addResult = complexNum1.add(complexNum2);
    addResult.displayComplex("Addition");

    mulResult = complexNum1.multiply(complexNum2);
    mulResult.displayComplex("Multiplication");

    conjugateRes = complexNum1.complexConjugate();
    conjugateRes.displayComplex("Conjugate");

    double normResult = complexNum1.norm();
    cout << "\nNorm : " << normResult << "\n\n";
}