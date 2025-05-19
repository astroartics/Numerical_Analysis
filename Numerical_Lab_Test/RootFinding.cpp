#include "RootFinding.hpp"

void RootFinding::setTolerance(double tol)
{
    TOL = pow(10, -tol);
}

// Bisection Method
// double RootFinding::BisectionMethod(int lb, int ub, int printItr)
// {
//     int itrCount = 0;
//     double a = -999, b = -999, c;
//     int flag = 0;

//     if (lb > ub)
//     {
//         int temp = ub;
//         ub = lb;
//         lb = temp;
//     }

//     for (int i = lb; i <= ub; i++)
//     {
//         for (int j = ub; j >= lb; j--)
//         {
//             if ((f(i) < 0.0 && f(j) > 0.0) || (f(i) > 0.0 && f(j) < 0.0))
//             {
//                 flag = 1;
//                 a = i;
//                 b = j;
//                 break;
//             }
//             else
//             {
//                 flag = 0;
//             }
//         }
//         if (flag)
//         {
//             break;
//         }
//     }

//     if (a != -999 && b != -999)
//     {
//         c = a;

//         cout << "\nBracketing interval : [" << (a < b ? a : b) << " to " << (b > a ? b : a) << "]\n";

//         if (printItr)
//         {
//             cout << "\n\033[33ma\t\t\tb\t\t\tx\t\t\tf(a)\t\t\tf(b)\t\t\tf(x)\033[0m\n";
//             cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
//         }

//         while (abs(b - a) >= TOL)
//         {
//             c = (a + b) / 2.0;

//             if (f(c) == 0.0)
//             {
//                 break;
//             }

//             if (printItr)
//             {
//                 cout << fixed << setprecision(6) << a << "\t\t" << b << "\t\t" << c << "\t\t" << f(a) << "\t\t" << f(b) << "\t\t" << f(c) << endl;
//             }

//             if ((f(a) > 0 && f(c) < 0) || (f(a) < 0 && f(c) > 0))
//             {
//                 b = c;
//             }
//             else
//             {
//                 a = c;
//             }
//             itrCount++;
//         }

//         cout << "\nNumber of iterations required : " << itrCount << endl;
//         return c;
//     }
//     else
//     {
//         cout << "\033[31mRoot does not exist in interval " << lb << " to " << ub << ".\033[0m" << endl;
//         exit(0);
//     }
// }

vector<double> RootFinding::BisectionMethod(int lb, int ub, int printItr)
{
    vector<double> roots;

    // int lb, ub;
    // cout << "\nEnter lowerbound and upperbound for an interval : ";
    // cin >> lb;
    // cin >> ub;

    int itrCount = 0;
    double a = -999, b = -999, c;
    int flag = 0;

    if (lb > ub)
    {
        int temp = ub;
        ub = lb;
        lb = temp;
    }

    // for (int i = lb; i <= ub; i++)
    // {
    //     for (int j = ub; j >= lb; j--)
    //     {
    //         if ((f(i) < 0.0 && f(j) > 0.0) || (f(i) > 0.0 && f(j) < 0.0))
    //         {
    //             flag = 1;
    //             a = i;
    //             b = j;
    //             break;
    //         }
    //         else
    //         {
    //             flag = 0;
    //         }
    //     }
    //     if (flag)
    //     {
    //         break;
    //     }
    // }

    a = lb;
    b = 0;

    if (a != -999 && b != -999)
    {
        do
        {
            c = a;

            cout << "\nBracketing interval : [" << (a < b ? a : b) << " to " << (b > a ? b : a) << "]\n";

            if (printItr)
            {
                cout << "\n\033[33ma\t\t\tb\t\t\tx\t\t\tf(a)\t\t\tf(b)\t\t\tf(x)\033[0m\n";
                cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
            }

            while (abs(b - a) >= TOL)
            {
                c = (a + b) / 2.0;

                if (f(c) == 0.0)
                {
                    if (find(roots.begin(), roots.end(), c) == roots.end())
                    {
                        cout << "\n\nResult : " << c << endl;
                        roots.push_back(c);
                    }
                    // cout << c << endl;
                    break;
                }

                if (printItr)
                {
                    cout << fixed << setprecision(6) << a << "\t\t" << b << "\t\t" << c << "\t\t" << f(a) << "\t\t" << f(b) << "\t\t" << f(c) << endl;
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

            // if (find(roots.begin(), roots.end(), c) != roots.end())
            // {
            //     cout << c << endl;
            //     roots.push_back(c);
            // }

            // if (c < 0)
            a = c + 1;
            // else
            //     a = c - 1;

            if (a > 0)
                b = ub;
            else
                b = 0;

            cout << "\n\nResult : " << c << endl;
            cout << "\na : " << a << "b : " << b << endl;
            cout << "\nNumber of iterations required : " << itrCount << endl;

            if (find(roots.begin(), roots.end(), c) == roots.end())
            {
                // cout << "\n\nResult : " << c << endl;
                roots.push_back(c);
            }

            // return c;

            // cout << "SIZE : " << roots.size() << endl;
        } while (roots.size() != 4);
    }
    else
    {
        cout << "\033[31mRoot does not exist in interval " << lb << " to " << ub << ".\033[0m" << endl;
        exit(0);
    }

    return roots;
}