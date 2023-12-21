#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:
// - Worst Case: O(n log n) - occurs in all cases due to the complete heapification process.
// - Best Case: O(n log n) - same as the worst case.
// - Average Case: O(n log n) - consistent performance across different scenarios.

// Details:
// - Comparison-based sorting algorithm that uses a binary heap.
// - In-place algorithm with a space complexity of O(1) (excluding input array).
// - Unstable sorting algorithm.
// - Efficient for large datasets.
// - Consistent performance, making it suitable for a variety of scenarios.
// - Used when a stable sort is not required and guaranteed performance is essential.

void heapify(vector<int>& arr, int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(vec);
    printVec(vec);
    return 0;
}

