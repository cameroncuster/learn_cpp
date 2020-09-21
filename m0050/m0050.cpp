#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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
    ifstream fin;
    ofstream fout;
    employee data;
    vector<employee> empData;
    vector<employee>::iterator it;
    string header;

    if (argc != 4)
    {
        cout << "Usage: m0050.exe inputCSVfile outputCSVfile sortMethod" 
             << endl;
        exit(0);
    }

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

    getline(fin, header);
    fout << header << endl;
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

    if ((string)argv[3] == "-i")
    {
        // use algorithm of sort to sort by id
    }
    if ((string)argv[3] == "-n") 
    {
        // function call to sort by name
    }
    if ((string)argv[3] == "-s") 
    {
        // function call to sort by salary
    }

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
        if (emp1.firstName < emp2.firstName)
        {
            return true;
        }
    }
    if (emp1.lastName < emp2.lastName)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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