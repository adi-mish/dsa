#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:
// - Worst Case: O(n log n).
// - Best Case: O(n log n).
// - Average Case: O(n log n).

// Details:
// - Divide-and-conquer algorithm.
// - Out-of-place algorithm with a space complexity of O(n).
// - Stable sorting algorithm.
// - Well-suited for large datasets.
// - Used in external sorting and linked lists.

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(vec, 0, len-1);
    printVec(vec);
    return 0;
}