#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
const long long mod = (1e9) + 7;
int n, m, ans, tmp, tot;
void update(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
bool in(int t, int i) {
  if (t & (1 << (i - 1))) return 1;
  return 0;
}
int f(int x, int i) {
  if (x % 2 != i) x--;
  return x / 2 + 1;
}
int gcd(int x, int y) {
  if (!x || !y) return x + y;
  return gcd(y, x % y);
}
int main() {
  read(n);
  read(m);
  int a, b, c, d;
  for (int x = 0; x < 2; x++)
    for (int y = 0; y < 2; y++) {
      for (int t = 0; t < (1 << 4); t++) {
        a = in(t, 1);
        b = in(t, 2);
        c = in(t, 3);
        d = in(t, 4);
        if (abs((a - x) * (d - y) - (c - x) * (b - y)) % 2 == 0)
          update(ans, (long long)f(n, a) * f(m, b) % mod * f(n, c) % mod *
                          f(m, d) % mod * f(n, x) % mod * f(m, y) % mod);
      }
    }
  tot = (n + 1) * (m + 1);
  update(ans, mod - tot);
  update(ans, mod - (long long)tot * (tot - 1) * 3 % mod);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (!i && !j) continue;
      tmp = (n - i + 1) * (m - j + 1) % mod;
      if (i && j) tmp = tmp * 2 % mod;
      tmp = (long long)tmp * (gcd(i, j) - 1) * 6 % mod;
      update(ans, mod - tmp);
    }
  printf("%d\n", ans);
  return 0;
}
