#include <iostream>
#include <cstring> // For memset
using namespace std;

void bfs(int graph[][100], int n, int start) {
    bool visited[n];   // To track visited nodes
    memset(visited, false, sizeof(visited)); // Initialize visited array to false

    int bfsArray[n];    // Array to simulate a queue
    int front = 0, rear = 0;

    // Start with the given node
    bfsArray[rear++] = start;
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (front < rear) {
        // Dequeue the front element
        int current = bfsArray[front++];
        cout << current << " ";

        // Enqueue all unvisited neighbors of the current node
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                bfsArray[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, start;
    
    cout << "Enter the number of nodes: ";
    cin >> n;

    int graph[100][100]; // Adjacency matrix

    cout << "Enter the adjacency matrix (size " << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting node: ";
    cin >> start;

    bfs(graph, n, start);

    return 0;
}
