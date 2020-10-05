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

bool employee::setID( int newID )
{
    if( id > 0 )
    {
        id = newID;
        return true;
    }
    return false;
}

int employee::getID( )
{
    return id;
}

bool employee::setFirstName( string newFname )
{
    if( !newFname.empty( ) )
    {
        firstName = newFname;
        return true;
    }
    return false;
}

string employee::getFirstName( )
{
    return firstName;
}

bool employee::setLastName( string newLname )
{
    if( !newLname.empty( ) )
    {
        lastName = newLname;
        return true;
    }
    return false;
}

string employee::getLastName( )
{
    return lastName;
}

bool employee::setSalary( double theNewSalary )
{
    if( theNewSalary > 0.0 )
    {
        salary = theNewSalary;
        return true;
    }
    return false;
}

double employee::getSalary( )
{
    return salary;
}

bool employee::setBonus( double theNewBonus )
{
    if( theNewBonus > 0.0 )
    {
        bonus = theNewBonus;
        return true;
    }
    return false;
}

double employee::getBonus( )
{
    return bonus;
}