#include "Numerical_Analysis.hpp"

void Numerical_Analysis::roots()
{
    RootFinding findRoot;

    findRoot.BisectionMethod();
    findRoot.NewtonRaphsonMethod();
    findRoot.FixedPoint();
}