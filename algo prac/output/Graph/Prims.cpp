#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

// Function to find the vertex with the minimum key value, not yet included in MST
int findMinKey(int key[], bool mstSet[], int n) {
    int minKey = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
    }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[][100], int n) {
    cout << "Edge\tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Prim's Algorithm
void primMST(int graph[][100], int n) {
    int parent[n];    // Array to store constructed MST
    int key[n];       // Key values used to pick the minimum weight edge
    bool mstSet[n];   // To represent the set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;       // Make key 0 so that this vertex is picked first
    parent[0] = -1;   // First node is the root of MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = findMinKey(key, mstSet, n);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        // Update the key value and parent index of adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            // Update key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print the constructed MST
    printMST(parent, graph, n);
}
int main() {
    int n;
    // Input the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100]; // Adjacency matrix to represent the graph

    // Input the graph as an adjacency matrix
    cout << "Enter the adjacency matrix (size " << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Run Prim's algorithm
    primMST(graph, n);

    return 0;
}
