#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long inf = 5e9 + 7;
const long long max_n = 2e3 + 3, log_n = 12;
long long n;
vector<vector<pair<long long, long long>>> scan(long long id) {
  long long a;
  cin >> a;
  vector<long long> par(a), deg(a), least(a, inf), sz(a, 1);
  sz[0] = 0;
  vector<vector<pair<long long, long long>>> res(n);
  for (long long i = 1; i < a; ++i) {
    cin >> par[i], --par[i];
    deg[par[i]]++;
  }
  for (long long i = 0; i < n; i++) {
    long long v;
    cin >> v;
    --v;
    least[v] = i;
    while (true) {
      res[i].emplace_back(least[v], sz[v]);
      long long to = par[v];
      if (least[to] == inf) least[to] = least[v];
      --deg[to];
      sz[to] += sz[v];
      if (deg[to] != 0) break;
      v = to;
    }
  }
  return res;
}
void solve() {
  cin >> n;
  vector<vector<pair<long long, long long>>> r1 = scan(0), r2 = scan(1);
  vector<long long> dp(n);
  for (long long i = 0; i < n; i++) {
    for (pair<long long, long long> j : r1[i]) {
      dp[i] = max(dp[i], j.second + (j.first == 0 ? 0 : dp[j.first - 1]));
    }
    for (pair<long long, long long> j : r2[i]) {
      dp[i] = max(dp[i], j.second + (j.first == 0 ? 0 : dp[j.first - 1]));
    }
  }
  cout << dp[n - 1];
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout.precision(10);
  solve();
}
