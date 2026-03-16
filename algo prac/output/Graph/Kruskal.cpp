#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Find function to determine the parent of an element in a disjoint set
int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);  // Path compression
}

// Union function to merge two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Compare function to sort edges by weight
bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskal(int V, int E, Edge edges[]) {
    // Sort edges by weight
    sort(edges, edges + E, compare);

    // Initialize parent and rank arrays for union-find
    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;  // Initially, each node is its own parent
        rank[i] = 0;    // Initially, rank is 0 for each node
    }

    // Process edges and build the MST
    cout << "Edges in the MST:" << endl;
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(parent, u) != find(parent, v)) {
            // If they are in different sets, include this edge in MST
            cout << u << " - " << v << " : " << edges[i].weight << endl;
            unionSets(parent, rank, u, v);  // Merge the sets
        }
    }
}

int main() {
    int V, E;

    // Get the number of vertices and edges from the user
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create an array to store edges
    Edge edges[E];

    // Get edge details (source, destination, weight) from the user
    cout << "Enter the edges (src, dest, weight):" << endl;
    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Call Kruskal’s algorithm
    kruskal(V, E, edges);

    return 0;
}
