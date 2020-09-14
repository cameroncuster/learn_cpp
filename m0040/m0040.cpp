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

int main(int argc, char *argv[])
{
    fstream bFile;
    
    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID";
        exit(1);
    }
    
    bFile.open("data1.bin", ios::in | ios::out | ios::binary | ios::trunc);
    if (!bFile.is_open())
    {
        cout << "Unable to open binary file: " << argv;
        exit(1);
    }

    printFile(bFile);
    return 0;
}

void printFile(fstream &bFile)
{

    cout << setw(7) << " "
        << left << setw(20)
        << setw(40) << right
        << "Salary: " << setw(10)
        << "Bonus: " << setw(10) << endl;
}