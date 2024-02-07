#include <iostream>
#include <unordered_map>
using namespace std;

int firstRepeatingElement(int n, int arr[]) {
    unordered_map<int, int> indexMap;
    int minIndex = n + 1; // Initialize with a value greater than array size
    int firstRepeating = -1;

    for (int i = 0; i < n; ++i) {
        if (indexMap.find(arr[i]) != indexMap.end()) {
            if (indexMap[arr[i]] < minIndex) {
                minIndex = indexMap[arr[i]];
                firstRepeating = arr[i];
            }
        } else {
            indexMap[arr[i]] = i + 1; // Using 1-based indexing
        }
    }

    return firstRepeating;
}

int main() {
    int n = 7;
    int arr[] = {1, 5, 3, 4, 3, 5, 6};

    int result = firstRepeatingElement(n, arr);
    cout << "Output: " << result << endl;

    return 0;
}

