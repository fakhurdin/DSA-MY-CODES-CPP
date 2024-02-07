#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

vector<int> kClosestNeighbors(int N, int X, int K, int a[]) {
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < K; ++i) {
        int diff = abs(X - a[i]);
        maxHeap.push({diff, a[i]});
    }

    for (int i = K; i < N; ++i) {
        int diff = abs(X - a[i]);
        if (diff < maxHeap.top().first) {
            maxHeap.pop();
            maxHeap.push({diff, a[i]});
        }
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    // Reversing the result to get closest neighbors in ascending order
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int N1 = 5, X1 = 0, K1 = 4;
    int arr1[] = {-21, 21, 4, -12, 20};

    vector<int> result1 = kClosestNeighbors(N1, X1, K1, arr1);
    cout << "Output for input {N = 5, X = 0, K = 4}:" << endl;
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    int N2 = 6, X2 = 5, K2 = 3;
    int arr2[] = {10, 2, 14, 4, 7, 6};

    vector<int> result2 = kClosestNeighbors(N2, X2, K2, arr2);
    cout << "\nOutput for input {N = 6, X = 5, K = 3}:" << endl;
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

