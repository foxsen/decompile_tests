#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int f = 1, sum = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 3) + (sum << 1) + ch - '0';
    ch = getchar();
  }
  return f * sum;
}
double ans, f[100010][110];
int n, m, a[100010], b[100010];
double C(int n, int m) {
  if (n < m) return 0;
  double ret = 1;
  for (int i = 1; i <= m; i++) ret = ret * (1.0 * (n - i + 1) / i);
  return ret;
}
int main() {
  n = gi();
  for (int i = 1; i <= n; i++) a[i] = b[i] = gi();
  for (int i = 1; i <= n; i++) f[i][a[i]] = 1;
  for (int i = 1; i <= n; i++) ans += f[i][0];
  m = gi();
  while (m--) {
    int u = gi(), v = gi(), K = gi();
    ans -= f[u][0];
    for (int j = 0; j <= a[u]; j++) {
      double now = 0, cc = C(b[u], K);
      for (int k = 0; k <= K; k++)
        now += f[u][j + k] * C(j + k, k) * C(b[u] - j - k, K - k) / cc;
      f[u][j] = now;
    }
    b[u] -= K;
    b[v] += K;
    ans += f[u][0];
    printf("%.10lf\n", ans);
  }
  return 0;
}
