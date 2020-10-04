#ifndef __EMPLOYEE__H__
#define __EMPLOYEE__H__
#include <string>
using std::string;

class employee
{
    public:
        employee( );
        employee( int theID, string fname, string lname, double theSalary,
                  double theBonus );
        ~employee( );



    private:
        int id;
        string firstName;
        string lastName;
        double salary;
        double bonus;
};

#endif

