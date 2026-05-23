#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100005;
const long long LOG = 20;
long long n, l, s;
long long a[MAXN];
vector<long long> g[MAXN];
long long depth[MAXN], sum[MAXN], up[MAXN][LOG];
long long dp[MAXN];
long long ans = 0;
void calc(long long v) {
  for (long long i = 1; i < LOG; i++) {
    up[v][i] = -1;
  }
  for (long long i = 1; i < LOG; i++) {
    if (up[v][i - 1] == -1 || up[up[v][i - 1]][i - 1] == -1) {
      up[v][i] = -1;
    } else {
      up[v][i] = up[up[v][i - 1]][i - 1];
    }
  }
  for (long long to : g[v]) {
    depth[to] = depth[v] + 1;
    sum[to] = sum[v] + a[to];
    up[to][0] = v;
    calc(to);
  }
}
void dfs(long long v) {
  for (long long to : g[v]) {
    dfs(to);
    dp[v] = max(dp[v], dp[to]);
  }
  dp[v]--;
  if (dp[v] == -1) {
    ans++;
    long long x = v;
    for (long long i = LOG - 1; i >= 0; i--) {
      if (up[x][i] != -1 && depth[v] - depth[up[x][i]] + 1 <= l &&
          sum[v] - sum[up[x][i]] + a[up[x][i]] <= s) {
        x = up[x][i];
      }
    }
    dp[v] = depth[v] - depth[x];
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base ::sync_with_stdio(0);
  cin >> n >> l >> s;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > s) {
      cout << -1;
      return 0;
    }
  }
  for (long long i = 1; i < n; i++) {
    long long p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  depth[0] = 0;
  sum[0] = a[0];
  up[0][0] = -1;
  calc(0);
  dfs(0);
  cout << ans;
  return 0;
}
