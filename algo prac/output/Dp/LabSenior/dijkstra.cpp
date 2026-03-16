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
        cout << i + 1 << "\t" << dist[i] << "\n";
    }
}

int main() {
    int n, e;
    int graph[100][100] = {0};  // Initialize the graph matrix with 0 (no edges initially)

    // Input the number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter the edges (u, v, weight) format:" << endl;
    // Input the edges and their weights
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u - 1][v - 1] = weight;  // Adjust for 0-based index
    }

    int start;
    cout << "Enter the starting vertex (1-indexed): ";
    cin >> start;
    start -= 1;  // Convert to 0-based index

    // Call Dijkstra's algorithm
    dijkstra(graph, n, start);

    return 0;
}
/*### Explanation of Dijkstra's Algorithm for Single Source Shortest Path

Dijkstra's algorithm is a well-known algorithm used to find the shortest paths between a source node and all other nodes in a weighted graph. It works with graphs that have non-negative edge weights. The key idea is to progressively find the closest node to the source and update the distances of its neighbors. Here's a step-by-step breakdown of the code and the underlying algorithm.

### Problem Overview:

- **Input**:
  - A directed, weighted graph is given.
  - The graph consists of `V` vertices (nodes) and `E` edges.
  - We are given the weights of edges between vertices.
  - The goal is to compute the shortest distance from a given source vertex to all other vertices.

- **Output**:
  - The shortest distance from the source vertex to every other vertex in the graph.

### Approach:

1. **Graph Representation**:
   - We represent the graph using a 2D array (adjacency matrix). The element `graph[u][v]` represents the weight of the edge from vertex `u` to vertex `v`. If there is no direct edge between two vertices, we will initialize the value with 0 (or infinity if desired).

2. **Dijkstra’s Algorithm**:
   - **Initialization**:
     - We create a `dist[]` array, which will store the shortest distance from the source vertex to all other vertices. Initially, all distances are set to infinity (`INT_MAX`), except for the source vertex which is set to 0.
     - We create a `visited[]` array to keep track of which vertices have been processed.

   - **Main Logic**:
     - We iteratively choose the vertex with the smallest known distance that has not been visited yet. This is the "greedy" part of the algorithm, where we always expand the closest node first.
     - For the chosen vertex, we update the distances of its neighbors. If a shorter path to a neighbor is found, we update the `dist[]` value for that neighbor.
     - We repeat this process until all vertices are visited.

   - **Final Output**:
     - Once all vertices are processed, the `dist[]` array will contain the shortest distances from the source to each vertex.

### Key Steps in the Algorithm:

1. **Initialization**:
   - The `dist[]` array is initialized to infinity (`INT_MAX`), except for the source node which is initialized to 0.
   - The `visited[]` array keeps track of which vertices have already been processed.
   
2. **Greedy Selection of the Minimum Distance Node**:
   - In each iteration, we select the unvisited vertex with the smallest distance value. This ensures that we are always expanding the closest node to the source.
   
3. **Relaxation**:
   - For the chosen vertex, we update the distances to its adjacent vertices. This is known as "relaxing" the edges: if we find a shorter path to a vertex through the current vertex, we update its distance.

4. **Termination**:
   - The algorithm terminates when all vertices have been processed. At this point, the `dist[]` array contains the shortest distance from the source to every other vertex.

### Example Walkthrough:

Consider the following sample graph:

```
3 3
1 2 10
1 3 60
2 3 40
```

- This means:
  - There are 3 vertices (1, 2, 3) and 3 edges.
  - Edge 1 -> 2 has a weight of 10.
  - Edge 1 -> 3 has a weight of 60.
  - Edge 2 -> 3 has a weight of 40.

Let's assume that the starting vertex is **1**.

### Step-by-Step Process:

1. **Initialization**:
   - `dist[] = {0, INT_MAX, INT_MAX}` (distance to source vertex 1 is 0, other distances are infinity).
   - `visited[] = {false, false, false}` (no vertex has been visited yet).

2. **First Iteration**:
   - The source vertex is **1**, and its distance is 0. We mark vertex 1 as visited.
   - We check its neighbors:
     - Vertex 2 can be reached with a distance of 10 (since `dist[1] + graph[1][2] = 0 + 10 = 10`).
     - Vertex 3 can be reached with a distance of 60 (since `dist[1] + graph[1][3] = 0 + 60 = 60`).
   - So, the updated `dist[] = {0, 10, 60}`.

3. **Second Iteration**:
   - The unvisited vertex with the minimum distance is **2** (distance = 10).
   - We mark vertex 2 as visited.
   - We check its neighbors:
     - Vertex 3 can be reached through vertex 2 with a distance of 50 (`dist[2] + graph[2][3] = 10 + 40 = 50`), which is shorter than 60.
   - So, the updated `dist[] = {0, 10, 50}`.

4. **Third Iteration**:
   - The remaining unvisited vertex is **3** (distance = 50).
   - We mark vertex 3 as visited, but there are no more neighbors to process.

5. **Final Output**:
   - The shortest distances from the source vertex 1 to all other vertices are:
     - Vertex 1: Distance = 0
     - Vertex 2: Distance = 10
     - Vertex 3: Distance = 50

### Code Explanation:

```cpp
#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

void dijkstra(int graph[100][100], int n, int start) {
    int dist[n];       // Stores shortest distances from the source
    bool visited[n];   // Tracks visited vertices

    // Initialize all distances as "infinity" and all vertices as unvisited
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;    // Initially, all distances are set to infinity
        visited[i] = false;   // No vertex is visited initially
    }

    dist[start] = 0; // Distance to the source is 0

    // Loop to find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = -1, minDist = INT_MAX;
        
        // Find the unvisited vertex with the minimum distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // If no unvisited vertex is reachable, stop

        visited[u] = true; // Mark vertex u as visited

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << dist[i] << "\n";
    }
}

int main() {
    int n, e;
    int graph[100][100] = {0};  // Initialize the graph matrix with 0 (no edges initially)

    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter the edges (u, v, weight) format:" << endl;
    // Input the edges and their weights
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u - 1][v - 1] = weight;  // Adjust for 0-based index
    }

    int start;
    cout << "Enter the starting vertex (1-indexed): ";
    cin >> start;
    start -= 1;  // Convert to 0-based index

    // Call Dijkstra's algorithm
    dijkstra(graph, n, start);

    return 0;
}
```

### Summary:
- Dijkstra's algorithm is a greedy algorithm to find the shortest paths from a source node to all other nodes in a graph with non-negative edge weights.
- The key idea is to iteratively select the vertex with the smallest known distance and update the distances of its neighbors.
*/