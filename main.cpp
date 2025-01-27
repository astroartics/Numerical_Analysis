#include "RootFinding.hpp"

int main()
{
    RootFinding bisection, newtonRaphson;

    bisection.BisectionMethod();
    newtonRaphson.NewtonRaphsonMethod();

    return 0;
}