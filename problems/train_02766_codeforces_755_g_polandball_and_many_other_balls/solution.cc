#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1 << 15;
int Jie[N], inv[N], jie[N];
inline int mul(const int &a, const int &b) { return 1ll * a * b % mod; }
inline void add(int &a, const int &b) {
  a += b;
  if (a >= mod) a -= mod;
  return;
}
inline int C(int m, int n) { return mul(jie[m], mul(inv[n], inv[m - n])); }
inline int CC(int m, int n) { return mul(Jie[m], inv[n]); }
int main() {
  int n = 1000000000, k = 32767;
  scanf("%d%d", &n, &k);
  Jie[0] = n;
  jie[0] = 1, inv[0] = inv[1] = 1;
  for (int i = (2); i < (k + 1); ++i)
    inv[i] = -1ll * mod / i * inv[mod % i] % mod + mod;
  for (int i = (1); i < (k + 1); ++i) {
    Jie[i] = n - i;
    jie[i] = mul(jie[i - 1], i);
    inv[i] = mul(inv[i], inv[i - 1]);
  }
  for (int i = (1); i < (min(k, n) + 1); ++i) {
    int ans = 0;
    for (int j = (0); j < (i + 1); ++j) {
      if (n - j < i) break;
      ans = (ans + 1ll * C(i, j) * CC(j, i)) % mod;
    }
    for (int j = (0); j < (k + 1); ++j)
      Jie[j] = 1ll * Jie[j] * (n - i - j) % mod;
    printf("%d ", ans);
  }
  for (int i = (min(k, n) + 1); i < (k + 1); ++i) {
    printf("0 ");
  }
}
