#include "RootFinding.hpp"

void RootFinding::acceptCoefficients()
{
    int degree;
    double coeff;
    cout << "\nEnter degree of the polynomial : ";
    cin >> degree;

    for (int i = degree; i >= 0; i--)
    {
        cout << "Coefficient for x^" << i << " = ";
        cin >> coeff;
        coefficients.push_back(coeff);
    }
}
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
double RootFinding::HornersRule(double x)
{
    // double coeff[3] = {2, 0, -1};
    double result = coefficients[0];
    for (int i = 1; i < coefficients.size(); i++)
    {
        result = result * x + coefficients[i];
    }
    return result;
}
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// Bisection Method
void RootFinding::BisectionMethod()
{
    // acceptCoefficients();

    int itrCount = 0;
    double a = -999, b = -999;
    int flag = 0;

    for (int i = -20; i <= 20; i++)
    {
        for (int j = 20; j >= -20; j--)
        {
            if (f(i) < 0.0 && f(j) > 0.0)
            {
                flag = 1;
                a = i;
                b = j;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }

    if (a != -999 && b != -999)
    {
        double c = a;

        cout << "\nBracketing interval : [" << a << " to " << b << "]\n";
        cout << "\n\033[33ma\t\t\tb\t\t\tx\t\t\tf(a)\t\t\tf(b)\t\t\tf(x)\033[0m\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
        while (abs(b - a) >= TOL)
        {
            c = (a + b) / 2;

            if (f(c) == 0.0)
            {
                break;
            }

            cout << fixed << setprecision(6) << a << "\t\t" << b << "\t\t" << c << "\t\t" << f(a) << "\t\t" << f(b) << "\t\t" << f(c) << endl;

            // if ((HornersRule(a) > 0 && HornersRule(c) < 0) || HornersRule(a) < 0 && HornersRule(c) > 0)
            if ((f(a) > 0 && f(c) < 0) || (f(a) < 0 && f(c) > 0))
            {
                b = c;
            }
            else
            {
                a = c;
            }
            itrCount++;
        }

        cout << "\nThe value of root is (Bisection Method) : " << c << endl;
        cout << "Number of iterations required : " << itrCount << endl;
    }
    else
    {
        cout << "\033[31mBracketing interval does not exist between -20 to 20.\033[0m" << endl;
    }
}
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// Newton-Raphson Method
void RootFinding::NewtonRaphsonMethod()
{
    double xn, xn1;
    int itrCount = 0;

    do
    {
        cout << "\n\nProvide a starting point (x0) for finding the root : ";
        cin >> xn;

        cout << "\n\033[33mx_n\t\t\tf(x)\t\t\tf'(x)\t\t\tx_n+1\n\033[0m";
        cout << "----------------------------------------------------------------------------------\n";

        double tempXn = xn;

        while (abs(tempXn - xn1) >= TOL)
        {
            tempXn = xn;
            if (fDerivative(xn) != 0)
            {
                xn1 = xn - (f(xn) / fDerivative(xn));
                cout << tempXn << "\t\t" << f(xn) << "\t\t" << fDerivative(xn) << "\t\t" << xn1 << "\n";
                xn = xn1;
                itrCount++;
            }
            else
            {
                cout << "f'(x) is 0. Please choose a different starting point.\n\n";
                break;
            }
        }

        cout << "\nThe value of root is (Newton-Raphson Method) : " << xn << endl;
        cout << "Number of iterations required : " << itrCount << "\n\n";

    } while (fDerivative(xn) == 0); // Continue till f'(x) is becoming 0 in some iteration.
}
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// Fixed-point Method
void RootFinding::FixedPoint()
{
    int itrCnt = 0;
    double xn = 2.5;

    cout << "\n\033[33mx_n\t\t\tf(x_n)\n\033[0m";
    cout << "--------------------------------\n";

    while (abs(xn - q(xn)) >= TOL)
    {
        if (q(xn) == INFINITY || q(xn) > 1000000)
        {
            cout << "\n\nThe function is diverging with the given starting point...\n\n";
            exit(0);
        }
        q(xn);
        cout << xn << "\t\t" << q(xn) << endl;
        xn = q(xn);
        itrCnt++;
        if (itrCnt > 100)
            break;
    }

    cout << "\nValue of root using Fixed Point Iteration Method : " << xn << endl;
    cout << "Number of iterations required : " << itrCnt << "\n\n";
}