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

    // function call here to compare

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