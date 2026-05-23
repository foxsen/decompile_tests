#include <bits/stdc++.h>
using namespace std;
int const p = 998244353;
int pw(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % p;
    x = 1ll * x * x % p;
    y >>= 1;
  }
  return res;
}
int a[65537], iv[65537], b[65537], sum[195], inv[65537], cnt[131075], st[195],
    top, tmp[20], tmp2[20], tmp3[20], f[65537];
long long tmp4[20];
vector<int> v[65537];
map<vector<int>, int> mp;
void getexp(int *f, int *g, int n) {
  g[0] = 1;
  for (int i = 1; i < n; i++) {
    g[i] = 0;
    f[i] = 1ll * f[i] * i % p;
    for (int j = 0; j < i; j++)
      g[i] = (g[i] + 1ll * f[j + 1] * g[i - j - 1]) % p;
    g[i] = 1ll * g[i] * iv[i] % p;
  }
}
void getln(int *f, int *g, int n) {
  g[0] = 0;
  for (int i = 1; i < n; i++) {
    g[i] = 0;
    for (int j = 1; j < i; j++) g[i] = (g[i] + 1ll * f[j] * g[i - j]) % p;
    g[i] = (1ll * i * f[i] + p - g[i]) % p;
  }
  for (int i = 1; i < n; i++) g[i] = 1ll * g[i] * iv[i] % p;
}
int mod(int x) { return x >= p ? x - p : x; }
int main() {
  iv[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i < 65536; i++)
    iv[i] = 1ll * (p - p / i) * iv[p % i] % p,
    inv[i] = 1ll * inv[i - 1] * iv[i] % p;
  int n, K, c, xorsum = 0;
  scanf("%d%d%d", &n, &K, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), xorsum ^= a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= K; j++) v[i].push_back(a[i] ^ (a[i] - j));
    mp[v[i]]++;
  }
  int t = 0, fac = 1;
  for (auto r : mp) t++, v[t] = r.first, sum[t] = r.second;
  for (int i = 2; i <= K; i++) fac = 1ll * fac * i % p;
  for (int s = 0; s < (1 << c); s++) {
    for (int i = 1; i <= t; i++) {
      int d = 0;
      for (int j = 0; j <= K; j++)
        d |= ((__builtin_popcount(s & v[i][j]) & 1) << j);
      if (!cnt[d]) st[++top] = d;
      cnt[d] += sum[i];
    }
    memset(tmp, 0, sizeof(tmp));
    tmp[0] = 1;
    for (int i = 1; i <= top; i++) {
      for (int j = 0; j <= K; j++)
        if (st[i] & (1 << j))
          tmp2[j] = p - inv[j];
        else
          tmp2[j] = inv[j];
      getln(tmp2, tmp3, K + 1);
      for (int j = 0; j <= K; j++) tmp3[j] = 1ll * tmp3[j] * cnt[st[i]] % p;
      getexp(tmp3, tmp2, K + 1);
      memset(tmp4, 0, sizeof(tmp4));
      for (int j = 0; j <= K; j++)
        for (int k = 0; k <= K - j; k++) tmp4[j + k] += 1ll * tmp2[j] * tmp[k];
      for (int j = 0; j <= K; j++) tmp[j] = tmp4[j] % p;
      cnt[st[i]] = 0;
    }
    top = 0;
    f[s] = 1ll * tmp[K] * fac % p;
  }
  for (int len = 2; len <= (1 << c); len <<= 1)
    for (int i = 0; i < (1 << c); i += len)
      for (int j = i; j < i + (len >> 1); j++) {
        int t = f[j];
        f[j] = mod(f[j] + f[j + (len >> 1)]);
        f[j + (len >> 1)] = mod(t - f[j + (len >> 1)] + p);
      }
  int d = 1ll * pw(1 << c, p - 2) * pw(n, p - 1 - K) % p;
  for (int i = 0; i < (1 << c); i++)
    printf("%lld ", 1ll * f[i ^ xorsum] * d % p);
  return 0;
}
