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

    int operation;
    cout << "\n1) Add\n2) Multiply\n3) Complex Conjugate\n4) Norm\n\nChoose an option : ";
    cin >> operation;

    switch (operation)
    {
    case 1:
    {
        addResult = complexNum1.add(complexNum2);
        addResult.displayComplex("Addition");
        break;
    }

    case 2:
    {
        mulResult = complexNum1.multiply(complexNum2);
        mulResult.displayComplex("Multiplication");
        break;
    }

    case 3:
    {
        conjugateRes = complexNum1.complexConjugate();
        conjugateRes.displayComplex("Conjugate");
        break;
    }

    case 4:
    {
        double normResult = complexNum1.norm();
        cout << "\nNorm : " << normResult << "\n\n";
        break;
    }

    default:
    {
        "\nInvalid option!\n";
        break;
    }
    }
}