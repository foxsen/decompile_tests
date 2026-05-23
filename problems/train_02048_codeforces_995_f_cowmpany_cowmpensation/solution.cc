#include <bits/stdc++.h>
using namespace std;
int n, d;
long long dp[3006][3006], c[3006][3006], tmp = 1, ans = 0;
const long long mod = 1e9 + 7;
vector<int> e[3006];
int dfs(int u, int p = 0) {
  for (int i = 1; i <= n; i++) dp[u][i] = 1;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    dfs(v, u);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < e[u].size(); j++) {
      int v = e[u][j];
      if (v == p) continue;
      dp[u][i] = (dp[u][i] * dp[v][i]) % mod;
    }
  for (int i = 1; i <= n; i++) dp[u][i] = (dp[u][i] + dp[u][i - 1]) % mod;
  return 0;
}
int init_com() {
  for (int i = 0; i < 3006; i++) c[i][0] = 1;
  for (int i = 1; i < 3006; i++)
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  return 0;
}
long long fast_pow(long long x, long long y) {
  if (y == 1) return x;
  if (y == 0) return 1;
  long long res = fast_pow(x, y / 2);
  if (y % 2) return ((res * res) % mod) * x % mod;
  return res * res % mod;
}
long long inv(long long x) { return fast_pow(x, mod - 2); }
int main() {
  init_com();
  cin >> n >> d;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    e[x].push_back(i);
  }
  memset(dp, 0, sizeof(dp));
  dfs(1);
  if (d <= n) return cout << dp[1][d], 0;
  for (int i = 1; i <= min(n, d); i++) {
    tmp = (tmp * (d - i + 1)) % mod;
    tmp = (tmp * inv(i)) % mod;
    for (int j = i - 1; j >= 1; j--) {
      long long dec = c[i][j];
      dec = (dec * dp[1][j]) % mod;
      dp[1][i] = (dp[1][i] - dec + mod) % mod;
    }
    ans = (ans + dp[1][i] * tmp % mod) % mod;
  }
  cout << ans;
}
