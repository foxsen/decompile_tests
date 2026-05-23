#include <bits/stdc++.h>
using namespace std;
int head[52], tot, size[52], n;
long double c[52][52], dp[52][52], tmp[52], g[52];
inline int rd() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
struct edge {
  int n, to;
} e[52 << 1];
inline long double calc(int n, int m) { return c[n][m]; }
inline long double path(int n, int m) { return c[n + m][n]; }
inline void add(int u, int v) {
  e[++tot].n = head[u];
  e[tot].to = v;
  head[u] = tot;
}
void dfs(int u, int fa) {
  dp[u][0] = 1;
  size[u] = 1;
  for (int i = head[u]; i; i = e[i].n)
    if (e[i].to != fa) {
      int v = e[i].to;
      dfs(v, u);
      for (int i = 0; i <= size[v]; ++i) {
        g[i] = 0;
        for (int j = 0; j < i; ++j) g[i] += 0.5 * dp[v][j];
        g[i] += (size[v] - i) * dp[v][i];
      }
      for (int j = 0; j < size[u]; ++j)
        for (int k = 0; k <= size[v]; ++k)
          tmp[j + k] +=
              dp[u][j] * g[k] * path(j, k) * path(size[u] - 1 - j, size[v] - k);
      for (int j = 0; j <= size[u] + size[v]; ++j)
        dp[u][j] = tmp[j], tmp[j] = 0;
      size[u] += size[v];
    }
}
int main() {
  n = rd();
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  int u, v;
  for (int i = 1; i < n; ++i) {
    u = rd();
    v = rd();
    add(u, v);
    add(v, u);
  }
  long double xx = 1;
  for (int i = 1; i < n; ++i) xx = xx * i;
  for (int i = 1; i <= n; ++i) {
    memset(dp, 0, sizeof(dp));
    dfs(i, 0);
    double x = dp[i][n - 1] / xx;
    printf("%.10lf\n", x);
  }
  return 0;
}
