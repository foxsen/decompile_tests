#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[200007];
set<long long> s[200007];
map<long long, long long> dp[200007];
long long ans = 0;
long long a[200007];
long long spf[200007];
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < 200007; i++) spf[i] = i;
  for (long long i = 4; i < 200007; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 200007; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 200007; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
set<long long> getFactorization(long long x) {
  set<long long> ret;
  while (x != 1) {
    ret.insert(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
void dfs(long long n, long long u) {
  for (auto e : adj[n]) {
    if (e == u) continue;
    dfs(e, n);
  }
  long long k = s[n].size();
  vector<long long> v[k];
  long long i = 0;
  for (auto f : s[n]) {
    dp[n][f] = 1;
    ans = max(ans, dp[n][f]);
    for (auto e : adj[n]) {
      v[i].push_back(dp[e][f]);
      dp[n][f] = max(dp[n][f], dp[e][f] + 1);
      ans = max(ans, dp[n][f]);
    }
    i++;
  }
  for (i = (0); i <= (k - 1); i++) sort(v[i].begin(), v[i].end());
  for (i = (0); i <= (k - 1); i++) {
    long long j = v[i].size();
    if (j >= 2) ans = max(ans, v[i][j - 1] + v[i][j - 2] + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, k = 0, m, i, j, l = 0, r = 8000000000000000007, u = 0, x = 0, y;
  sieve();
  cin >> n;
  for (i = (1); i <= (n); i++) cin >> a[i];
  for (i = (1); i <= (n - 1); i++) {
    cin >> x >> y;
    adj[x].push_back(y), adj[y].push_back(x);
  }
  for (i = (1); i <= (n); i++) s[i] = getFactorization(a[i]);
  dfs(1, 0);
  cout << ans;
}
