#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortDFS(int node, vector<int>& visited, vector<vector<int> >& graph, stack<int>& order) {
    visited[node] = 1;

    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            topologicalSortDFS(neighbor, visited, graph, order);
        }
    }

    order.push(node);
}

vector<int> topologicalSort(int V, vector<vector<int>>& graph) {
    vector<int> visited(V, 0);
    stack<int> order;

    for (int i = 0; i < V; ++i) {
        if (visited[i] == 0) {
            topologicalSortDFS(i, visited, graph, order);
        }
    }

    vector<int> result;
    while (!order.empty()) {
        result.push_back(order.top());
        order.pop();
    }

    return result;
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> graph = {
        {1, 2},    // Edge from 0 to 1 and 2
        {2, 3},
        {4},
        {4, 5},
        {},
        {}
    };

    vector<int> result = topologicalSort(V, graph);
    cout << "Output: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

