#include <cmath>
#include <bits/stdc++.h>
#define TOL 0.000001 // 10^6 for maximum accuracy

using namespace std;

class Roots
{
public:
    double f(double x)
    {
        return (2 * x * x) - 1;
    }

    double f_derivative(double x)
    {
        return (4 * x);
    }

    // Bisection Method
    void BisectionMethod()
    {
        double a = -999, b = -999;
        int itrCount = 0;

        int flag = 0;
        for (int i = -20; i < 50; i++)
        {
            for (int j = 20; j < 50; j++)
            {
                if (f(i) < 0.0 && f(j) > 0.0)
                {
                    flag = 1;
                    a = i;
                    b = j;
                    // cout << a << " " << b << ":" << f(a) << " " << f(b) << endl;
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

            cout << "\n\033[33ma\t\t\tb\t\t\tx\t\t\tf(a)\t\t\tf(b)\t\t\tf(x)\033[0m\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
            while ((b - a) >= TOL)
            {
                c = (a + b) / 2;

                if (f(c) == 0.0)
                {
                    break;
                }

                cout << fixed << setprecision(6) << a << "\t\t" << b << "\t\t" << c << "\t\t" << f(a) << "\t\t" << f(b) << "\t\t" << f(c) << endl;

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

    // ---------------------------------------------------

    // Newton-Raphson Method
    void NewtonRaphsonMethod()
    {
        double xn, xn_1;
        int itrCount = 0;

        do
        {
            cout << "\n\nProvide a starting point (x0) for finding the root : ";
            cin >> xn;
            cout << "\n\033[33mx_n\t\t\tf(x)\t\t\tf'(x)\t\t\tx_n+1\n\033[0m";
            cout << "----------------------------------------------------------------------------------\n";
            if (xn > 0)
            {
                double temp_xn = xn;

                while (abs(temp_xn - xn_1) >= TOL)
                {
                    temp_xn = xn;
                    xn_1 = xn - (f(xn) / f_derivative(xn));
                    cout << temp_xn << "\t\t" << f(xn) << "\t\t" << f_derivative(xn) << "\t\t" << xn_1 << "\n";
                    xn = xn_1;
                    itrCount++;
                }

                cout << "\nThe value of root is (Newton-Raphson Method) : " << xn << endl;
                cout << "Number of iterations required : " << itrCount << "\n\n";
            }
            else
            {
                cout << "\n\033[31mStarting point has to be greater than 0!\033[0m" << endl;
            }
        } while (xn <= 0);
    }
};

int main()
{
    Roots bisection, newtonRaphson;

    bisection.BisectionMethod();
    newtonRaphson.NewtonRaphsonMethod();

    return 0;
}