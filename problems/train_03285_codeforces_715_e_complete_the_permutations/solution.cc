#include <bits/stdc++.h>
using namespace std;
int dg[2010], a[2010], b[2010], n, dp[2010][2010];
int va[2010], vb[2010], v[2010], vs[2010], f[2010], g[2010], h[2010];
int A, B, X, C, D, fac[2010], inv[2010];
int gmod(int x) { return x >= 998244353 ? x - 998244353 : x; }
void mul(int a[], int b[], int c[]) {
  for (int i = 0; i <= n; ++i) h[i] = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; i + j <= n; ++j)
      h[i + j] = (h[i + j] + 1ll * a[i] * b[j]) % 998244353;
  for (int i = 0; i <= n; ++i) c[i] = h[i];
}
int qpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % 998244353)
    if (b & 1) ans = 1ll * ans * a % 998244353;
  return ans;
}
int main() {
  scanf("%d", &n);
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % 998244353;
  inv[n] = qpow(fac[n], 998244353 - 2);
  for (int i = n - 1; i >= 1; --i)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % 998244353;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] ? va[a[i]] = i : 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), b[i] ? vb[b[i]] = i : 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] && b[i]) dg[a[i]]++, dg[b[i]]++;
  int N = n, X = 0;
  for (int i = 1, j; i <= n; ++i)
    if (!vs[i] && dg[i] == 1) {
      if (va[i]) {
        int x = va[i];
        vs[i] = 1;
        while (x) {
          int y = b[x];
          vs[y] = 1, x = va[y];
        }
      } else {
        int x = vb[i];
        vs[i] = 1;
        while (x) {
          int y = a[x];
          vs[y] = 1, x = vb[y];
        }
      }
    }
  for (int i = 1, j; i <= n; ++i)
    if (!vs[i] && dg[i] == 2) {
      for (j = i; !vs[j];) {
        int nxt = b[va[j]];
        vs[j] = 1, j = nxt;
      }
      X++;
    }
  for (int i = 1; i <= n; ++i)
    if (va[i] && vb[i]) N--;
  for (int i = 1; i <= n; ++i)
    if (((!!va[i]) ^ (!!vb[i]))) {
      if (va[i]) {
        int x = va[i];
        while (1) {
          int y = b[x];
          if (!y) {
            A++;
            break;
          }
          if (!va[y]) {
            C++;
            break;
          }
          x = va[y];
        }
      } else {
        int x = vb[i];
        while (1) {
          int y = a[x];
          if (!y) {
            B++;
            break;
          }
          if (!vb[y]) {
            C++;
            break;
          }
          x = vb[y];
        }
      }
    }
  C /= 2;
  D = N - A - B - C;
  g[X] = 1;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= A; ++i)
    for (int j = 0; j <= i; ++j)
      dp[i][j] =
          ((j ? dp[i - 1][j - 1] : 0) + 1ll * dp[i - 1][j] * (A + D - i)) %
          998244353;
  mul(dp[A], g, g);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= B; ++i)
    for (int j = 0; j <= i; ++j)
      dp[i][j] =
          ((j ? dp[i - 1][j - 1] : 0) + 1ll * dp[i - 1][j] * (B + D - i)) %
          998244353;
  mul(dp[B], g, g);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= C; ++i)
    for (int j = 0, x = D - i + 1; j <= i; ++j)
      dp[i][j] = ((j ? 1ll * dp[i - 1][j - 1] * x : 0) +
                  1ll * dp[i - 1][j] * x * (x - 1)) %
                 998244353;
  mul(dp[C], g, g);
  D -= C;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= D; ++i)
    for (int j = 0; j <= i; ++j)
      dp[i][j] = ((j ? 1ll * dp[i - 1][j - 1] * i : 0) +
                  1ll * dp[i - 1][j] * (D - i) * i) %
                 998244353;
  mul(dp[D], g, g);
  for (int i = 1; i <= n; ++i) printf("%d ", g[n - i + 1]);
}
