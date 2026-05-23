#include <bits/stdc++.h>
using namespace std;
using lld = long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using pli = pair<lld, int>;
using pil = pair<int, lld>;
int n, m;
lld ms[2 * 262144];
lld mt[2 * 262144];
pii a[200009];
pii b[200009];
void update(int dep, int ql, int qr, int ll, int rr, int v) {
  if (ql <= ll && rr <= qr) {
    mt[dep] += v;
    return;
  }
  if (qr < ll || rr < ql) return;
  update(dep * 2, ql, qr, ll, (ll + rr) / 2, v);
  update(dep * 2 + 1, ql, qr, (ll + rr) / 2 + 1, rr, v);
  ms[dep] = min(ms[dep * 2] + mt[dep * 2], ms[dep * 2 + 1] + mt[dep * 2 + 1]);
}
lld getms(int dep, int ql, int qr, int ll, int rr) {
  if (ql <= ll && rr <= qr) {
    return ms[dep] + mt[dep];
  }
  if (qr < ll || rr < ql) return 1000000000000009LL;
  lld p = getms(dep * 2, ql, qr, ll, (ll + rr) / 2);
  lld q = getms(dep * 2 + 1, ql, qr, (ll + rr) / 2 + 1, rr);
  return min(p, q) + mt[dep];
}
int main() {
  int i, j, k;
  int t = 1, tv = 0;
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i].first);
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i].second);
    }
    for (i = 0; i < n; i++) {
      b[a[i].first - 1] = pii(i, a[i].second);
    }
    for (i = 0; i < n; i++) {
      ms[i + 262144 + 1] = ms[i + 262144] + a[i].second;
    }
    for (; i + 1 < 262144; i++) {
      ms[i + 262144 + 1] = ms[i + 262144];
    }
    for (i = 262144 - 1; i > 0; i--) {
      ms[i] = min(ms[i * 2], ms[i * 2 + 1]);
    }
    lld res = getms(1, 1, n - 1, 0, 262144 - 1);
    for (i = 0; i < n; i++) {
      j = b[i].first;
      update(1, 0, j, 0, 262144 - 1, b[i].second);
      update(1, j + 1, 262144 - 1, 0, 262144 - 1, -b[i].second);
      lld cur = getms(1, 1, n - 1, 0, 262144 - 1);
      res = min(res, cur);
    }
    printf("%lld\n", res);
  }
}
