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
    ComplexNumbers complexNum1, complexNum2, addResult, subResult, mulResult, conjugateRes;
    complexNum1.ComplexNumFormat();
    complexNum1.complexInput();
    complexNum2.complexInput();

    int operation;
    cout << "\n1) Add\n2) Multiply\n3) Subtract\n4) Complex Conjugate\n4) Norm\n\nChoose an option : ";
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
        subResult = complexNum1.subtract(complexNum2);
        subResult.displayComplex("Subtraction");
        break;

    case 4:
    {
        int num;
        cout << "\nComplex conjugate of number 1 or 2 : ";
        cin >> num;
        conjugateRes = num == 1 ? complexNum1.complexConjugate() : complexNum2.complexConjugate();
        conjugateRes.displayComplex("Conjugate");
        break;
    }

    case 5:
    {
        double normResult = complexNum1.norm();
        cout << "\n\033[32mNorm : " << normResult << "\033[0m\n\n";
        break;
    }

    default:
    {
        cout << "\nInvalid option!\n";
        break;
    }
    }
}