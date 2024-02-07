#include <iostream>
#include <queue>
using namespace std;

int minSteps(int N, int M, vector< vector<int> >& A, int X, int Y) {
    if (A[0][0] == 0 || A[X][Y] == 0) return -1; // Invalid start or end point

    vector<vector <int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    vector<vector <bool> > visited(N, vector<bool>(M, false));
    q.push({0, 0});
    visited[0][0] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == X && y == Y) return steps; // Reached destination

            for (auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && A[newX][newY] == 1 && !visited[newX][newY]) {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        steps++;
    }
    return -1; // Path not found
}

int main() {
    int N = 3;
    int M = 4;
    vector<vector<int>> A = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 1, 1}};
    int X = 2;
    int Y = 3;

    int result = minSteps(N, M, A, X, Y);
    cout << "Output: " << result << endl;

    return 0;
}

