#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int prev, vector<vector<int>>& adj, vector<vector<int>>& col,
         vector<int>& dist) {
  int nxt;
  for (int i = 0; i < adj[node].size(); i++) {
    nxt = adj[node][i];
    if (nxt != prev) {
      dist[nxt] = dist[node] + col[node][i];
      dfs(nxt, node, adj, col, dist);
    }
  }
}
int main() {
  long long n, u, v, c;
  cin >> n;
  vector<vector<int>> adj(n), col(n);
  vector<int> dist(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> c;
    adj[u].push_back(v);
    adj[v].push_back(u);
    col[u].push_back(c);
    col[v].push_back(c);
  }
  dist[0] = 0;
  dfs(0, -1, adj, col, dist);
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (dist[root] < dist[i]) {
      root = i;
    }
  }
  cout << dist[root] << "\n";
}
