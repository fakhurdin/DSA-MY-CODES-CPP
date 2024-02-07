#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
public:
    Graph(int V, int E, vector<pair<int, int>> edges) {
        this->V = V;
        this->E = E;
        this->adjList.resize(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    vector<vector<int>> getAdjacencyList() {
        return adjList;
    }

private:
    int V;
    int E;
    vector<vector<int>> adjList;
};

int main() {
    int V = 5;
    int E = 7;
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};

    Graph graph(V, E, edges);

    vector<vector<int>> adjList = graph.getAdjacencyList();

    for (int i = 0; i < V; i++) {
        cout << "{";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << ", ";
        }
        cout << "}" << endl;
    }

    return 0;
}

