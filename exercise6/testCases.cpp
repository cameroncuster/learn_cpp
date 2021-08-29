#include "newton.h"
#include "..\catch.hpp"


// functions
double f0( double x )
{
    return pow( x, 3 ) + 2;
}

double fP0( double x )
{
    return 3 * pow( x, 2 );
}

double f1(double x)
{
    return x + 5;
}

double fP1(double x)
{
    return 1;
}

double f2(double x)
{
    return pow(x, 2) + x - 1;
}

double fP2(double x)
{
    return 2 * x + 1;
}

double f3(double x)
{
    return pow(x, 5);
}

double fP3(double x)
{
    return 5 * pow(x, 4);
}

double f4(double x)
{
    return pow(x, 3) / 3;
}

double fP4(double x)
{
    return pow(x, 2);
}

TEST_CASE( "newtonApprox - x^3 + 2" )
{
    double epsilon = .001;
    double n = 2;
    double ans;
    
    // note, you pass the name of your functions
    ans = newtonApprox( n, f0, fP0, epsilon ); 

    REQUIRE( fabs( f0( ans ) ) <= epsilon );
}

TEST_CASE("newtonApprox - x + 5")
{
    double epsilon = .001;
    double n = 0;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, f1, fP1, epsilon);

    REQUIRE(fabs(f1(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - x^2 + x - 1")
{
    double epsilon = .001;
    double n = 0;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, f2, fP2, epsilon);

    REQUIRE(fabs(f2(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - x^(1/2)")
{
    double epsilon = .001;
    double n = 0;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, f3, fP3, epsilon);

    REQUIRE(fabs(f3(ans)) <= epsilon);
}

TEST_CASE("newtonApprox - x^3/3")
{
    double epsilon = .001;
    double n = 0;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, f4, fP4, epsilon);

    REQUIRE(fabs(f4(ans)) <= epsilon);
}