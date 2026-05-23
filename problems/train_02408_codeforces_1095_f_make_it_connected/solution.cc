#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
vector<vector<long long>> edges;
long long par[N];
long long find(long long x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(long long x, long long y) {
  x = find(x);
  y = find(y);
  if (x != y) par[x] = y;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges.push_back({w, u, v});
  }
  long long root = min_element(a.begin(), a.end()) - a.begin();
  for (long long i = 0; i < n; i++) {
    if (i != root) edges.push_back({a[i] + a[root], root, i});
  }
  sort(edges.begin(), edges.end());
  for (long long i = 0; i < n; i++) par[i] = i;
  long long ans = 0;
  for (auto e : edges) {
    long long w = e[0], u = e[1], v = e[2];
    if (find(u) != find(v)) {
      ans += w;
      unite(u, v);
    }
  }
  cout << ans;
  return 0;
}
