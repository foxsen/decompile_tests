#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
using namespace std;
long long n;
vector<long long> vc;
vector<vector<pair<long long, long long>>> adj;
long long ans;
long long dfs(long long s, long long p) {
  long long m1, m2;
  m1 = m2 = 0;
  for (auto i : adj[s]) {
    if (p != i.first) {
      long long m = dfs(i.first, s);
      m -= i.second;
      if (m > m1) {
        m2 = m1;
        m1 = m;
      } else if (m > m2) {
        m2 = m;
      }
    }
  }
  ans = max(ans, m1 + m2 + vc[s]);
  return m1 + vc[s];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vc.resize(n + 1);
  adj.resize(n + 1);
  for (long long i = 1; i <= n; i++) cin >> vc[i];
  long long a, b, c;
  for (long long i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  dfs(1, -1);
  cout << ans << "\n";
  return 0;
}
