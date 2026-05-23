#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int mod = 1e9 + 7;
int d[MAXN];
int dp[MAXN][MAXN];
int n;
char s[MAXN];
int t1[MAXN], t2[MAXN], c[MAXN], xy[MAXN];
int sa[MAXN], rnk[MAXN], height[MAXN];
int Dp[MAXN][16];
int cmp(int *r, int a, int b, int d) {
  return r[a] == r[b] && r[a + d] == r[b + d];
}
void getHeight(int n, int k = 0) {
  for (int i = 0; i <= n; ++i) rnk[sa[i]] = i;
  for (int i = 0; i < n; ++i) {
    if (k) --k;
    int j = sa[rnk[i] - 1];
    while (s[i + k] == s[j + k]) ++k;
    height[rnk[i]] = k;
  }
}
void da(int n, int m = 128) {
  int *x = t1, *y = t2;
  for (int i = 0; i < n; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) ++c[x[i] = s[i]];
  for (int i = 0; i < m; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
  for (int d = 1, p = 0; p < n; d <<= 1, m = p) {
    p = 0;
    for (int i = n - d; i < n; ++i) y[p++] = i;
    for (int i = 0; i < n; ++i)
      if (sa[i] >= d) y[p++] = sa[i] - d;
    for (int i = 0; i < m; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) ++c[xy[i] = x[y[i]]];
    for (int i = 0; i < m; ++i) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--c[xy[i]]] = y[i];
    swap(x, y);
    p = 0;
    x[sa[0]] = p++;
    for (int i = 1; i < n; ++i)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], d) ? p - 1 : p++;
  }
  getHeight(n - 1);
}
void init_RMQ(int n) {
  for (int i = 1; i <= n; ++i) Dp[i][0] = height[i];
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      Dp[i][j] = min(Dp[i][j - 1], Dp[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int RMQ(int L, int R) {
  int k = 0;
  while ((1 << (k + 1)) <= R - L + 1) ++k;
  return min(Dp[L][k], Dp[R - (1 << k) + 1][k]);
}
int lcp(int a, int b) {
  a = rnk[a], b = rnk[b];
  return a < b ? RMQ(a + 1, b) : RMQ(b + 1, a);
}
bool check(int x, int y, int n) {
  if (d[y] == 0) return 0;
  int t = lcp(x - 1, y - 1);
  if (t >= n) return 0;
  if (rnk[x - 1] < rnk[y - 1]) return 1;
  return 0;
}
void solve() {
  scanf("%s", s);
  for (int i = 1; i <= n; ++i) {
    d[i] = s[i - 1] - '0';
  }
  da(n + 1);
  init_RMQ(n);
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    memset(c, 0, sizeof c);
    for (int j = i - 1; j >= 1; --j)
      if (d[j]) {
        int len = i - j;
        if (i + len - 1 > n) break;
        int ok = check(j, i, len);
        if (ok)
          (c[i + len - 1] += dp[j][i - 1]) %= mod;
        else
          (c[i + len] += dp[j][i - 1]) %= mod;
      }
    for (int j = i; j <= n; ++j) {
      (c[j] += c[j - 1]) %= mod;
      (dp[i][j] += c[j]) %= mod;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (d[i]) {
      (ans += dp[i][n]) %= mod;
    }
  printf("%d\n", ans);
}
int main() {
  while (~scanf("%d", &n)) solve();
  return 0;
}
