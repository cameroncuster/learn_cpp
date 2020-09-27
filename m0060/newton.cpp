#include "newton.h"
#include <cmath>

// write the function named newtonApprox here

double newtonApprox(double n, function<double(double)> f, 
    function<double(double)> fP, double epsilon)
{
    if (abs(f(n)) < epsilon)
    {
        return n;
    }
    else
    {
        n = n - f(n) / fP(n);
        return newtonApprox(n, f, fP, epsilon);
    }
}