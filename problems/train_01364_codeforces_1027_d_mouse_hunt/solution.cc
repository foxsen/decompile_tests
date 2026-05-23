#include <bits/stdc++.h>
using namespace std;
inline void prep() {
  cin.tie(0);
  cin.sync_with_stdio(0);
};
const int mod = (int)1e9 + 7;
const int MX = (int)2e5 + 20;
int mn[MX];
vector<int> g[MX], comp_g[MX];
int pre[MX];
int low[MX];
int id[MX];
stack<int> stk;
int cntr, scc;
void tarjan(int x) {
  if (pre[x] != -1) return;
  stk.push(x);
  pre[x] = cntr++;
  low[x] = pre[x];
  for (auto& y : g[x]) {
    if (pre[y] == -1) tarjan(y);
    low[x] = min(low[x], low[y]);
  }
  if (pre[x] == low[x]) {
    while (true) {
      int y = stk.top();
      stk.pop();
      low[y] = MX;
      id[y] = scc;
      if (y == x) break;
    }
    scc++;
  }
}
int main() {
  prep();
  int n;
  cin >> n;
  int c[n];
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    mn[i] = (int)2e9;
  }
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    g[i].push_back(--x);
  }
  memset(pre, 0xff, sizeof pre);
  memset(id, 0xff, sizeof id);
  for (int i = 0; i < n; ++i) {
    tarjan(i);
  }
  for (int i = 0; i < n; ++i) {
    mn[id[i]] = min(mn[id[i]], c[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (auto& x : g[i]) {
      if (id[x] != id[i]) comp_g[id[i]].push_back(id[x]);
    }
  }
  int res = 0;
  for (int i = 0; i < scc; ++i) {
    if (comp_g[i].size() == 0) res += mn[i];
  }
  cout << res << '\n';
  return 0;
}
