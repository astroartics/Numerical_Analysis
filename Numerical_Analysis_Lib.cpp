#include <iostream>
#include <cmath>
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
        double a, b;
        int itrCount = 0;

        int flag = 0;
        for (int i = 0; i < 50; i++)
        {
            for (int j = 1; j < 50; j++)
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

        double c = a;
        while ((b - a) >= TOL)
        {
            c = (a + b) / 2;

            if (f(c) == 0.0)
            {
                break;
            }

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
        cout << "The value of root is (Bisection Method) : " << c << endl;
        cout << "Number of iterations required : " << itrCount << endl;
    }

    // ---------------------------------------------------

    // Newton-Raphson Method
    void NewtonRaphsonMethod()
    {
        double xn, xn_1;
        int itrCount = 0;

        do
        {
            cout << "\nProvide a starting point (x0) for finding the root : ";
            cin >> xn;
            if (xn > 0)
            {
                double temp_xn = xn;

                while (abs(temp_xn - xn_1) >= TOL)
                {
                    temp_xn = xn;
                    xn_1 = xn - (f(xn) / f_derivative(xn));
                    xn = xn_1;
                    itrCount++;
                }

                cout << "The value of root is (Newton-Raphson Method) : " << xn << endl;
                cout << "Number of iterations required : " << itrCount << endl;
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