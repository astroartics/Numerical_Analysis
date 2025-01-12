#include <iostream>
#define MARGIN 0.01

using namespace std;

class BisectionMethod
{
public:
    double f(double x)
    {
        return (x * x * x) - (2 * x) - 5;
    }

public:
    void root()
    {
        double a, b;

        int flag = 0;
        for (int i = 1; i < 50; i++)
        {
            for (int j = 2; j < 50; j++)
            {
                if (f(i) < 0.0 && f(j) > 0.0)
                {
                    flag = 1;
                    a = i;
                    b = j;
                    cout << a << " " << b << ":" << f(a) << " " << f(b) << endl;
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
        while ((b - a) >= MARGIN)
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
        }
        cout << "The value of root is : " << c << endl;
    }
};

int main()
{
    BisectionMethod bisection;
    bisection.root();

    return 0;
}