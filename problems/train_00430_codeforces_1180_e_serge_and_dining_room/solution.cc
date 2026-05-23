#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6, big = 1e18;
long long val[maxn], t[4 * maxn + 5], sum[4 * maxn + 5];
void build(long long v, long long l, long long r) {
  if (l == r - 1) {
    sum[v] = 0;
    t[v] = val[l];
    return;
  }
  long long m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);
  t[v] = max(t[2 * v], t[2 * v + 1]);
  sum[v] = 0;
}
void upd(long long v, long long l, long long r, long long tl, long long tr,
         long long c) {
  if (tr <= l || tl >= r) return;
  if (tl >= l && tr <= r) {
    sum[v] += c;
    return;
  }
  long long tm = (tl + tr) / 2;
  upd(2 * v, l, r, tl, tm, c);
  upd(2 * v + 1, l, r, tm, tr, c);
  t[v] = max(t[2 * v] + sum[2 * v], t[2 * v + 1] + sum[2 * v + 1]);
}
long long get(long long v, long long l, long long r, long long tl,
              long long tr) {
  if (tr <= l || tl >= r) return -big;
  if (tl >= l && tr <= r) return t[v] + sum[v];
  long long tm = (tl + tr) / 2;
  return max(get(2 * v, l, r, tl, tm), get(2 * v + 1, l, r, tm, tr)) + sum[v];
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < m; ++i) cin >> b[i];
  for (long long i = 0; i < maxn; ++i) val[i] = 0;
  build(1, 0, 1e6);
  for (long long i = 0; i < n; ++i) upd(1, 0, a[i], 0, 1e6, 1);
  for (long long i = 0; i < m; ++i) upd(1, 0, b[i], 0, 1e6, -1);
  long long q;
  cin >> q;
  while (q) {
    --q;
    long long type, v, id;
    cin >> type >> id >> v;
    --id;
    if (type == 1) {
      upd(1, 0, a[id], 0, 1e6, -1);
      a[id] = v;
      upd(1, 0, a[id], 0, 1e6, 1);
    } else {
      upd(1, 0, b[id], 0, 1e6, 1);
      b[id] = v;
      upd(1, 0, b[id], 0, 1e6, -1);
    }
    long long l = -1, r = 1e6;
    while (l < r - 1) {
      long long mid = (l + r) / 2;
      if (get(1, mid, 1e6, 0, 1e6) > 0)
        l = mid;
      else
        r = mid;
    }
    if (l == -1)
      cout << "-1\n";
    else
      cout << l + 1 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
