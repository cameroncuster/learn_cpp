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
    // check if the id is here, ask how to do this
    bFile.clear();
    bFile.seekp(0, ios::beg);
    int i = 0;
    char id;
    char* idptr = &id;
    idptr = new (nothrow) char[sizeof(int)];
    if (idptr == nullptr)
    {
        cout << "Not enough memory to allocate an array.";
    }

    while (argv[2] != id)
    {
        bFile.seekp(i, ios::beg);
        id = bFile.read(idptr, sizeof(int));
        stoi(&id);
        i += 60;
    }
    bFile.clear();
    bFile.seekg(/*this is where the id is + 52*/, ios::beg);

}