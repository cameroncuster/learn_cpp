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
        employee( string fname, string lname); // can i create multiple instances?
        ~employee( );
        
        // function protoypes
        bool setID( int newID );
        int getID( );
        bool setFirstName( string newFname );
        string getFirstName( );
        bool setLastName( string newLname );
        string getLastName( );
        bool setSalary( double theNewSalary );
        double getSalary( );
        bool setBonus( double theNewBonus );
        double getBonus( );


    private:
        int id;
        string firstName;
        string lastName;
        double salary;
        double bonus;
};

#endif

