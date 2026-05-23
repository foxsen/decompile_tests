#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int jt = 998244353;
int n, m;
int jc[1 << 19], fjc[1 << 19];
int l[1 << 19], r[1 << 19];
int a[44], b[44];
int xf[1 << 19], cs[1 << 19][44];
int lgl[1 << 19];
int ksmii(int a, int b) {
  if (!b) return 1;
  int x = ksmii(a, b >> 1);
  x = 1ll * x * x % jt;
  if (b & 1) x = 1ll * x * a % jt;
  return x;
}
int inline C(int a, int b) {
  if (b < 0 || a < b) return 0;
  return 1ll * jc[a] * fjc[b] % jt * fjc[a - b] % jt;
}
int main() {
  jc[0] = 1;
  for (int i = 1; i <= (500000); i++) jc[i] = 1ll * jc[i - 1] * i % jt;
  fjc[500000] = ksmii(jc[500000], jt - 2);
  for (int i = (500000); ((-1) > 0 ? i <= (1) : i >= (1)); i += (-1))
    fjc[i - 1] = 1ll * fjc[i] * i % jt;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= (n); i++) {
    scanf("%d%d", l + i, r + i);
    xf[l[i]]++;
    xf[r[i] + 1]--;
  }
  for (int i = 1; i <= (n); i++) {
    xf[i] += xf[i - 1];
    for (int j = 0; j < (m << 1 | 1); j++) {
      cs[i][j] = (cs[i - 1][j] + C(xf[i] - j, i - j)) % jt;
    }
  }
  for (int i = 0; i < (m); i++) scanf("%d%d", a + i, b + i);
  int ans = 0;
  for (int i = 0; i < (1 << m); i++) {
    int ls = 1, rs = n, ts = 0;
    for (int j = 0; j < (m); j++) {
      if (!((i >> j) & 1)) continue;
      if (lgl[a[j]] != i) {
        lgl[a[j]] = i;
        ts++;
      }
      if (lgl[b[j]] != i) {
        lgl[b[j]] = i;
        ts++;
      }
      ls = max(ls, max(l[a[j]], l[b[j]]));
      rs = min(rs, min(r[a[j]], r[b[j]]));
    }
    if (ls > rs) continue;
    int res = (cs[rs][ts] - cs[ls - 1][ts] + jt) % jt;
    if (__builtin_popcount(i) % 2)
      ans = (ans - res + jt) % jt;
    else
      ans = (ans + res) % jt;
  }
  printf("%d\n", ans);
  return 0;
}
