#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
void tracer(istream_iterator<string> it) {}
template <typename T, typename... Args>
void tracer(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " | ";
  tracer(++it, args...);
}
const long long MOD = 1e9 + 7;
const long double err = 1e-10;
const int N = 5e5 + 5;
set<pair<pair<int, int>, int>> st;
vector<vector<int>> adj(N);
int connected = 0;
vector<bool> vis(N, 0);
void no() {
  cout << "NO\n";
  exit(0);
}
void dfs(int u, int par = -1) {
  vis[u] = 1;
  connected++;
  for (auto v : adj[u]) {
    if (v == par) continue;
    if (vis[v]) no();
    dfs(v, u);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i].second >> V[i].first;
    st.insert(make_pair(make_pair(V[i].second, V[i].first), i + 1));
  }
  sort((V).begin(), (V).end());
  for (int i = 0; i < n; i++) {
    int us = V[i].second, ue = V[i].first, idx;
    auto mit = st.lower_bound(make_pair(make_pair(us, ue), -1));
    idx = (*mit).second;
    auto it = next(mit);
    st.erase(mit);
    int pmn = 2e9;
    while (it != st.end()) {
      auto prr = *it;
      int vs = prr.first.first, ve = prr.first.second, vidx = prr.second;
      if (vs > ue) break;
      if (ve > pmn) no();
      pmn = ve;
      adj[idx].push_back(vidx);
      adj[vidx].push_back(idx);
      it++;
    }
  }
  dfs(1);
  if (connected < n) no();
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
