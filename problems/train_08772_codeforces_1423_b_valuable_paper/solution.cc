#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
struct BipartiteMatcher {
  vector<vector<long long>> G;
  vector<long long> L, R, Viz;
  BipartiteMatcher(long long n, long long m)
      : G(n), L(n, -1), R(m, -1), Viz(n) {}
  void AddEdge(long long a, long long b) { G[a].push_back(b); }
  bool Match(long long node) {
    if (Viz[node]) return false;
    Viz[node] = true;
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    return false;
  }
  long long Solve() {
    long long ok = true;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (long long i = 0; i < (long long)L.size(); ++i)
        if (L[i] == -1) ok |= Match(i);
    }
    long long ret = 0;
    for (long long i = 0; i < L.size(); ++i) ret += (L[i] != -1);
    return ret;
  }
};
bool comp(const pair<long long, pair<long long, long long>> &a,
          const pair<long long, pair<long long, long long>> &b) {
  return a.second.second < b.second.second;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, pair<long long, long long>>> roads;
    for (long long i = 0; i < m; ++i) {
      long long u, v, w;
      cin >> u >> v >> w;
      --u;
      --v;
      roads.push_back({u, {v, w}});
    }
    sort(roads.begin(), roads.end(), comp);
    long long lo = 0, hi = 1e9 + 1;
    while (lo < hi) {
      long long md = (lo + hi) >> 1;
      BipartiteMatcher graph(n, n);
      for (auto it : roads) {
        if (it.second.second <= md)
          graph.AddEdge(it.first, it.second.first);
        else
          break;
      }
      long long cnt = graph.Solve();
      if (cnt < n) {
        lo = md + 1;
      } else
        hi = md;
    }
    if (hi == (1e9 + 1))
      cout << -1;
    else
      cout << hi;
  }
  return 0;
}
