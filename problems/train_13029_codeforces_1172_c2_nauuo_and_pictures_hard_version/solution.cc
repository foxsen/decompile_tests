#include <bits/stdc++.h>
using namespace std;
const long long maxn = 300007;
const long long maxm = 5007;
const long long mod = 998244353;
long long n, m, l[maxn], w[maxn], yes = 0, no = 0;
long long dp[maxm][maxm];
inline long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long ans = exgcd(b, a % b, x, y);
  long long u = y, v = x - a / b * y;
  x = u, y = v;
  return ans;
}
inline long long inv(long long u) {
  u = (u % mod + mod) % mod;
  long long ans, tmp;
  exgcd(u, mod, ans, tmp);
  return (ans % mod + mod) % mod;
}
inline long long mult(long long u, long long v) { return u * v % mod; }
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &l[i]);
  for (int i = 1; i <= n; ++i) scanf("%lld", &w[i]);
  for (int i = 1; i <= n; ++i) {
    if (l[i])
      yes += w[i];
    else
      no += w[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i][j] =
          (dp[i][j] + mult(dp[i - 1][j], mult((no - i + j + 1) % mod,
                                              inv(yes + no - i + 2 * j + 1)))) %
          mod;
      dp[i][j + 1] =
          (dp[i][j + 1] +
           mult(dp[i - 1][j], mult(yes + j, inv(yes + no - i + 2 * j + 1)))) %
          mod;
    }
  }
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i <= m; ++i) {
    ans1 = (ans1 + mult(yes + i, dp[m][i])) % mod;
    ans2 = (ans2 + mult((no - m + i + mod) % mod, dp[m][i])) % mod;
  }
  for (int i = 1; i <= n; ++i) {
    if (l[i]) {
      printf("%lld\n", mult(inv(yes), mult(ans1, w[i])));
    } else {
      printf("%lld\n", mult(inv(no), mult(ans2, w[i])));
    }
  }
  return 0;
}
