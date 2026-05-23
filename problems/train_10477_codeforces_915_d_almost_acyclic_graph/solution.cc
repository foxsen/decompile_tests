#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[505], de[505];
vector<int> g[505];
queue<int> q;
void solve() {
  for (int i = 1; i <= n; i++) de[i] = d[i];
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      de[v]--;
      if (de[v] == 0) q.push(v);
    }
  }
  for (int i = 1; i <= n; i++)
    if (de[i] > 0) return;
  cout << "YES";
  exit(0);
}
void topsort() {
  for (int i = 1; i <= n; i++)
    if (d[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      d[v]--;
      if (d[v] == 0) q.push(v);
    }
  }
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    if (d[i] != 0) f = 0;
    if (d[i] == 1) {
      q.push(i);
      d[i]--;
      solve();
      d[i]++;
    }
  }
  if (f) {
    cout << "YES";
    exit(0);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[v].push_back(u);
    d[u]++;
  }
  topsort();
  cout << "NO";
  return 0;
}
