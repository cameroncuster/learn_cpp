#include <vector>
#include <fstream>
#include <iostream>
#include <string>

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
    /*
    if (argc == 3)
    {
        if (argv[1])
        {
            // figure out what to put here
        }
    }
    */
    ifstream fin;
    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        exit(0);
    }

    ofstream fout;
    fout.open(argv[2]);
    if (!fout.is_open())
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        fin.close();
        exit(0);
    }

    employee data;
    vector<employee> empData;
    while (fin >> data.id)
    {
        fin.ignore();
        fin >> data.firstName;
        fin.ignore();
        fin >> data.lastName;
        fin.ignore();
        fin >> data.salary;
        fin.ignore();
        fin >> data.bonus;
        empData.push_back(data);
    }

    // function call here to compare

    for (int i = 0; i < empData.size(); i++)
    {
        fout << empData.at(i) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}