#include <bits/stdc++.h>
#include <chrono>
#include <cstring>
using namespace std;
using namespace chrono;

const int MAX_NODE = 100;
bool graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE];

void dfs(int node, int nodes) {
    visited[node] = true;
    cout << node << " ";  // Process the current node

    // Visit all the unvisited neighbors
    for (int i = 1; i <= nodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, nodes);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    memset(graph, false, sizeof(graph));  // Initialize the graph to false

    // Reading the edges and building the graph
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        // Uncomment the next line for an undirected graph
        // graph[v][u] = true; 
    }

    int initial;
    cin >> initial;

    // Measure the time taken by DFS
    auto start = high_resolution_clock::now();
    memset(visited, false, sizeof(visited)); // Reset the visited array
    cout << "DFS Traversal starting from node " << initial << ": ";
    dfs(initial, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by DFS: " << duration.count() << " microseconds" << endl;

    return 0;
}
