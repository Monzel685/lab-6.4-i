#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void create(double* arr, int size, double min, double max) {
    for (int i = 0; i < size; i++) {
        arr[i] = (max - min) * rand() / RAND_MAX + min;
    }
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(10) << fixed << setprecision(2) << arr[i];
    }
    cout << endl;
}

int minAbsIndex(double* arr, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < abs(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

double sumAfterFirstNegative(double* arr, int size) {
    double sum = 0;
    bool foundNegative = false;
    for (int i = 0; i < size; i++) {
        if (foundNegative) {
            sum += abs(arr[i]);
        }
        if (arr[i] < 0 && !foundNegative) {
            foundNegative = true;
        }
    }
    return sum;
}

void compressArray(double* arr, int& size, double a, double b) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < a || arr[i] > b) {
            arr[newSize++] = arr[i];
        }
    }
    for (int i = newSize; i < size; i++) {
        arr[i] = 0;
    }
    size = newSize;
}

int main() {
    srand((unsigned)time(NULL));
    int size;
    double a, b;

    cout << "Enter size: ";
    cin >> size;
    cout << "Enter a and b: ";
    cin >> a >> b;

    double* arr = new double[size];
    create(arr, size, -20, 20);

    printArray(arr, size);

    int minIndex = minAbsIndex(arr, size);
    cout << "Index of min absolute element: " << minIndex << endl;

    double sum = sumAfterFirstNegative(arr, size);
    cout << "Sum of absolute values after first negative: " << sum << endl;

    compressArray(arr, size, a, b);
    printArray(arr, size);

    delete[] arr;
    return 0;
}
