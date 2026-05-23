#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int mod = 1051131, inv_2 = (mod + 1) >> 1;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
int n, s;
long long t;
int a[(1 << 25) + 5], b[(1 << 25) + 5], pw[mod + 5], vis[mod + 5];
inline long long qpow(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) res = res * a % mod;
  return res;
}
inline void add(int &x, int y) {
  x += y;
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
}
inline int ad(int x, int y) {
  x += y;
  return x >= mod ? x -= mod : x;
}
inline int dc(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
inline void dft(int *a) {
  for (int i = 2; i <= n; i <<= 1)
    for (int p = i >> 1, j = 0; j < n; j += i)
      for (int k = j; k < j + p; k++) {
        int x = a[k], y = a[k + p];
        a[k] = ad(x, y), a[k + p] = dc(x, y);
      }
}
inline void idft(int *a) {
  for (int i = 2; i <= n; i <<= 1)
    for (int p = i >> 1, j = 0; j < n; j += i)
      for (int k = j; k < j + p; k++) {
        int x = a[k], y = a[k + p];
        a[k] = 1ll * ad(x, y) * inv_2 % mod,
        a[k + p] = 1ll * dc(x, y) * inv_2 % mod;
      }
}
int main() {
  n = (1 << read());
  scanf("%lld", &t);
  s = read();
  t %= 700752;
  for (int i = 0; i < s; i++) a[i] = read();
  for (int i = s; i < n; i++) a[i] = (101ll * a[i - s] + 10007) % mod;
  b[0] = 1;
  for (int i = 1; i < n; i++) b[i] = (i & -i) % mod;
  dft(a);
  dft(b);
  for (int i = 0; i < n; i++)
    if (b[i]) vis[b[i]] = 1;
  for (int i = 0; i < mod; i++)
    if (vis[i]) pw[i] = qpow(i, t);
  for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * pw[b[i]] % mod;
  idft(a);
  int ans = 0;
  for (int i = 0; i < n; i++) ans ^= a[i];
  printf("%d", ans);
  return 0;
}
