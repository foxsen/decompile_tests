#include <bits/stdc++.h>
using namespace std;
int n, m, end_dag = -1;
vector<vector<int> > e;
vector<char> visited;
vector<int> sorted;
vector<int> dist;
vector<int> p;
int max_len = 0;
int max_t = 0;
void toposort(int u) {
  visited[u] = 't';
  for (int i = 0; i < e[u].size(); i++) {
    if (visited[e[u][i]] == 'f') {
      toposort(e[u][i]);
    }
  }
  sorted.push_back(u);
}
int main() {
  cin >> n >> m;
  visited.assign(n + 1, 'f');
  dist.assign(n + 1, 0);
  e.resize(n + 1);
  p.assign(n + 1, -1);
  int u, v;
  map<pair<int, int>, int> t;
  for (size_t i = 0; i < m; i++) {
    cin >> u >> v;
    e[u].push_back(v);
    t[make_pair(u, v)] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 'f') {
      toposort(i);
    }
  }
  for (int i = sorted.size() - 1; i >= 0; i--) {
    for (int j = 0; j < e[sorted[i]].size(); j++) {
      if (dist[e[sorted[i]][j]] < dist[sorted[i]] + 1) {
        dist[e[sorted[i]][j]] = dist[sorted[i]] + 1;
        p[e[sorted[i]][j]] = sorted[i];
        if (dist[e[sorted[i]][j]] >= max_len) {
          max_len = dist[e[sorted[i]][j]];
          if (max_len == n - 1) {
            end_dag = e[sorted[i]][j];
          }
        }
      }
    }
  }
  if (end_dag != -1) {
    int vrt = end_dag;
    while (vrt != -1) {
      if (t[make_pair(p[vrt], vrt)] > max_t) {
        max_t = t[make_pair(p[vrt], vrt)];
      }
      vrt = p[vrt];
    }
  }
  if (max_len < n - 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << max_t << endl;
  return 0;
}
