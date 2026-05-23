#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool smin(T &a, const T &b) {
  return a > b ? a = b : a;
}
template <typename T>
inline bool smax(T &a, const T &b) {
  return a < b ? a = b : a;
}
const long long N = (long long)2e5 + 5, mod = (long long)0;
long long sz[N], dp[N], odp[N];
int32_t main() {
  long long a, b, h, w, n;
  cin >> a >> b >> h >> w >> n;
  for (long long j = 0; j < n; ++j) {
    cin >> sz[j];
  }
  sort(sz, sz + n);
  reverse(sz, sz + n);
  dp[h] = 1;
  for (long long j = 0; j <= min(n, 50LL); ++j) {
    for (long long k = a; k < N; ++k)
      if (dp[k] * w >= b) {
        cout << j << endl;
        return 0;
      }
    for (long long k = b; k < N; ++k)
      if (dp[k] * w >= a) {
        cout << j << endl;
        return 0;
      }
    memcpy(odp, dp, sizeof dp);
    memset(dp, 0, sizeof dp);
    if (j != n) {
      for (long long k = 0; k < N; ++k) {
        long long nxt = min(k * sz[j], N - 1);
        dp[k] = max(dp[k], min(N, odp[k] * sz[j]));
        dp[nxt] = max(dp[nxt], min(N, odp[k]));
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
