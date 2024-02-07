#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minStepsKnight(int N, vector<int>& knightPos, vector<int>& targetPos) {
    vector<vector<int>> directions = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{knightPos[0] - 1, knightPos[1] - 1}, 0});
    visited[knightPos[0] - 1][knightPos[1] - 1] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second;

        if (x == targetPos[0] - 1 && y == targetPos[1] - 1) {
            return steps;
        }

        for (auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
            }
        }
    }
    return -1; // Target position not reachable
}

int main() {
    int N = 6;
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};

    int result = minStepsKnight(N, knightPos, targetPos);
    cout << "Output: " << result << endl;

    return 0;
}

