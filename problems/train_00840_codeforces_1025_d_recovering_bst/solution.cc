#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
const int N = 710;
int G[N][N];
int dp[N][N][2];
int solve(int l, int r, int f) {
  if (l > r) return 1;
  if (l == r) {
    int root = (f == 0 ? l - 1 : r + 1);
    if (G[root][l] > 1) return 1;
    return 0;
  }
  int& x = dp[l][r][f];
  if (x != -1) return x;
  x = 0;
  int root = (f == 0 ? l - 1 : r + 1);
  for (int k = l; k <= r; k++) {
    if (G[root][k] > 1) x |= (solve(l, k - 1, 1) & solve(k + 1, r, 0));
  }
  return x;
}
int v[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i < (n + 1); ++i) cin >> v[i];
  sort(v + 1, v + 1 + n);
  for (int i = 1; i < (n + 1); ++i) {
    for (int j = 1; j < (n + 1); ++j) {
      G[i][j] = gcd(v[i], v[j]);
    }
  }
  memset(dp, -1, sizeof(dp));
  int ok = 0;
  for (int k = 1; k <= n; k++) {
    ok |= (solve(1, k - 1, 1) & solve(k + 1, n, 0));
  }
  if (ok)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
}
