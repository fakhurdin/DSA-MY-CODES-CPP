#include <iostream>
#include <unordered_set>
using namespace std;

bool findTriplets(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        unordered_set<int> hashSet;
        for (int j = i + 1; j < n; ++j) {
            int sum = -(arr[i] + arr[j]);
            if (hashSet.find(sum) != hashSet.end()) {
                return true; // Triplet found
            }
            hashSet.insert(arr[j]);
        }
    }
    return false; // Triplet not found
}

int main() {
    int n = 5;
    int arr[] = {0, -1, 2, -3, 1};

    bool result = findTriplets(arr, n);
    cout << "Output: " << (result ? "1" : "0") << endl;

    return 0;
}

