#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3LL;
const long long mod = (long long)1e9 + 7;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
const long long N = 102;
long long n, dp[N][2][N];
long long cnt[N], a[N];
long long v[2];
long long solve(long long idx, long long prev_parity, long long no_of_ones) {
  if (idx > n) {
    return 0;
  }
  long long& ans = dp[idx][prev_parity][no_of_ones];
  if (ans != -1) return ans;
  ans = inf;
  long long no_of_zeros = (idx - 1) - (no_of_ones + cnt[idx - 1]);
  ;
  if (a[idx] != 0) {
    long long add = 0;
    if (idx > 1) {
      add = (prev_parity != a[idx] % 2);
    }
    ans = add + solve(idx + 1, a[idx] % 2, no_of_ones);
    return ans;
  }
  if (no_of_zeros < (v[0])) {
    long long add = 0;
    if (idx > 1) {
      add = (prev_parity != 0);
    }
    ans = add + solve(idx + 1, 0, no_of_ones);
  }
  if (no_of_ones < (v[1])) {
    long long add = 0;
    if (idx > 1) {
      add = (prev_parity != 1);
    }
    smin(ans, add + solve(idx + 1, 1, no_of_ones + 1));
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector<bool> vis(n + 50);
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    vis[a[i]] = 1;
    cnt[i] = cnt[i - 1];
    if (a[i] != 0) cnt[i]++;
  }
  for (long long i = 1; i <= n; ++i) {
    if (!vis[i]) {
      v[i % 2]++;
    }
  }
  memset(dp, -1, sizeof dp);
  cout << solve(1, 0, 0);
  return 0;
}
