#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int n, m, k;
bool us[2222];
vector<vector<int> > gr;
bool dead[2222];
int ans[2222];
bool dfs(int v, int aim) {
  if (v == aim) return true;
  us[v] = true;
  bool flag = false;
  for (int i = 0; i < (int)gr[v].size(); i++) {
    if (!us[gr[v][i]]) {
      if (dfs(gr[v][i], aim)) {
        dead[gr[v][i]] = true;
        flag = true;
      }
    }
  }
  return flag;
}
int root(vector<int> &g, int v) {
  if (g[v] == v) return v;
  g[v] = root(g, g[v]);
  return g[v];
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  vector<int> v(n);
  gr = vector<vector<int> >(n);
  for (int i = 0; i < n; i++) {
    v[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    gr[from].push_back(to);
    gr[to].push_back(from);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    dfs(from, to);
    for (int i = 0; i < n + 1; i++) us[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!dead[i]) {
      for (int j = 0; j < (int)gr[i].size(); j++) {
        if (!dead[gr[i][j]]) {
          if (rand() & 1) {
            v[root(v, i)] = root(v, gr[i][j]);
          } else {
            v[root(v, gr[i][j])] = root(v, i);
          }
        }
      }
    }
  }
  int max = 0;
  for (int i = 0; i < n; i++) {
    ans[root(v, i)]++;
    if (ans[root(v, i)] > max) {
      int j;
      for (j = 0; j < (int)gr[i].size(); j++) {
        if (root(v, gr[i][j]) != root(v, i)) {
          break;
        }
      }
      if (j == (int)gr[i].size()) {
        max = ans[root(v, i)];
      }
    }
  }
  cout << max << endl;
  return 0;
}
