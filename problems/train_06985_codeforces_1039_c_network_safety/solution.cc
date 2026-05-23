#include <bits/stdc++.h>
using namespace std;
map<long long, vector<pair<long long, long long>>> m1;
vector<long long> used;
vector<vector<long long>> g;
const long long inf = 1e9 + 7;
void dfs(long long v, long long timer) {
  used[v] = timer;
  for (auto u : g[v]) {
    if (used[u] != timer) dfs(u, timer);
  }
}
long long N = 500005;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> pwr(N);
  pwr[0] = 1;
  for (long long i = 1; i < N; ++i) {
    pwr[i] = (2 * pwr[i - 1]) % inf;
  }
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    --u, --v;
    m1[(a[u] ^ a[v])].push_back({u, v});
  }
  g.resize(n);
  used.resize(n);
  long long answer = 0, timer = 0;
  for (auto x : m1) {
    timer++;
    set<long long> V;
    const auto& cur = x.second;
    for (auto u : cur) {
      V.insert(u.first);
      V.insert(u.second);
      g[u.first].push_back(u.second);
      g[u.second].push_back(u.first);
    }
    long long q = 0;
    for (auto u : V) {
      if (used[u] != timer) {
        dfs(u, timer);
        q++;
      }
    }
    answer = (answer + pwr[n - V.size() + q]) % inf;
    for (auto u : V) {
      g[u].clear();
    }
  }
  answer += (((pwr[k] - m1.size())) * pwr[n]) % inf;
  answer = (answer % inf + inf) % inf;
  cout << answer;
}
