#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[3001];
int dis[3001];
bool visited[3001];
bool visited2[3001];
int par[3001];
bool dfs(int v, int p, queue<int>& q) {
  par[v] = p;
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] == p) continue;
    if (!visited[adj[v][i]]) {
      visited[adj[v][i]] = 1;
      if (dfs(adj[v][i], v, q)) return true;
    } else {
      dis[adj[v][i]] = 0;
      visited2[adj[v][i]] = 1;
      q.push(adj[v][i]);
      int l = v;
      while (l != adj[v][i]) {
        visited2[l] = 1;
        dis[l] = 0;
        q.push(l);
        l = par[l];
      }
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
    adj[i].clear();
    visited2[i] = 0;
  }
  int x, y;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  queue<int> q;
  visited[1] = 1;
  par[1] = -1;
  dfs(1, -1, q);
  int v;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < adj[v].size(); i++) {
      if (!visited2[adj[v][i]]) {
        visited2[adj[v][i]] = 1;
        q.push(adj[v][i]);
        dis[adj[v][i]] = dis[v] + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << dis[i] << " ";
}
