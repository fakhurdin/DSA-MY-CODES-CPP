// Function to perform Binary Insertion Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> indirectIndexSort(const vector<int>& arr) {
    vector<int> indices(arr.size());
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, 2, ... n-1

    stable_sort(indices.begin(), indices.end(), [&arr](int a, int b) {
        return arr[a] < arr[b];
    });

    return indices;
}

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;

        // Using binary search to find the proper position
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Shifting elements to insert key at correct position
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

