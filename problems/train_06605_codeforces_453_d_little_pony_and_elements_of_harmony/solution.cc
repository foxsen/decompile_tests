#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
int a[N], b[N], c[N], f[N];
unsigned long long p[100];
int n, m;
long long T;
int mod, phi, cnt;
int mod1, mod2;
long long k1, k2;
int ans;
struct FWT1 {
  int a[N], b[N];
  int power(int x, long long y) {
    int ret = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
      if (y & 1) ret = 1ll * ret * x % mod;
    }
    return ret;
  }
  void FWT(int a[]) {
    int i, j, k, x, y;
    for (i = 1; i < n; i <<= 1) {
      for (j = 0; j < n; j += (i << 1)) {
        for (k = 0; k < i; k++) {
          x = a[j + k];
          y = a[j + k + i];
          a[j + k] = (x + y) % mod;
          a[j + k + i] = (x - y) % mod;
        }
      }
    }
  }
  void work() {
    int i, INV;
    FWT(a);
    FWT(b);
    for (i = 0; i <= n - 1; i++) a[i] = power(a[i], T);
    for (i = 0; i <= n - 1; i++) a[i] = 1ll * a[i] * b[i] % mod;
    FWT(a);
    INV = power(power(2, m), phi - 1);
    for (i = 0; i <= n - 1; i++) a[i] = 1ll * a[i] * INV % mod;
    for (i = 0; i <= n - 1; i++) a[i] = a[i] < 0 ? a[i] + mod : a[i];
  }
};
FWT1 F1;
void init() {
  int i;
  p[0] = 1;
  for (i = 1; i <= 62; i++) p[i] = p[i - 1] * 2;
}
struct FWT2 {
  unsigned long long power(unsigned long long x, long long y) {
    unsigned long long ret = 1;
    for (; y; y >>= 1, x = x * x) {
      if (y & 1) ret = ret * x;
    }
    return ret;
  }
  unsigned long long a[N], b[N];
  void FWT(unsigned long long a[]) {
    int i, j, k;
    unsigned long long x, y;
    for (i = 1; i < n; i <<= 1) {
      for (j = 0; j < n; j += (i << 1)) {
        for (k = 0; k < i; k++) {
          x = a[j + k];
          y = a[j + k + i];
          a[j + k] = x + y;
          a[j + k + i] = x - y;
        }
      }
    }
  }
  void work() {
    int i, j;
    unsigned long long x;
    long long now;
    FWT(a);
    FWT(b);
    for (i = 0; i <= n - 1; i++) a[i] = power(a[i], T);
    for (i = 0; i <= n - 1; i++) a[i] *= b[i];
    FWT(a);
    for (i = 0; i <= n - 1; i++) a[i] /= p[m];
    for (i = 0; i <= n - 1; i++) a[i] &= (1 << cnt) - 1;
  }
};
FWT2 F2;
void getphi() {
  int x = mod;
  phi = mod;
  int i;
  for (i = 2; i * i <= mod; i++) {
    if (x % i == 0) phi = phi / i * (i - 1);
    while (x % i == 0) x /= i;
  }
  if (x > 1) phi = phi / x * (x - 1);
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
int main() {
  int i;
  int r1, r2;
  init();
  scanf("%d%I64d%d", &m, &T, &mod);
  n = (1 << m);
  while (mod % 2 == 0) {
    cnt++;
    mod >>= 1;
  }
  getphi();
  for (i = 0; i <= n - 1; i++) scanf("%d", &b[i]);
  for (i = 0; i <= m; i++) scanf("%d", &c[i]);
  for (i = 1; i <= n - 1; i++) f[i] = f[i >> 1] + (i & 1);
  for (i = 0; i <= n - 1; i++) a[i] = c[f[i]];
  for (i = 0; i <= n - 1; i++) F1.a[i] = a[i], F1.b[i] = b[i];
  for (i = 0; i <= n - 1; i++) F2.a[i] = a[i], F2.b[i] = b[i];
  F1.work();
  F2.work();
  mod1 = mod;
  mod2 = (1 << cnt);
  exgcd(mod1, mod2, k1, k2);
  for (i = 0; i <= n - 1; i++) {
    r1 = F1.a[i];
    r2 = F2.a[i];
    ans = (1ll * mod1 * (r2 - r1) % (mod1 * mod2) * k1 + r1) % (mod1 * mod2);
    ans = (ans + mod1 * mod2) % (mod1 * mod2);
    printf("%d\n", ans);
  }
}
