#include "Matrix.hpp"

using namespace std;

double *Matrix::GaussianElimination(int n)
{
    double *ans = new double[n]; // static keyword is used to ensure that the array's lifetime extends beyond the scope of the function, which would otherwise be limited to the function's execution.
    for (int i = 0; i < 3; i++)
    {
        ans[i] = i + 1;
    }
    return ans;
}

/*
When a local array is declared inside a function, it is created on the stack. Once the function exits, the stack memory is reclaimed, and any reference to that array becomes invalid. Therefore, if you try to return a local array, it would point to a memory location that no longer exists, causing undefined behavior.
By declaring the array as static, the array is moved from the stack to static storage (usually the data segment), meaning that it persists for the lifetime of the program. The function will return a reference to this array, which is valid even after the function exits.
*/