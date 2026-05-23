#include <bits/stdc++.h>
using namespace std;
int Ans[400005], n, m;
int a[400005], b[400005], W[400005], top;
int lc[800005], rc[800005], f[3][800005], rt;
struct O {
  int p, q, x, y, i;
} o[400005];
bool cmo(O a, O b) { return a.x < b.x; }
void build(int &u, int p, int q) {
  u = ++top;
  f[1][u] = f[2][u] = 1000000000;
  if (p == q) {
    f[0][u] = W[p];
    return;
  }
  build(lc[u], p, (p + q) / 2);
  build(rc[u], (p + q) / 2 + 1, q);
  f[0][u] = min(f[0][lc[u]], f[0][rc[u]]);
}
void mody(int u, int p, int q, int k) {
  if (p == q) {
    f[1][u] = b[p] - 2 * a[p];
    f[2][u] = -b[p] - 2 * a[p];
    return;
  }
  if (k <= (p + q) / 2)
    mody(lc[u], p, (p + q) / 2, k);
  else
    mody(rc[u], (p + q) / 2 + 1, q, k);
  f[1][u] = min(f[1][lc[u]], f[1][rc[u]]);
  f[2][u] = min(f[2][lc[u]], f[2][rc[u]]);
}
int qmin(int I, int u, int p, int q, int l, int r) {
  if (l <= p && q <= r) return f[I][u];
  int tmp = 1000000000;
  if (l <= (p + q) / 2) tmp = qmin(I, lc[u], p, (p + q) / 2, l, r);
  if (r > (p + q) / 2) tmp = min(tmp, qmin(I, rc[u], (p + q) / 2 + 1, q, l, r));
  return tmp;
}
void go(O o, int L, int R) {
  if (L > R) return;
  int k1 = upper_bound(b + L, b + R + 1, o.q) - b;
  int k2 = lower_bound(b + L, b + R + 1, o.y) - b;
  if (k1 > k2) swap(k1, k2);
  int ans;
  if (L <= k1 - 1) {
    ans = o.q < b[L];
    if (b[L] < o.y)
      ans += o.y + o.x + o.p + qmin(2, 1, 1, n, L, k1 - 1);
    else
      ans += o.x + o.p - o.y + qmin(1, 1, 1, n, L, k1 - 1);
    Ans[o.i] = min(Ans[o.i], ans);
  }
  if (k1 <= k2 - 1) {
    ans = o.q < b[k1];
    if (b[k1] < o.y)
      ans += o.y + o.x + o.p + qmin(2, 1, 1, n, k1, k2 - 1);
    else
      ans += o.x + o.p - o.y + qmin(1, 1, 1, n, k1, k2 - 1);
    Ans[o.i] = min(Ans[o.i], ans);
  }
  if (k2 <= R) {
    ans = o.q < b[k2];
    if (b[k2] < o.y)
      ans += o.y + o.x + o.p + qmin(2, 1, 1, n, k2, R);
    else
      ans += o.x + o.p - o.y + qmin(1, 1, 1, n, k2, R);
    Ans[o.i] = min(Ans[o.i], ans);
  }
}
void solve() {
  top = 0;
  for (int i = 1, j = 1; i <= n && j <= m; ++i) {
    while (top && b[top] >= W[i]) --top;
    a[++top] = i;
    b[top] = W[i];
    mody(1, 1, n, top);
    for (; j <= m && o[j].x == i; ++j)
      if (o[j].p <= o[j].x) {
        int k = lower_bound(a + 1, a + top + 1, o[j].p) - a;
        go(o[j], 1, k - 1);
        int q = min(o[j].q, b[k]);
        int t = lower_bound(b + k, b + top + 1, o[j].y) - b;
        if (t <= top)
          Ans[o[j].i] = min(Ans[o[j].i], o[j].x - o[j].p + abs(b[t] - o[j].y) +
                                             (int)(q < b[t]));
        if (--t >= k)
          Ans[o[j].i] = min(Ans[o[j].i], o[j].x - o[j].p + abs(b[t] - o[j].y) +
                                             (int)(q < b[t]));
        Ans[o[j].i] = min(Ans[o[j].i], o[j].x - o[j].p + abs(q - o[j].y));
      } else {
        int tmp = o[j].q;
        o[j].q = min(tmp, qmin(0, 1, 1, n, o[j].x, o[j].p));
        go(o[j], 1, top);
        o[j].q = tmp;
      }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &W[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &o[i].p, &o[i].q, &o[i].x, &o[i].y);
    o[i].i = i;
    Ans[i] = abs(o[i].x - o[i].p) + 1 + o[i].y;
  }
  sort(o + 1, o + m + 1, cmo);
  top = 0;
  build(rt, 1, n);
  solve();
  for (int i = 1; i <= n / 2; ++i) swap(W[i], W[n - i + 1]);
  for (int i = 1; i <= m / 2; ++i) swap(o[i], o[m - i + 1]);
  for (int i = 1; i <= m; ++i) o[i].x = n - o[i].x + 1, o[i].p = n - o[i].p + 1;
  top = 0;
  build(rt, 1, n);
  solve();
  for (int i = 1; i <= m; ++i) printf("%d\n", Ans[i]);
  return 0;
}
