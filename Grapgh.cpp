#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 6 // Maximum number of vertices

class Graph {
private:
    int V; // Number of vertices
    int adjMatrix[MAX][MAX]; // Adjacency matrix

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        // Initialize matrix to 0
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1; // For undirected graph
        adjMatrix[dest][src] = 1; // For bidirectional edges
    }

    // Function to display the adjacency matrix
    void display() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS)
    void DFS(int startVertex, vector<bool>& visited) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int i = 0; i < V; ++i) {
            if (adjMatrix[startVertex][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void DFSTraversal() {
        vector<bool> visited(V, false);
        cout << "Depth-First Traversal:" << endl;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
        cout << endl;
    }

    // Breadth-First Search (BFS)
    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        cout << "Breadth-First Traversal:" << endl;

        while (!queue.empty()) {
            int currentVertex = queue.front();
            cout << currentVertex << " ";
            queue.pop();

            for (int i = 0; i < V; ++i) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(6); // Create graph object with 6 vertices

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    cout << "Adjacency Matrix:" << endl;
    graph.display(); // Display the adjacency matrix

    // Perform DFS and BFS traversal
    graph.DFSTraversal();
    graph.BFS(0); // Start BFS from vertex 0

    return 0;
}

