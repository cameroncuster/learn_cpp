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
void applyBonus(fstream& bFile, char argv[2]);

int main(int argc, char *argv[])
{    
    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID";
        exit(1);
    }

    fstream bFile;
    
    bFile.open("data1.bin", ios::in | ios::out | ios::binary);
    if (!bFile.is_open())
    {
        cout << "Unable to open binary file: " << argv[1] << endl;
        exit(1);
    }

    printFile(bFile);
    applyBonus(bFile, argv[2]);
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

void applyBonus(fstream &bFile, char argv[2])
{
    int i = 0;
    int j = 0;
    int id = 0;
    double bonus = 500;
    bFile.clear();
    bFile.seekp(0, ios::beg);
    bFile.read((char*)&j, sizeof(int));
    while (argv[2] != id && j != id)
    {
        bFile.clear();
        bFile.seekp(i, ios::beg);
        bFile.read((char*)&id, sizeof(int));
        i += 60;
    }

    if (j == id || (int)argv[2] == id)
    {
        cout << "Employee ID " << argv[2] << " was not found." << endl;
        bFile.close();
        exit(1);
    }

    bFile.seekp(int(sizeof(empData) - sizeof(int) - sizeof(double)), ios::cur);
    bFile.write((char*)&bonus, sizeof(double));
    // what do I need to do to my write function?

    cout << "Employee ID " << argv[2] << " has been updated." << endl;
}