#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <typename T>
void read(T &a) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  a = x * f;
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
double dp[1005][1005];
long long n, m;
double dfs(long long n, long long m) {
  if (!m) return 1.0;
  if (!n) return 1.0 / (m + 1);
  if (dp[n][m]) return dp[n][m];
  double a = 1.0 / (m + 1) + 1.0 * m / (m + 1) * (1 - dfs(m - 1, n));
  double b = 1.0 * m / (m + 1) * (1 - dfs(m - 1, n));
  double c = 1;
  double d = 1 - dfs(m, n - 1);
  double p = (d - c) / (b - a - c + d);
  return dp[n][m] = b * p + c * (1 - p);
}
signed main() {
  read(n, m);
  double ans = dfs(n, m);
  printf("%.10lf %.10lf\n", ans, 1 - ans);
  return 0;
}
