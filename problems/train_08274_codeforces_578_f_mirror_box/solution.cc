#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = N * N;
int n, m, l, mod, fa[M], id[M], fl;
long long ans, a[N][N];
char s[N][N];
long long mypow(long long x, int y) {
  long long z = 1;
  while (y) {
    if (y & 1) (z *= x) %= mod;
    y >>= 1;
    (x *= x) %= mod;
  }
  return z;
}
long long det() {
  l--;
  long long res = 1;
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= l; j++) a[i][j] %= mod;
  }
  for (int i = 1; i <= l; i++) {
    int k = i;
    while (k <= l && !a[k][i]) k++;
    if (k > l) return 0;
    if (k != i) res *= -1;
    for (int j = 1; j <= l; j++) swap(a[k][j], a[i][j]);
    (res *= a[i][i]) %= mod;
    for (int j = i + 1; j <= l; j++)
      if (a[j][i]) {
        long long z = a[j][i] * mypow(a[i][i], mod - 2) % mod;
        for (int y = 1; y <= l; y++) (a[j][y] -= a[i][y] * z) %= mod;
      }
  }
  return res;
}
int fd(int x) { return fa[x] == x ? x : fa[x] = fd(fa[x]); }
void link(int x, int y) {
  x = fd(x), y = fd(y);
  fa[x] = y;
  if (x == y) fl = 1;
}
void pre() {
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      int x = ((i - 1) * (m + 1) + j);
      fa[x] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '\\') {
        link(((i - 1) * (m + 1) + j), ((i + 1 - 1) * (m + 1) + j + 1));
      } else if (s[i][j] == '/') {
        link(((i - 1) * (m + 1) + j + 1), ((i + 1 - 1) * (m + 1) + j));
      }
    }
  }
}
void work(bool f) {
  l = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++)
      if (((i + j) & 1) == f) {
        int x = ((i - 1) * (m + 1) + j);
        if (fa[x] == x) id[x] = ++l;
      }
  }
  if (l > 202) return;
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= l; j++) a[i][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '*') {
        int x, y;
        if (((i + j) & 1) == f)
          x = ((i - 1) * (m + 1) + j), y = ((i + 1 - 1) * (m + 1) + j + 1);
        else
          x = ((i + 1 - 1) * (m + 1) + j), y = ((i - 1) * (m + 1) + j + 1);
        x = id[fd(x)], y = id[fd(y)];
        a[x][x]++, a[y][y]++;
        a[x][y]--, a[y][x]--;
      }
  }
  ans += det();
}
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  pre();
  work(1);
  work(0);
  if (fl) ans = 0;
  printf("%I64d\n", (ans % mod + mod) % mod);
  return 0;
}
