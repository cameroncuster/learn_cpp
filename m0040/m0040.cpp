#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct empData
{
    int id;
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus;
};

void printFile(fstream &bFile);
void applyBonus(fstream &bFile, int empID);

int main(int argc, char *argv[])
{    
    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID";
        exit(1);
    }

    int empID = stoi(argv[2]);
    fstream bFile;
    
    bFile.open("data1.bin", ios::in | ios::out | ios::binary | ios::ate);
    if (!bFile.is_open())
    {
        cout << "Unable to open binary file: " << argv[1] << endl;
        exit(1);
    }

    printFile(bFile);
    applyBonus(bFile, empID);
    printFile(bFile);
    bFile.close();
    return 0;
}

void printFile(fstream &bFile)
{
    empData emp;
    cout << showpoint << fixed << setprecision(2);
    bFile.clear();
    bFile.seekp(0, ios::beg);
    while (bFile.read((char*)&emp, sizeof(empData)))
    {
        cout << setw(7) << emp.id << " "
            << left << setw(20) << emp.firstName
            << setw(40) << emp.lastName << right
            << " Salary: " << setw(10) << emp.salary
            << " Bonus: " << setw(10) << emp.bonus << endl;
    }
}

void applyBonus(fstream &bFile, int empID)
{
    empData employee;
    double bonus = 500;

    while (bFile.read((char*)&employee, sizeof(empData)))
    {
        bFile.clear();
        if (employee.id == empID)
        {
            break;
        }
    }

    if (empID != employee.id)
    {
        cout << "Employee ID " << empID << " was not found." << endl;
        bFile.close();
        exit(1);
    }

    bFile.clear();
    bFile.seekp(int(sizeof(empData) - sizeof(double)), ios::cur);
    bFile.write((char*)&bonus, sizeof(double));
    cout << "Employee ID " << empID << " has been updated." << endl;
}