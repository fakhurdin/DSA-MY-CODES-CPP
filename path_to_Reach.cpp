#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool isPath(int x, int y, vector<vector<int> >& grid, vector<vector <bool> >& visited, int n) {
    if (!isSafe(x, y, n) || grid[x][y] == 0 || visited[x][y])
        return false;

    if (grid[x][y] == 2)
        return true;

    visited[x][y] = true;

    // Check in all four directions
    if (isPath(x + 1, y, grid, visited, n) ||
        isPath(x - 1, y, grid, visited, n) ||
        isPath(x, y + 1, grid, visited, n) ||
        isPath(x, y - 1, grid, visited, n)) {
        return true;
    }

    return false;
}

bool isPathExists(vector <vector <int> >& grid) {
    int n = grid.size();
    vector<vector <bool> > visited(n, vector<bool>(n, false));
    int sourceX = -1, sourceY = -1;

    // Finding the source coordinates
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                sourceX = i;
                sourceY = j;
                break;
            }
        }
    }

    // If source not found
    if (sourceX == -1 || sourceY == -1)
        return false;

    return isPath(sourceX, sourceY, grid, visited, n);
}

int main() {
    vector<vector <int> > grid = {
        {3, 0, 3, 0, 0},
        {3, 0, 0, 0, 3},
        {3, 3, 3, 3, 3},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 1, 3}
    };

    if (isPathExists(grid))
        cout << "Output: 1\n";
    else
        cout << "Output: 0\n";

    return 0;
}

