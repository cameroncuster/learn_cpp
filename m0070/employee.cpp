#include "employee.h"
employee::employee( )
{
    id = 0;
    firstName = "";
    lastName = "";
    salary = 0.0;
    bonus = 0.0;
}
employee::employee( int theID, string fname, string lname, double theSalary,
                    double theBonus )
{
    id = 0;
    firstName = "";
    lastName = "";
    salary = 0.0;
    bonus = 0.0;

    if( id > 0 && theSalary >= 0.0 && theBonus >= 0.0 && 
        !fname.empty() && !lname.empty() )
    {
        id = theID;
        firstName = fname;
        lastName = lname;
        salary = theSalary;
        theBonus = theBonus;
    }
}
employee::~employee( )
{

}
