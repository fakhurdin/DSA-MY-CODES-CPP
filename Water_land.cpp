#include <iostream>
#include <vector>
using namespace std;

void DFS(int i, int j, vector<vector <int> >& grid, int rows, int cols) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != 1) {
        return;
    }

    grid[i][j] = 0; // Mark the current land as visited

    // Check in all eight directions
    DFS(i + 1, j, grid, rows, cols);
    DFS(i - 1, j, grid, rows, cols);
    DFS(i, j + 1, grid, rows, cols);
    DFS(i, j - 1, grid, rows, cols);
    DFS(i + 1, j + 1, grid, rows, cols);
    DFS(i + 1, j - 1, grid, rows, cols);
    DFS(i - 1, j + 1, grid, rows, cols);
    DFS(i - 1, j - 1, grid, rows, cols);
}

int countIslands(vector<vector <int> >& grid) {
    int rows = grid.size();
    if (rows == 0) {
        return 0;
    }
    int cols = grid[0].size();
    int islands = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                islands++;
                DFS(i, j, grid, rows, cols);
            }
        }
    }

    return islands;
}

int main() {
    vector<vector <int> > grid = {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, 0}
    };

    int islands = countIslands(grid);
    cout << "Output: " << islands << endl;

    return 0;
}

