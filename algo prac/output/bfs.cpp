#include<bits/stdc++.h>
#include<string>
#include<cstring>
using namespace std;
const int MAX_NODE=100;
bool graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE];
void bfs(int start, int nodes) {
    memset(visited, false, sizeof(visited)); // Initialize visited array to false
    queue<int>q;                            // Queue for BFS

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " "; // Process the current node

        for (int i = 1; i <= nodes; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    memset(graph,false,sizeof(graph));
    for(int i=0;i<e;i++){
    int u,v;
    cin >> u >> v;
    graph[u][v] = true;
    graph[u][v] = true;// for dirceted
  
    }
      int inital;
    cin >> inital;
    bfs(inital,graph);
  return 0;

}