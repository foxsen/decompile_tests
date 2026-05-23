#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > h;
vector<vector<long long> > g;
long long p[500001][21];
long long volume[500001];
long long n, ans, s, f;
void dfs(long long v, long long m) {
  p[v][0] = m;
  for (long long i = 0; i < g[v].size(); i++) {
    long long k = g[v][i];
    if (k != m) {
      volume[k] = volume[v] + 1;
      dfs(k, v);
    }
  }
}
void prepare() {
  for (long long i = 0; i <= 500000; i++)
    for (long long k = 1; k <= 20; k++) p[i][k] = -1;
  dfs(1, -1);
  for (long long k = 1; k <= 20; k++)
    for (long long i = 1; i <= 500000; i++)
      if (p[i][k - 1] != -1) p[i][k] = p[p[i][k - 1]][k - 1];
  ans = 1;
  cout << ans << ' ';
  s = 1;
  f = 2;
}
long long kanst(long long v, long long k) {
  while (k > 0) {
    long long k0 = log2(k);
    v = p[v][k0];
    k -= 1 << k0;
  }
  return v;
}
long long lca(long long a, long long b) {
  if (a == b) return a;
  if (volume[b] > volume[a]) swap(a, b);
  a = kanst(a, volume[a] - volume[b]);
  if (a == b) return a;
  for (long long j = 20; j >= 0; j--) {
    if (p[a][j] != p[b][j]) {
      a = p[a][j];
      b = p[b][j];
    }
  }
  return p[a][0];
}
int main() {
  cin >> n;
  g.resize(200001);
  vector<long long> d;
  d.resize(n + 1);
  for (long long i = 2; i <= n; i++) {
    long long a;
    cin >> a;
    d[i] = i;
    g[i].push_back(a);
    g[a].push_back(i);
  }
  prepare();
  for (long long k = 3; k <= n; k++) {
    if (volume[s] + volume[k] - 2 * volume[lca(s, k)] > ans) {
      ans = volume[s] + volume[k] - 2 * volume[lca(s, k)];
      f = k;
    }
    if (volume[f] + volume[k] - 2 * volume[lca(f, k)] > ans) {
      ans = volume[f] + volume[k] - 2 * volume[lca(f, k)];
      s = k;
    }
    cout << ans << ' ';
  }
  return 0;
}
