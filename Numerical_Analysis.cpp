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
    ComplexNumbers complexNum1, complexNum2, addResult, subResult, mulResult, divResult, conjugateRes;
    complexNum1.ComplexNumFormat();
    complexNum1.complexInput();
    complexNum2.complexInput();

    int operation;
    cout << "\n1) Add\n2) Subtract\n3) Multiply\n4) Division\n5) Complex Conjugate\n6) Norm\n\nChoose an option : ";
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
        subResult = complexNum1.subtract(complexNum2);
        subResult.displayComplex("Subtraction");
        break;
    }

    case 3:
    {
        mulResult = complexNum1.multiply(complexNum2);
        mulResult.displayComplex("Multiplication");
        break;
    }

    case 4:
    {
        divResult = complexNum1.division(complexNum2);
        divResult.displayComplex("Division");
        break;
    }

    case 5:
    {
        int num;
        cout << "\nComplex conjugate of number 1 or 2 : ";
        cin >> num;
        conjugateRes = num == 1 ? complexNum1.complexConjugate() : complexNum2.complexConjugate();
        conjugateRes.displayComplex("Conjugate");
        break;
    }

    case 6:
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