#include <bits/stdc++.h>
using namespace std;
const int INF = 1000001000;
const long long INFL = 2000000000000001000;
int solve();
int main() {
  srand(2317);
  cout.precision(10);
  cout.setf(ios::fixed);
  int tn = 1;
  for (int i = 0; i < tn; ++i) solve();
}
const int maxn = 2e5;
vector<int> g[maxn];
bool del[maxn];
int bamboo[maxn];
bool type2[maxn];
queue<int> o;
int solve() {
  int n;
  cin >> n;
  for (int i = 0; i < int(n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < int(n); ++i)
    if (((int)(g[i]).size()) == 1) o.push(i);
  while (!o.empty()) {
    int u = o.front();
    del[u] = true;
    o.pop();
    for (int v : g[u]) {
      if (del[v]) continue;
      if (((int)(g[v]).size()) == 2)
        o.push(v);
      else
        ++bamboo[v];
    }
  }
  bool fail = false;
  for (int i = 0; i < int(n); ++i) {
    if (del[i]) continue;
    if (((int)(g[i]).size()) <= 3 && ((int)(g[i]).size()) <= bamboo[i] + 1)
      type2[i] = true;
  }
  for (int i = 0; i < int(n); ++i) {
    if (type2[i] || del[i]) continue;
    int deg = 0;
    for (int v : g[i])
      if (!type2[v] && !del[v]) ++deg;
    if (deg > 2) fail = true;
  }
  if (fail)
    cout << "No\n";
  else
    cout << "Yes\n";
  return 0;
}
