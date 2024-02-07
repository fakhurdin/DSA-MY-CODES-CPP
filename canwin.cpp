#include <iostream>
#include <vector>
using namespace std;

bool canWin(vector<int>& nums, int start, int end, int p1Score, int p2Score, bool isP1Turn) {
    if (start > end) {
        return p1Score > p2Score; // Return true if Player 1 has higher score
    }

    if (isP1Turn) {
        // Player 1's turn, try both choices and check if there's any chance to win
        return canWin(nums, start + 1, end, p1Score + nums[start], p2Score, !isP1Turn) ||
               canWin(nums, start, end - 1, p1Score + nums[end], p2Score, !isP1Turn);
    } else {
        // Player 2's turn, simulate Player 2's choices
        return canWin(nums, start + 1, end, p1Score, p2Score + nums[start], !isP1Turn) &&
               canWin(nums, start, end - 1, p1Score, p2Score + nums[end], !isP1Turn);
    }
}

bool canWinGame(vector<int>& nums) {
    int size = nums.size();
    return canWin(nums, 0, size - 1, 0, 0, true);
}

int main() {
    vector<int> nums = {1, 5, 2};
    cout << "Output: " << (canWinGame(nums) ? "true" : "false") << endl;
    return 0;
}

