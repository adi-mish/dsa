#include <iostream>
#include <iterator>
using namespace std;

// Time Complexity:
// - Worst Case: O(n^2) - occurs when the array is reverse sorted.
// - Best Case: O(n) - occurs when the array is already sorted.
// - Average Case: O(n^2).

// Details:
// - Simple and straightforward.
// - In-place algorithm with a space complexity of O(1).
// - Stable sorting algorithm.
// - Suitable for small datasets or educational purposes.
// - Inefficient for large datasets due to its quadratic time complexity.

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArr(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
}

int main() {
    int testArray[] {5,8,10,2,7};
    int arraySize = size(testArray);
    insertionSort(testArray, arraySize);
    printArr(testArray, arraySize);
    return 0;
}