#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 233, mod = 1e9 + 7;
int n, N, x;
int a[1 << 17], b[1 << 17], c[1 << 17], f[1 << 17], h[18][1 << 17],
    g[18][1 << 17], cnt[1 << 17];
template <typename T>
inline void read(T &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline void FWT_or(int *a) {
  for (int i = 2; i <= N; i <<= 1) {
    for (int j = 0, m = i >> 1; j < N; j += i) {
      for (int k = 0; k < m; k++)
        a[j + k + m] = ((a[j + k] + a[j + k + m]) >= mod
                            ? ((a[j + k] + a[j + k + m]) - mod)
                            : (a[j + k] + a[j + k + m]));
    }
  }
}
inline void IFWT_or(int *a) {
  for (int i = 2; i <= N; i <<= 1) {
    for (int j = 0, m = i >> 1; j < N; j += i) {
      for (int k = 0; k < m; k++)
        a[j + k + m] = ((a[j + k + m] - a[j + k] + mod) >= mod
                            ? ((a[j + k + m] - a[j + k] + mod) - mod)
                            : (a[j + k + m] - a[j + k] + mod));
    }
  }
}
inline void FWT_and(int *a) {
  for (int i = 2; i <= N; i <<= 1) {
    for (int j = 0, m = i >> 1; j < N; j += i) {
      for (int k = 0; k < m; k++)
        a[j + k] = ((a[j + k] + a[j + k + m]) >= mod
                        ? ((a[j + k] + a[j + k + m]) - mod)
                        : (a[j + k] + a[j + k + m]));
    }
  }
}
inline void IFWT_and(int *a) {
  for (int i = 2; i <= N; i <<= 1) {
    for (int j = 0, m = i >> 1; j < N; j += i) {
      for (int k = 0; k < m; k++)
        a[j + k] = ((a[j + k] - a[j + k + m] + mod) >= mod
                        ? ((a[j + k] - a[j + k + m] + mod) - mod)
                        : (a[j + k] - a[j + k + m] + mod));
    }
  }
}
inline void FWT_xor(int *a) {
  for (int i = 2; i <= N; i <<= 1) {
    for (int j = 0, m = i >> 1; j < N; j += i) {
      for (int k = 0; k < m; k++) {
        int x = a[j + k], y = a[j + k + m];
        a[j + k] = ((x + y) >= mod ? ((x + y) - mod) : (x + y));
        a[j + k + m] =
            ((x - y + mod) >= mod ? ((x - y + mod) - mod) : (x - y + mod));
      }
    }
  }
}
inline void IFWT_xor(int *a) {
  for (int i = 2; i <= N; i <<= 1) {
    for (int j = 0, m = i >> 1; j < N; j += i) {
      for (int k = 0; k < m; k++) {
        int x = a[j + k], y = a[j + k + m];
        a[j + k] = 1ll * (x + y) * ((mod + 1) >> 1) % mod;
        a[j + k + m] = 1ll * (x - y + mod) * ((mod + 1) >> 1) % mod;
      }
    }
  }
}
int main() {
  read(n);
  N = 1 << 17;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 17; j++)
      if (i & (1 << j)) cnt[i]++;
  }
  for (int i = 1; i <= n; i++) read(x), g[cnt[x]][x]++, b[x]++, c[x]++;
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i < N; i++)
    f[i] = ((f[i - 1] + f[i - 2]) >= mod ? ((f[i - 1] + f[i - 2]) - mod)
                                         : (f[i - 1] + f[i - 2]));
  for (int i = 0; i <= 17; i++) FWT_or(g[i]);
  for (int i = 1; i <= 17; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k <= i; k++)
        h[i][j] = (h[i][j] + 1ll * g[k][j] * g[i - k][j]) % mod;
    }
    IFWT_or(h[i]);
    for (int j = 0; j < N; j++)
      if (cnt[j] != i) h[i][j] = 0;
    if (i != 17) FWT_or(h[i]);
  }
  for (int i = 1; i < 17; i++) IFWT_or(h[i]);
  for (int i = 0; i < N; i++) a[i] = h[cnt[i]][i];
  FWT_xor(c);
  for (int i = 0; i < N; i++) c[i] = 1ll * c[i] * c[i] % mod;
  IFWT_xor(c);
  for (int i = 0; i < N; i++) a[i] = 1ll * a[i] * f[i] % mod;
  for (int i = 0; i < N; i++) b[i] = 1ll * b[i] * f[i] % mod;
  for (int i = 0; i < N; i++) c[i] = 1ll * c[i] * f[i] % mod;
  FWT_and(a);
  FWT_and(b);
  FWT_and(c);
  for (int i = 0; i < N; i++) a[i] = 1ll * a[i] * b[i] % mod * c[i] % mod;
  IFWT_and(a);
  int ans = 0;
  for (int i = 1; i < N; i <<= 1)
    ans = ((ans + a[i]) >= mod ? ((ans + a[i]) - mod) : (ans + a[i]));
  printf("%d\n", ans);
}
