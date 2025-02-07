#include "RootFinding.hpp"
#include "ComplexNumbers.hpp"

int main()
{
    RootFinding roots;
    double result, startingPoint, x;
    int lb, ub, printItr;

    roots.acceptCoefficients();
    cout << "Enter the value of 'x' for evaluating the polynomial using Horner's rule: ";
    cin >> x;
    cout << "Value of polynomial : " << roots.HornersRule(x) << "\n\n";

    cout << "Enter lowerbound and upperbound for an interval : ";
    cin >> lb;
    cin >> ub;

    cout << "Do you want to print the iterations (0 for No/ 1 for Yes) : ";
    cin >> printItr;

    result = roots.BisectionMethod(lb, ub, printItr);
    cout << "The value of root using Bisection Method : " << result << endl;

    cout << "\n\nProvide a starting point (x0) for finding the root : ";
    cin >> startingPoint;
    result = roots.NewtonRaphsonMethod(startingPoint, printItr);
    cout << "The value of root using Newton-Raphson Method : " << result << endl;

    result = roots.FixedPoint(printItr);
    cout << "Value of root using Fixed Point Iteration Method : " << result << endl;

    return 0;
}

/*
Complex class main code

    ComplexNumbers complexNum1, complexNum2, result;
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
        result = complexNum1.add(complexNum2);
        result.displayComplex("Addition");
        break;
    }

    case 2:
    {
        result = complexNum1.subtract(complexNum2);
        result.displayComplex("Subtraction");
        break;
    }

    case 3:
    {
        result = complexNum1.multiply(complexNum2);
        result.displayComplex("Multiplication");
        break;
    }

    case 4:
    {
        result = complexNum1.division(complexNum2);
        result.displayComplex("Division");
        break;
    }

    case 5:
    {
        int num;
        cout << "\nComplex conjugate of number 1 or 2 : ";
        cin >> num;
        result = (num == 1 ? complexNum1.complexConjugate() : complexNum2.complexConjugate());
        result.displayComplex("Conjugate");
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

    return 0;
 */