#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1605;
const long double eps = 1e-10;
struct data {
  int a, b, s, t;
  long double p;
  bool operator<(const data& d2) const {
    return t * p * (1 - d2.p) < d2.t * d2.p * (1 - p);
  }
} a[MAXN];
int N, T;
long double f[MAXN][MAXN], g[MAXN][MAXN], ans = -1e100, tim = 1e100;
int main() {
  cin >> N >> T;
  for (int i = 1; i <= N; ++i)
    cin >> a[i].a >> a[i].b >> a[i].s >> a[i].t >> a[i].p;
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= T; ++i) f[0][i] = -1e100;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= T; ++j) f[i][j] = f[i - 1][j], g[i][j] = g[i - 1][j];
    for (int j = a[i].s; j <= T; ++j) {
      if (f[i - 1][j - a[i].s] + a[i].a - f[i][j] > eps) {
        f[i][j] = f[i - 1][j - a[i].s] + a[i].a;
        g[i][j] = g[i - 1][j - a[i].s];
      } else if (abs(f[i - 1][j - a[i].s] + a[i].a - f[i][j]) < eps) {
        g[i][j] = max(g[i][j], g[i - 1][j - a[i].s]);
      }
    }
    for (int j = a[i].s + a[i].t; j <= T; ++j) {
      if (f[i - 1][j - a[i].s - a[i].t] + a[i].a + a[i].b * (1 - a[i].p) -
              f[i][j] >
          eps) {
        f[i][j] =
            f[i - 1][j - a[i].s - a[i].t] + a[i].a + a[i].b * (1 - a[i].p);
        g[i][j] = (g[i - 1][j - a[i].s - a[i].t] + a[i].t) * a[i].p;
      } else if (abs(f[i - 1][j - a[i].s - a[i].t] + a[i].a +
                     a[i].b * (1 - a[i].p) - f[i][j]) < eps) {
        g[i][j] =
            max(g[i][j], (g[i - 1][j - a[i].s - a[i].t] + a[i].t) * a[i].p);
      }
    }
  }
  for (int i = 0; i <= T; ++i) {
    if (f[N][i] - ans > eps) {
      ans = f[N][i];
      tim = i - g[N][i];
    } else if (abs(f[N][i] - ans) < eps) {
      tim = min(tim, i - g[N][i]);
    }
  }
  cout << fixed << setprecision(10) << ans << ' ' << tim;
  return 0;
}
