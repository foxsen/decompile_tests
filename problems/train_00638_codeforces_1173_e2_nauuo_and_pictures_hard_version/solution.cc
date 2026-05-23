#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
const int N = 200010;
const int M = 3010;
int pow_mod(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) {
      ret = 1LL * ret * a % md;
    }
    b >>= 1;
    a = 1LL * a * a % md;
  }
  return ret;
}
int inv[M << 1];
int f[M][M], g[M][M];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> w(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int SA = 0, SB = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    if (a[i] == 0) {
      SB += w[i];
    } else {
      SA += w[i];
    }
  }
  vector<int> inv(M << 1);
  for (int delta = -m; delta <= m; delta++) {
    if (SA + SB + delta > 0) inv[delta + m] = pow_mod(SA + SB + delta, md - 2);
  }
  for (int i = m; i >= 0; i--) {
    f[i][m - i] = g[i][m - i] = 1;
    for (int j = min(SB, m - i - 1); j >= 0; j--) {
      f[i][j] += 1LL * (SA + i + 1) * f[i + 1][j] % md * inv[i - j + m] % md;
      f[i][j] %= md;
      f[i][j] += 1LL * (SB - j) * f[i][j + 1] % md * inv[i - j + m] % md;
      f[i][j] %= md;
      g[i][j] += 1LL * (SB - j - 1) * g[i][j + 1] % md * inv[i - j + m] % md;
      g[i][j] %= md;
      g[i][j] += 1LL * (SA + i) * g[i + 1][j] % md * inv[i - j + m] % md;
      g[i][j] %= md;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      printf("%d\n", 1LL * w[i] * f[0][0] % md);
    } else {
      printf("%d\n", 1LL * w[i] * g[0][0] % md);
    }
  }
  return 0;
}
