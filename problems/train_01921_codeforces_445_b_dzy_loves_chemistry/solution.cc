#include <bits/stdc++.h>
using namespace std;
int V, E, u, v;
array<vector<int>, 51> graph;
bool marked[51];
void dfs(int u) {
  marked[u] = true;
  for (auto& v : graph[u]) {
    if (!marked[v]) dfs(v);
  }
}
int main() {
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int CC = 0;
  for (int i = 1; i <= V; i++) {
    if (!marked[i]) {
      dfs(i);
      CC++;
    }
  }
  cout.setf(ios::fixed);
  cout << setprecision(0);
  cout << pow(2, V - CC) << "\n";
  return 0;
}
