#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

void dijkstra(int graph[100][100], int n, int start) {
    int dist[n];       // Stores shortest distances from the source
    bool visited[n];   // Tracks visited vertices

    // Initialize all distances as "infinity" and all vertices as unvisited
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0; // Distance to the source is 0

    // Loop to find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum distance that is not yet processed
        int u = -1, minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // If no unvisited vertex is reachable, stop

        visited[u] = true; // Mark the vertex as processed

        // Update distances of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int n, start;
    int graph[100][100];

    cout << "Enter the number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    dijkstra(graph, n, start);

    return 0;
}
