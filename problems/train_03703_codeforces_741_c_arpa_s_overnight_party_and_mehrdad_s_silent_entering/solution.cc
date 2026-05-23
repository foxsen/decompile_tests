#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g;
vector<int> col;
void dfs(int v, int c) {
  if (-1 == v) {
    return;
  }
  if (-1 != col[v]) {
    return;
  }
  col[v] = c + 1;
  dfs(g[v].first, c ^ 1);
  dfs(g[v].second, c ^ 1);
}
int main() {
  int n;
  cin >> n;
  g.assign(2 * n, make_pair(-1, -1));
  col.assign(2 * n, -1);
  vector<pair<int, int>> ids;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    ids.push_back(make_pair(a, b));
    g[a].first = b;
    g[b].first = a;
    g[2 * i].second = 2 * i + 1;
    g[2 * i + 1].second = 2 * i;
  }
  for (int i = 0; i < 2 * n; ++i) {
    if (-1 == col[i]) {
      dfs(i, 0);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << col[ids[i].first] << ' ' << col[ids[i].second] << '\n';
  }
  return 0;
}
