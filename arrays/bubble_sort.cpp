#include <iostream>
#include <iterator>

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

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    int testArray[] {5,8,10,2,7};
    int arraySize = std::size(testArray);
    bubbleSort(testArray, arraySize);
    printArr(testArray, arraySize);
    return 0;
}