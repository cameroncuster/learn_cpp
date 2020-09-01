#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void alloc2d(float**&, int, int);
void free2d(float**&, int);

int main() {
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

    alloc2d(array2d, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            input >> array2d[i][j];
        }
    }

    free2d(array2d, rows);

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