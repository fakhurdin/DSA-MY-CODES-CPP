#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minSwapsToSort(vector<int>& nums) {
    int n = nums.size();
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; ++i) {
        indexMap[nums[i]] = i;
    }

    int swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != sortedNums[i]) {
            swaps++;

            int index = indexMap[sortedNums[i]];
            swap(nums[i], nums[index]);
            indexMap[nums[index]] = index;
        }
    }

    return swaps;
}

int main() {
    vector<int> nums = {2, 8, 5, 4};
    int minSwaps = minSwapsToSort(nums);
    cout << "Output: " << minSwaps << endl;

    return 0;
}

