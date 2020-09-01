#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void alloc2d(float**&, int, int);
void free2d(float**&, int);
float sumArray(float*, int);
float findMin(float*, int);
float findMax(float*, int);

int main(int argc) {

    // check for correct number of command line arguments
    if (argc != 3) {
        exit(1);
    }

    // create a 2d array and define rows and columns
    float** array2d = nullptr;
    int rows = 0;
    int cols = 0;
    ifstream input;
    ofstream output;
    input.open("data1.txt");
    
    if (!input.is_open()) {
        cout << "Unable to open the input file: data1.txt" << endl;
    }

    output.open("data2.txt");

    if (!output.is_open()) {
        cout << "Unable to open the output file: data2.txt" << endl;
    }

    input >> rows >> cols;

    // allocate a dynamic 2d array and assign values from the input
    alloc2d(array2d, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            input >> array2d[i][j];
        }
    }

    // output the array and its values to the output file
    for (int i = 0; i < rows; i++) {
        output << fixed << setprecision(3) << "Row: " << setw(10) << i
            << " Sum: " << setw(15) << sumArray(array2d[i], cols)
            << " Minimum: " << setw(15) << findMin(array2d[i], cols)
            << " Maximum: " << setw(15) << findMax(array2d[i], cols) << endl;
    }

    for (int i = 0; i < rows; i++) {
        output << endl;
        for (int j = 0; j < cols; j++) {
            output << fixed << setprecision(3) << setw(15) << array2d[i][j];
        }
    }

    // free the memory used by the array
    free2d(array2d, rows);

    input.close();
    output.close();
    return 0;
}

void alloc2d(float**& ptr, int rows, int cols) {
    ptr = new (nothrow) float* [rows];
    if (ptr == nullptr) {
        cout << "Not enough memory to run the program." << endl;
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        ptr[i] = new (nothrow) float[cols];
        if (ptr[i] == nullptr) {
            cout << "Not enough memory to run the program." << endl;
            exit(1);
        }
    }
}

void free2d(float**& ptr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete ptr[i];
    }
    delete[] ptr;
    ptr = nullptr;
}

float sumArray(float* ptr, int cols) {
    float sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += ptr[i];
    }
    return sum;
}

float findMin(float* ptr, int cols) {
    float min = FLT_MAX;
    for (int i = 0; i < cols; i++) {
        if (min > ptr[i]) {
            min = ptr[i];
        }
    }
    return min;
}

float findMax(float* ptr, int cols) {
    float max = FLT_TRUE_MIN;
    for (int i = 0; i < cols; i++) {
        if (max < ptr[i]) {
            max = ptr[i];
        }
    }
    return max;
}