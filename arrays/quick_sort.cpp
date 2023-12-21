#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:
// - Worst Case: O(n^2) - occurs when the pivot selection leads to unbalanced partitions.
// - Best Case: O(n log n) - occurs when the pivot selection leads to balanced partitions.
// - Average Case: O(n log n).

// Details:
// - Divide-and-conquer algorithm.
// - In-place algorithm with a space complexity of O(log n) for the recursive call stack.
// - Unstable sorting algorithm.
// - Often faster in practice compared to other O(n log n) algorithms.
// - Used in many applications and standard libraries.

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


void printVec(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}

int main() {
    vector<int> vec {5,8,10,2,7};
    int len = vec.size();
    quickSort(vec, 0, len-1);
    printVec(vec);
    return 0;
}