#include <cmath>
#include <functional>

using namespace std;


// you will add the function prototype for the function named newtonApprox 
// here.  Parameters are the starting guess, the name of function being
// evaluated, the function that computes the derivative of the function and
// an epsilon value for computing if it is close enough.
 
double newtonApprox(double n, function<double(double)> f,
    function<double(double)> fP, double epsilon);
