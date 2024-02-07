#include <iostream>
#include <vector>
using namespace std;

void countFrequencies(int N, vector<int>& arr, int P) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] <= N) {
            arr[arr[i] - 1] += P;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << arr[i] / P << " ";
    }
    cout << endl;
}

int main() {
    int N = 5;
    vector<int> arr = {2, 3, 2, 3, 5};
    int P = 5;

    countFrequencies(N, arr, P);

    return 0;
}

