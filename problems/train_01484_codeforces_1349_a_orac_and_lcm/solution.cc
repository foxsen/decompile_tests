#include <bits/stdc++.h>
using namespace std;
long long n, prim[310000], ans = 1, a[310000], pan[310000];
long long Fmin[310000], Smin[310000], b;
long long maxx, poi, tot;
bool v[310000];
long long ksm(long long c, long long d) {
  long long zhi = 1;
  while (d) {
    if (d % 2) zhi *= c;
    c *= c;
    d /= 2;
  }
  return zhi;
}
void oula() {
  for (long long i = 2; i <= 300000; i++) {
    if (!v[i]) prim[++prim[0]] = i, a[i] = i;
    for (long long j = 1; j <= prim[0], prim[j] * i <= 200000; j++) {
      v[i * prim[j]] = 1, a[i * prim[j]] = prim[j];
      if (i % prim[j] == 0) break;
    }
  }
}
void fen() {
  long long qian = 0, tot = 0;
  while (b > 1) {
    tot++;
    if (a[b] != qian) {
      pan[qian]++;
      if (tot <= Fmin[qian]) {
        Smin[qian] = Fmin[qian];
        Fmin[qian] = tot;
      } else if (tot < Smin[qian])
        Smin[qian] = tot;
      tot = 0;
      qian = a[b];
    }
    b /= a[b];
  }
  tot++;
  if (a[b] != qian) {
    pan[qian]++;
    if (tot <= Fmin[qian]) {
      Smin[qian] = Fmin[qian];
      Fmin[qian] = tot;
    } else if (tot < Smin[qian])
      Smin[qian] = tot;
    tot = 0;
    qian = a[b];
  }
}
signed main() {
  memset(Fmin, 127, sizeof(Fmin));
  scanf("%d", &n);
  oula();
  for (long long i = 1; i <= n; i++) {
    scanf("%d", &b);
    fen();
  }
  for (long long i = 1; prim[i] <= 200000; i++) {
    if (pan[prim[i]] < n - 1) continue;
    if (pan[prim[i]] == n - 1)
      ans *= ksm(prim[i], Fmin[prim[i]]);
    else if (pan[prim[i]] == n) {
      if (Smin[prim[i]] == 0 || Smin[prim[i]] == 2139062143) continue;
      ans *= ksm(prim[i], Smin[prim[i]]);
    }
  }
  cout << ans << endl;
  return 0;
}
