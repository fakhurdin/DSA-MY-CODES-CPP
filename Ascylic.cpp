#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct Map {
    int key;
    string name;
    bool boss;
    int cost;
    Map(int k, string n, bool b, int c) : key(k), name(n), boss(b), cost(c) {}
};

class GameMap {
private:
    int totalMaps;
    unordered_map<int, Map*> mapDetails;
    vector<vector<int>> adjacencyMatrix;

public:
    GameMap(int n) : totalMaps(n), adjacencyMatrix(n, vector<int>(n, 0)) {}

    void addMapDetails(int key, const string& name, bool boss, int cost) {
        Map* newMap = new Map(key, name, boss, cost);
        mapDetails[key] = newMap;
    }

    void addEdge(int from, int to) {
        adjacencyMatrix[from][to] = 1; // Adding directed edge from 'from' to 'to'
    }

    vector<int> getOptimalPath() {
        vector<int> indegree(totalMaps, 0);

        for (int i = 0; i < totalMaps; ++i) {
            for (int j = 0; j < totalMaps; ++j) {
                indegree[j] += adjacencyMatrix[i][j];
            }
        }

        queue<int> q;
        for (int i = 0; i < totalMaps; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> optimalPath;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            optimalPath.push_back(current);

            for (int i = 0; i < totalMaps; ++i) {
                if (adjacencyMatrix[current][i] == 1) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }

        return optimalPath;
    }

    void displayMapDetails(const vector<int>& optimalPath) {
        cout << "Optimal path to win the game: ";
        for (int i = 0; i < optimalPath.size(); ++i) {
            cout << "[" << mapDetails[optimalPath[i]]->key << "] ";
        }
        cout << endl;

        int totalCost = 0;
        cout << "Total cost: ";
        for (int i = 0; i < optimalPath.size(); ++i) {
            totalCost += mapDetails[optimalPath[i]]->cost;
        }
        cout << totalCost << endl;
    }
};

int main() {
    int totalMaps = 6; // Change this according to the number of maps

    GameMap game(totalMaps);

    // Adding map details
    game.addMapDetails(0, "The Forest", true, 1);
    game.addMapDetails(1, "Desert Oasis", false, 2);
    game.addMapDetails(2, "Snowy Peaks", false, 3);
    game.addMapDetails(3, "Abandoned City", true, 5);
    game.addMapDetails(4, "Volcano Base", true, 11);
    game.addMapDetails(5, "Sand Dunes", true, 5);

    // Creating connections between maps
    game.addEdge(0, 1);
    game.addEdge(0, 2);
    game.addEdge(1, 3);
    game.addEdge(2, 3);
    game.addEdge(0, 4);
    game.addEdge(3, 5);
    game.addEdge(4, 5);

    vector<int> optimalPath = game.getOptimalPath();
    game.displayMapDetails(optimalPath);

    return 0;
}

