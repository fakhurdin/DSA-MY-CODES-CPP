#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findPairs(vector<int>& arr) {
    unordered_map<int, pair<int, int>> sumMap;

    int n = arr.size();
    bool found = false;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = arr[i] + arr[j];

            if (sumMap.find(sum) != sumMap.end()) {
                pair<int, int> p = sumMap[sum];
                cout << "(" << p.first << ", " << p.second << ") and (" << arr[i] << ", " << arr[j] << ")" << endl;
                found = true;
                break;
            } else {
                sumMap[sum] = make_pair(arr[i], arr[j]);
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        cout << "No pairs found" << endl;
    }
}

int main() {
    vector<int> arr1 = {3, 4, 7, 1, 2, 9, 8};
    cout << "Output for input {3, 4, 7, 1, 2, 9, 8}:" << endl;
    findPairs(arr1);

    vector<int> arr2 = {3, 4, 7, 1, 12, 9};
    cout << "\nOutput for input {3, 4, 7, 1, 12, 9}:" << endl;
    findPairs(arr2);

    vector<int> arr3 = {65, 30, 7, 90, 1, 9, 8};
    cout << "\nOutput for input {65, 30, 7, 90, 1, 9, 8}:" << endl;
    findPairs(arr3);

    return 0;
}

