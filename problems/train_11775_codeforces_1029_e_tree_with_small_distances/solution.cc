#include <bits/stdc++.h>
using namespace std;
int n, ans, d[200010], p[200010];
vector<vector<int> > gr;
void dfs(int x, int par) {
  p[x] = par;
  if (par != -1) {
    d[x] = d[par] + 1;
  }
  for (auto j : gr[x]) {
    if (j == par) {
      continue;
    }
    dfs(j, x);
  }
}
set<pair<int, int> > pajestegreedy;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  vector<int> vi;
  gr.resize(n, vi);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    if (d[i] > 2) pajestegreedy.insert({-d[i], i});
  }
  while (!pajestegreedy.empty()) {
    int x = pajestegreedy.begin()->second;
    x = p[x];
    if (pajestegreedy.find({-d[x], x}) != pajestegreedy.end())
      pajestegreedy.erase({-d[x], x});
    for (auto i : gr[x]) {
      if (pajestegreedy.find({-d[i], i}) != pajestegreedy.end()) {
        pajestegreedy.erase({-d[i], i});
      }
    }
    ++ans;
  }
  cout << ans;
}
