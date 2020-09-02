#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void alloc2d(float**&, int, int);
void free2d(float**&, int);
float sumArray(float*, int);
float* findMin(float*&, int);
float* findMax(float*&, int);

int main(int argc, char** argv)
{
    // check for proper number of command line arguments
    if (argc != 3)
    {
        cout << "Usage: m0021.exe inputfile outputfile";
        exit(0);
    }

    // create a 2d array and define rows and columns
    float** array2d = nullptr;
    int rows = 0;
    int cols = 0;
    ifstream input;
    ofstream output;

    input.open(argv[1]);

    if (!input.is_open())
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        exit(0);
    }

    output.open(argv[2]);

    if (!output.is_open())
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        exit(0);
    }

    input >> rows >> cols;

    // allocate a dynamic 2d array and assign values from the input
    alloc2d(array2d, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            input >> array2d[i][j];
        }
    }

    // output the array and its values to the output file
    output << rows << setw(2) << cols << endl << fixed << showpoint << setprecision(3);
    for (int i = 0; i < rows; i++)
    {
        output << "Row:" << setw(10) << i
            << " Sum:" << setw(15) << sumArray(array2d[i], cols)
            << " Minimum:" << setw(15) << *findMin(array2d[i], cols)
            << " Maximum:" << setw(15) << *findMax(array2d[i], cols) << endl;
    }

    output << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output << setw(15) << array2d[i][j];
        }
        output << endl;
    }

    // free the memory used by the array
    free2d(array2d, rows);

    input.close();
    output.close();
    return 0;
}

void alloc2d(float**& ptr, int rows, int cols)
{
    ptr = new (nothrow) float* [rows];
    if (ptr == nullptr)
    {
        cout << "Not enough memory to run the program." << endl;
        exit(0);
    }
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new (nothrow) float[cols];
        if (ptr[i] == nullptr)
        {
            cout << "Not enough memory to run the program." << endl;
            exit(0);
        }
    }
}

void free2d(float**& ptr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete ptr[i];
    }
    delete[] ptr;
    ptr = nullptr;
}

float sumArray(float* ptr, int cols)
{
    float sum = 0;
    for (int i = 0; i < cols; i++)
    {
        sum += ptr[i];
    }
    return sum;
}

float* findMin(float* &ptr, int cols)
{
    int minLocation = 0;
    for (int i = 1; i < cols; i++)
    {
        if (ptr[minLocation] > ptr[i])
        {
            minLocation = i;
        }
    }
    return &ptr[minLocation];
}

float* findMax(float* &ptr, int cols)
{
    int maxLocation = 0;
    for (int i = 1; i < cols; i++)
    {
        if (ptr[maxLocation] < ptr[i])
        {
            maxLocation = i;
        }
    }
    return &ptr[maxLocation];
}