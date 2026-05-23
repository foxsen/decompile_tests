#include <bits/stdc++.h>
using namespace std;
vector<int> V;
vector<int> E[200005];
int d[200005];
int p[200005];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void meld(int x, int y) {
  x = find(x), y = find(y);
  p[x] = y;
}
int s, t;
void build() {
  fill(begin(d), end(d), 1e9);
  queue<int> Q;
  for (auto x : V) Q.emplace(x), d[x] = 0;
  while (!Q.empty()) {
    auto x = Q.front();
    Q.pop();
    for (auto y : E[x]) {
      if (d[y] == 1e9) d[y] = d[x] + 1, Q.emplace(y);
    }
  }
}
int n, m, k;
bool test(int mid) {
  iota(begin(p), end(p), 0);
  for (int x = 1; x <= n; ++x)
    for (auto y : E[x])
      if (d[x] + d[y] + 1 <= mid) meld(x, y);
  return find(s) == find(t);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    V.push_back(x);
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  cin >> s >> t;
  if (find(begin(V), end(V), t) == end(V)) V.push_back(t);
  build();
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (test(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (test(l))
    cout << l << endl;
  else
    cout << -1 << endl;
  return 0;
}
