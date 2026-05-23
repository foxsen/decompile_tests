#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
const int MXN = (int)1e5 + 7;
int n, k, t;
int fac[MXN], rev[MXN], m[MXN];
int binpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (1LL * res * x) % INF;
    y >>= 1;
    x = (1LL * x * x) % INF;
  }
  return res;
}
int c(int x, int y) {
  if (y > x) return 0;
  long long res = (1LL * fac[x] * rev[x - y]) % INF;
  res = (1LL * res * rev[y]) % INF;
  return res;
}
int f(int d) {
  int res = c(n / d - 1, k - 1);
  return res;
}
int main() {
  fac[0] = 1;
  rev[0] = 1;
  for (int i = 1; i < MXN; i++) fac[i] = (fac[i - 1] * 1LL * i) % INF;
  for (int i = 1; i < MXN; i++) {
    m[i] = 1;
    int cur = i;
    for (int d = 2; d * d <= cur; d++) {
      if (cur % d != 0) continue;
      int cnt = 0;
      while (cur % d == 0) {
        cur /= d;
        cnt++;
      }
      if (cnt >= 2) {
        m[i] = 0;
        break;
      }
      m[i] = -m[i];
    }
    if (cur > 1) m[i] = -m[i];
    rev[i] = binpow(fac[i], INF - 2);
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    int ans = 0;
    for (int d = 1; d * d <= n; d++) {
      if (n % d != 0) continue;
      ans = (ans + 1LL * m[d] * f(d)) % INF;
      if (n / d != d) ans = (ans + 1LL * m[n / d] * f(n / d)) % INF;
      if (ans < 0) ans += INF;
    }
    printf("%d\n", ans);
  }
  return 0;
}
