#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
template <typename T>
void maxtt(T &t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T &t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
string direc = "RDLU";
const long long MOD2 = (long long)998244353 * (long long)998244353;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 998244353) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
long long a[200135];
struct lsp {
  long long a[60] = {0};
  const int maxBit = 54;
  bool insert(long long x) {
    for (int i = maxBit; ~i; i--)
      if (x & (1LL << i)) {
        if (a[i] != 0)
          x ^= a[i];
        else {
          for (int(j) = 0; (j) < (int)(i); (j)++)
            if (x & (1LL << j)) x ^= a[j];
          for (int j = i + 1; j <= maxBit; j++)
            if (a[j] & (1LL << i)) a[j] ^= x;
          a[i] = x;
          return 1;
        }
      }
    return 0;
  }
  lsp getOrthogonal(int m) {
    lsp res;
    vector<int> vp;
    for (int j = m - 1; j >= 0; j--)
      if (!a[j]) {
        vp.push_back(j);
        res.a[j] |= 1LL << j;
      }
    for (int j = m - 1; j >= 0; j--)
      if (a[j]) {
        int cc = 0;
        for (int z = m - 1; z >= 0; z--)
          if (!a[z]) {
            long long w = (a[j] >> z) & 1;
            res.a[vp[cc]] |= w << j;
            cc++;
          }
      }
    return res;
  }
} sp;
int p[66], q[66];
void ppt() {
  for (int i = 0; i <= m; i++) {
    printf("%lld ", (long long)p[i] * fastPow(2, n - k) % 998244353);
  }
  exit(0);
}
vector<long long> bs;
inline void dfs(int *p, int k, int i, long long x) {
  if (i == k) {
    p[__builtin_popcountll(x)]++;
    return;
  }
  dfs(p, k, i + 1, x);
  dfs(p, k, i + 1, x ^ bs[i]);
}
void calsm(lsp sp, int *p, int k) {
  bs.clear();
  for (int(j) = 0; (j) < (int)(sp.maxBit); (j)++)
    if (sp.a[j]) bs.push_back(sp.a[j]);
  assert(bs.size() == k);
  dfs(p, k, 0, 0);
}
void calbg() {
  vector<vector<int>> C(60, vector<int>(60, 0));
  C[0][0] = 1;
  for (int i = 1; i <= 55; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 998244353;
    }
  }
  vector<vector<int>> w(m + 1, vector<int>(m + 1, 0));
  for (int c = 0; c <= m; c++) {
    for (int d = 0; d <= m; d++) {
      for (int j = 0; j <= c; j++) {
        int val = (long long)C[d][j] * C[m - d][c - j] % 998244353;
        if (j % 2 == 0)
          addmod(w[c][d], val);
        else
          addmod(w[c][d], 998244353 - val);
      }
    }
  }
  lsp B = sp.getOrthogonal(m);
  calsm(B, q, m - k);
  for (int(c) = 0; (c) < (int)(m + 1); (c)++) {
    for (int d = 0; d <= m; d++) {
      addmod(p[c], (long long)q[d] * w[c][d] % 998244353);
    }
  }
  int tmp = fastPow(2, m - k);
  tmp = fastPow(tmp, 998244353 - 2);
  for (int(c) = 0; (c) < (int)(m + 1); (c)++)
    p[c] = (long long)p[c] * tmp % 998244353;
  ppt();
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%lld", a + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) k += sp.insert(a[i]);
  if (k <= m / 2) {
    calsm(sp, p, k);
    ppt();
  }
  calbg();
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
