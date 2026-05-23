#include <bits/stdc++.h>
using namespace std;
const int B = 1e7 + 10;
int mndv[B], prm[B], nprm;
int mdv[60][2], gdv[60], ndv;
long long phidv[60];
int Ndv;
long long m, x;
inline long long Mul(long long a, long long b, long long mod) {
  a %= mod, b %= mod;
  long long z = (long double)a / mod * b;
  long long res = (unsigned long long)a * b - (unsigned long long)z * mod;
  return (res + mod) % mod;
}
long long Pow(long long a, long long b, long long mod) {
  long long c = 1;
  while (b) {
    if (b & 1) c = Mul(c, a, mod);
    a = Mul(a, a, mod);
    b >>= 1;
  }
  return c;
}
void Init() {
  for (int i = 2; i < B; i++) {
    if (!mndv[i]) prm[++nprm] = mndv[i] = i;
    for (int j = 1; j <= nprm && prm[j] * i < B; j++) {
      mndv[prm[j] * i] = prm[j];
      if (i % prm[j] == 0) continue;
    }
  }
}
void Divide(int g) {
  for (int i = 1; i <= ndv; i++) gdv[i] = 0;
  while (g > 1) {
    gdv[prm[mndv[g]]]++;
    g /= mndv[g];
  }
}
long long Run(const long long& phi, const long long& mod) {
  long long ord = phi, tmpphi = phi;
  for (int i = 1; i <= Ndv; i++)
    if (tmpphi % phidv[i] == 0) {
      int cnt = 0;
      while (tmpphi % phidv[i] == 0) cnt++, tmpphi /= phidv[i];
      long long tdv = 1, mxdv = 1;
      for (int j = 0; j <= cnt; j++, tdv *= phidv[i])
        if (Pow(x, phi / tdv, mod) == 1) mxdv = max(mxdv, tdv);
      ord /= mxdv;
    }
  return phi / ord;
}
int main() {
  Init();
  scanf("%lld%lld", &m, &x);
  long long tmpm = m, phim = m;
  for (int i = 2; i < B; i++)
    if (tmpm % i == 0) {
      phim = phim / i * (i - 1);
      mdv[++ndv][0] = i, prm[i] = ndv;
      while (tmpm % i == 0) mdv[ndv][1]++, tmpm /= i;
    }
  if (tmpm > 1) phim = phim / tmpm * (tmpm - 1);
  long long tmpphi = phim;
  for (int i = 2; i < B; i++)
    if (tmpphi % i == 0) {
      phidv[++Ndv] = i;
      while (tmpphi % i == 0) tmpphi /= i;
    }
  if (tmpphi > 1) phidv[++Ndv] = tmpphi;
  long long ans = 0;
  for (int g = 1; g <= m / g; g++)
    if (m % g == 0) {
      Divide(g);
      long long phi = g;
      for (int i = 1; i <= ndv; i++)
        if (gdv[i]) phi = phi / mdv[i][0] * (mdv[i][0] - 1);
      if (tmpm > 1 && g % tmpm == 0) phi = phi / tmpm * (tmpm - 1);
      ans += Run(phi, g);
      if (m / g != g) {
        phi = m / g;
        for (int i = 1; i <= ndv; i++)
          if (gdv[i] < mdv[i][1]) phi = phi / mdv[i][0] * (mdv[i][0] - 1);
        if (tmpm > 1 && g % tmpm) phi = phi / tmpm * (tmpm - 1);
        ans += Run(phi, m / g);
      }
    }
  printf("%lld\n", ans);
  return 0;
}
