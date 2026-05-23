#include <bits/stdc++.h>
const int maxN = 5e5 + 7;
const int maxH = 60;
int n, fa[maxN];
double f[maxN][maxH];
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int main() {
  int n = 1, T = read(), opt, x;
  for (int i = 0; i < maxH; ++i) f[1][i] = 1;
  while (T--) {
    opt = read();
    x = read();
    if (opt == 1) {
      fa[++n] = x;
      for (int i = 0; i < maxH; ++i) f[n][i] = 1;
      double tmp1 = f[x][0], tmp2;
      f[x][0] *= 0.5;
      for (int Fa = fa[x], i = 1; Fa && i < maxH; Fa = fa[x = Fa], ++i) {
        tmp2 = f[Fa][i];
        f[Fa][i] /= 0.5 + 0.5 * tmp1;
        f[Fa][i] *= 0.5 + 0.5 * f[x][i - 1];
        tmp1 = tmp2;
      }
    } else {
      double ans = 0;
      for (int i = 1; i < maxH; ++i) ans += (f[x][i] - f[x][i - 1]) * i;
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
