#include "RootFinding.hpp"

int main()
{
    RootFinding roots;
    double result, tol;
    int lb, ub, printItr;

    cout << "Do you want to print the iterations (0 for No/ 1 for Yes) : ";
    cin >> printItr;

    // cout << "Enter the value for positive power (t) for tolerance (10^(-t)) : ";
    // cin >> tol;
    // roots.setTolerance(tol);

    cout << "\nEnter lowerbound and upperbound for an interval : ";
    cin >> lb;
    cin >> ub;
    // result = roots.BisectionMethod(lb, ub, printItr);
    vector<double> res = roots.BisectionMethod(lb, ub, printItr);
    // cout << "The value of root using Bisection Method : " << result << endl;
    for (auto e : res)
        cout << e << " ";

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