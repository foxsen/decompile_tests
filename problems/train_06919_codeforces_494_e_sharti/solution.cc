#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
struct node {
  int x, l, r, t;
  node(int x = 0, int l = 0, int r = 0, int t = 0) : x(x), l(l), r(r), t(t) {}
  bool operator<(const node& a) const { return x < a.x; }
} a[N];
int tag[N * 60], sm[N * 60], lc[N * 60], rc[N * 60], q1, q2, q3, clk;
void ps(int o, int l, int r) {
  if (tag[o])
    sm[o] = (l - 1) ^ r;
  else
    sm[o] = sm[lc[o]] ^ sm[rc[o]];
}
void modify(int& o, int l, int r) {
  if (!o) o = ++clk;
  if (q1 <= l && r <= q2) {
    tag[o] += q3;
    return ps(o, l, r);
  }
  int mid = (l + r) / 2;
  if (q1 <= mid) modify(lc[o], l, mid);
  if (q2 > mid) modify(rc[o], mid + 1, r);
  ps(o, l, r);
}
int rt, ans, K;
void solve(int l, int r) {
  int tmp = ((l - 1) ^ r) & sm[rt];
  for (int i = 0; i < 30; ++i)
    if (tmp >> i & 1) {
      ans ^= min(K, 1 << i);
      if (i) ans ^= min(K, 1 << (i - 1));
    }
}
int n, m, cnt;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> K;
  for (; K & (K - 1); K &= K - 1)
    ;
  for (int i = 1; i <= m; ++i) {
    int xl, xr, yl, yr;
    cin >> xl >> yl >> xr >> yr;
    a[++cnt] = node(xl, yl, yr, 1);
    a[++cnt] = node(xr + 1, yl, yr, -1);
  }
  sort(a + 1, a + cnt + 1);
  for (int i = 1; i <= cnt; ++i) {
    if (a[i].x != a[i - 1].x) solve(a[i - 1].x, a[i].x - 1);
    q1 = a[i].l;
    q2 = a[i].r;
    q3 = a[i].t;
    modify(rt, 1, n);
  }
  cout << (ans ? "Hamed\n" : "Malek\n");
  return 0;
}
