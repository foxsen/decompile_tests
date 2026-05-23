#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 1e9 + 7;
const double db = acos(-1.0);
long long n, i;
pair<long long, long long> p[9999999];
long long t[100000 * 4 + 10];
void upd(long long v, long long l, long long r, long long nm, long long zn) {
  if (l == r) {
    t[v] = zn;
  } else {
    long long mid = (r + l) / 2;
    if (nm <= mid)
      upd(v * 2, l, mid, nm, zn);
    else
      upd(v * 2 + 1, mid + 1, r, nm, zn);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}
long long max_el(long long v, long long l, long long r, long long l1,
                 long long r1) {
  if (l1 > r1) return 0;
  if (l == l1 && r == r1) return t[v];
  long long mid = (r + l) / 2;
  return max(max_el(v * 2, l, mid, l1, min(mid, r1)),
             max_el(v * 2 + 1, mid + 1, r, max(mid + 1, l1), r1));
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    p[i].first = x * 1ll * x * 1ll * y;
    p[i].second = -i;
  }
  sort(p + 1, p + n + 1);
  for (i = 1; i <= n; i++) {
    upd(1, 1, n, -p[i].second, max_el(1, 1, n, 1, -p[i].second) + p[i].first);
  }
  double mx = db * max_el(1, 1, n, 1, n);
  printf("%.9lf", mx);
  return 0;
}
