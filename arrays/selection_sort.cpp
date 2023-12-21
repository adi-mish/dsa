#include <iostream>

// Time Complexity:
// - Worst Case: O(n^2) - same as bubble sort.
// - Best Case: O(n^2) - same as bubble sort.
// - Average Case: O(n^2).

// Details:
// - Simple and intuitive.
// - In-place algorithm with a space complexity of O(1).
// - Unstable sorting algorithm.
// - Generally outperforms bubble sort in practice.
// - Inefficient for large datasets.

void printArr(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int testArray[] {5,8,10,2,7};
    int arraySize = std::size(testArray);
    selectionSort(testArray, arraySize);
    printArr(testArray, arraySize);
    return 0;
}