#include <iostream>

// Only iostream library allowed
using std::cout;
using std::endl;

// Adjacency list representation of a graph
typedef struct {
    int arr[13][3] = {{1, 4, 7}, {4, 5, 6}, {7, 8, 11}, {5}, {6, 9}, {11, 10, 12}, {10}, {2, 3}, {3, 9}, {12}, {2}};
    int operator[](int i) const { return arr[i][0]; }
} Graph;

// Mark a node as visited
void markVisited(Graph& graph, int node) {
    graph.arr[node][node] = 1;
}

// Check if a node is visited
bool isVisited(Graph& graph, int node) {
    return graph.arr[node][node] == 1;
}

// Depth-first search traversal
void dfs(Graph& graph, int node) {
    // Mark the node as visited
    markVisited(graph, node);

    // Recursively traverse all the adjacent nodes
    for (int i = 0; i < 3; ++i) {
        int neighbor = graph[node];
        if (neighbor != 0 && !isVisited(graph, neighbor)) {
            dfs(graph, neighbor);
        }
        graph[++node];
    }
}

// Breadth-first search traversal
void bfs(Graph& graph, int node) {
    // Create a queue to store the nodes to be visited
    int queue[13];
    int front = 0, rear = 0;

    // Add the starting node to the queue
    queue[rear++] = node;

    // While the queue is not empty
    while (front != rear) {
        // Get the current node from the queue
        int currentNode = queue[front++];
        
        // Mark the current node as visited
        markVisited(graph, currentNode);

        // Add all the adjacent nodes of the current node to the queue
        for (int i = 0; i < 3; ++i) {
            int neighbor = graph.arr[currentNode][i];
            if (neighbor != 0 && !isVisited(graph, neighbor)) {
                queue[rear++] = neighbor;
            }
        }
    }
}

// Print the nodes visited in a DFS or BFS traversal
void printTraversal(Graph& graph, int node, std::string traversalType) {
    cout << traversalType << " traversal: ";

    // If DFS, recursively print all the adjacent nodes
    if (traversalType == "DFS") {
        dfs(graph, node);
    }
    // If BFS, use a queue to print all the nodes in the graph
    else if (traversalType == "BFS") {
        bfs(graph, node);
    }

    // Print all the visited nodes
    for (int i = 0; i < 13; ++i) {
        if (isVisited(graph, i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    // Create the graph
    Graph graph;

    // Print the DFS and BFS traversals
    printTraversal(graph, 0, "DFS");
    printTraversal(graph, 0, "BFS");

    return 0;
}

