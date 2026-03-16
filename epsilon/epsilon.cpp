#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int MAX_NODE = 100;
bool graph[MAX_NODE][MAX_NODE];  
bool visited[MAX_NODE]; 
void dfs(int node, int nodes) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 1; i <= nodes; i++) {
        if (graph[node][i] && !visited[i]) {
   dfs(i, nodes);
        }
    }
}
void bfs(int start, int nodes) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; 
        for (int i = 1; i <= nodes; i++) {
   if (graph[node][i] && !visited[i]) {
   visited[i] = true;
 q.push(i);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;  
    memset(graph, false, sizeof(graph)); 
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
    }

    int initial;
    cin >> initial; 
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
       cout << "BFS";
            bfs(initial, n);  
            break;
        case 2:
            cout << "DFS";
      memset(visited, false, sizeof(visited));
            dfs(initial, n);  
            break;
        default:
            cout << "er" << endl;
            break;
    }
    cout << endl;
    return 0;
}
