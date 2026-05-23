#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return y < x ? (x = y, 1) : 0;
}
const int maxn = 2e3 + 17, mod = 1e9 + 7;
int n, dp[maxn][2048], ans, s[maxn], a[maxn], k;
void go(int i, int mask, int ad) {
  if ((mask & -mask) < ad)
    (dp[i + 1][ad] += dp[i][mask]) %= mod;
  else if (mask + ad == 1 << k)
    (ans += (long long)dp[i][mask] * s[i + 1] % mod) %= mod;
  else
    (dp[i + 1][mask + ad] += dp[i][mask]) %= mod;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k, k--;
  for (int i = 0; i < n; i++) cin >> a[i], a[i] /= 2;
  s[n] = 1;
  for (int i = n - 1; ~i; i--) s[i] = s[i + 1] * (a[i] ? 1 : 2) % mod;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int mask = 0; mask < 1 << k; mask++) {
      if (a[i] != 1) go(i, mask, 2);
      if (a[i] != 2) go(i, mask, 1);
    }
  cout << ans << '\n';
  return 0;
}
