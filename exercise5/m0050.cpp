#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// basic struct
struct employee
{
    int id;
    string firstName;
    string lastName;
    double salary;
    double bonus;
};

// prototypes
bool sortById(employee emp1, employee emp2);
bool sortByName(employee emp1, employee emp2);
bool sortBySalary(employee emp1, employee emp2);

int main(int argc, char* argv[])
{
    // vars
    ifstream fin;
    ofstream fout;
    employee data;
    vector<employee> empData;
    string header;
    bool check = false;

    // check command line args
    if (argc != 4)
    {
        cout << 
            "Usage: m0050.exe inputCSVFile outputCSVFILE sortMethod" 
             << endl;
        exit(0);
    }
 
    // ensure files are open, exit if not
    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        exit(0);
    }

    fout.open(argv[2]);
    if (!fout.is_open())
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        fin.close();
        exit(0);
    }

    // get and output the header
    getline(fin, header);
    fout << header << endl;

    // get data to fill vector with structures
    while (fin >> data.id)
    {
        fin.ignore();
        getline(fin, data.firstName, ',');
        getline(fin, data.lastName, ',');
        fin >> data.salary;
        fin.ignore();
        fin >> data.bonus;
        empData.push_back(data);
    }

    // complete operation with error checking
    if ((string)argv[3] == "-i")
    {
        sort(empData.begin(), empData.end(), sortById);
        check = true;
    }
    if ((string)argv[3] == "-n") 
    {
        sort(empData.begin(), empData.end(), sortByName);
        check = true;
    }
    if ((string)argv[3] == "-s") 
    {
        sort(empData.begin(), empData.end(), sortBySalary);
        check = true;
    }
    if (check == false)
    {
        cout << "Invalid Sort Method:" << endl
            << "-i - sort by id" << endl
            << "-n - sort by name" << endl
            << "-s - sort by salary" << endl;
        exit(0);
    }

    // output with 2 decimals showing for salary
    fout << showpoint << fixed << setprecision(2);
    for (auto d : empData)
    {
        fout << d.id << ','
            << d.firstName << ','
            << d.lastName << ','
            << d.salary << ','
            << d.bonus << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

// ID compare function
bool sortById(employee emp1, employee emp2)
{
    if (emp1.id < emp2.id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Name compare function (last then first)
bool sortByName(employee emp1, employee emp2)
{
    if (emp1.lastName == emp2.lastName)
    {
        return emp1.firstName < emp2.firstName;
    }
    
    return emp1.lastName < emp2.lastName;
}

// Salary compare function (highest to lowest)
bool sortBySalary(employee emp1, employee emp2)
{
    if (emp1.salary > emp2.salary)
    {
        return true;
    }
    else
    {
        return false;
    }
}