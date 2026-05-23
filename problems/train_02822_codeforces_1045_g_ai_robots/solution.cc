#include <bits/stdc++.h>
using ll = long long;
using namespace std;
long long n, k;
const long long maxn = 3e5 + 10;
struct Point {
  long long p, l, r, len, q;
};
Point a[maxn];
long long b[maxn], c[maxn];
inline long long low(const long long& x) { return x & -x; }
inline void add(long long x, long long y) {
  for (; x <= n; x += low(x)) c[x] += y;
}
inline long long qry(long long x) {
  long long ans = 0;
  for (; x; x ^= low(x)) ans += c[x];
  return ans;
}
long long ans = 0;
void solve(long long l, long long r) {
  if (l == r) return;
  long long mid = l + r >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  long long L = l, R = l - 1;
  for (register long long i = (mid + 1); i <= (r); ++i) {
    while (L <= mid && a[i].q - a[L].q > k) add(a[L++].p, -1);
    while (R < mid && a[R + 1].q - a[i].q <= k) add(a[++R].p, 1);
    ans += qry(a[i].r) - qry(a[i].l - 1);
  }
  for (register long long i = (L); i <= (R); ++i) add(a[i].p, -1);
  sort(a + l, a + r + 1,
       [](const Point& a, const Point& b) { return a.q < b.q; });
}
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> k;
  for (register long long i = (1); i <= (n); ++i)
    cin >> a[i].p >> a[i].len >> a[i].q;
  long long len = 0;
  for (register long long i = (1); i <= (n); ++i) b[++len] = a[i].p;
  sort(b + 1, b + len + 1);
  len = unique(b + 1, b + len + 1) - b - 1;
  for (register long long i = (1); i <= (n); ++i) {
    a[i].l = lower_bound(b + 1, b + len + 1, a[i].p - a[i].len) - b;
    a[i].r = upper_bound(b + 1, b + len + 1, a[i].p + a[i].len) - b - 1;
    a[i].p = lower_bound(b + 1, b + len + 1, a[i].p) - b;
  }
  sort(a + 1, a + n + 1,
       [](const Point& a, const Point& b) { return a.len > b.len; });
  solve(1, n);
  cout << ans << '\n';
  return 0;
}
