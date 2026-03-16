#include <iostream>
#include <cstring> // For memset
using namespace std;

void dfs(int graph[][100], int n, int start, bool visited[]) {
    cout << start << " ";
    visited[start] = true;

    // Visit all unvisited neighbors
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}

int main() {
    int n, start;

    cout << "Enter the number of nodes: ";
    cin >> n;

    int graph[100][100]; // Adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting node: ";
    cin >> start;

    bool visited[n];
    memset(visited, false, sizeof(visited)); // Initialize visited array to false

    cout << "DFS Traversal: ";
    dfs(graph, n, start, visited);
    cout << endl;

    return 0;
}
