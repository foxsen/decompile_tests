#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, w[N], m;
vector<int> v[N], vv[N];
struct SegmentTree {
  struct TNode {
    int l, r, v;
  } t[N << 2];
  int lazy[N << 2];
  inline int lc(int pos) { return pos << 1; }
  inline int rc(int pos) { return pos << 1 | 1; }
  inline void pushup(int pos) { t[pos].v = min(t[lc(pos)].v, t[rc(pos)].v); }
  void build(int pos, int l, int r) {
    t[pos].l = l;
    t[pos].r = r;
    if (l == r) {
      t[pos].v = l - m - 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(lc(pos), l, mid);
    build(rc(pos), mid + 1, r);
    pushup(pos);
  }
  void pushdown(int pos) {
    if (!lazy[pos]) return;
    t[lc(pos)].v += lazy[pos];
    t[rc(pos)].v += lazy[pos];
    lazy[lc(pos)] += lazy[pos];
    lazy[rc(pos)] += lazy[pos];
    lazy[pos] = 0;
  }
  void modify(int pos, int r, int v) {
    if (!r) return;
    if (t[pos].r == r) {
      t[pos].v += v;
      lazy[pos] += v;
      return;
    }
    int mid = (t[pos].l + t[pos].r) >> 1;
    pushdown(pos);
    if (r <= mid)
      modify(lc(pos), r, v);
    else
      modify(lc(pos), mid, v), modify(rc(pos), r, v);
    pushup(pos);
  }
  int query(int pos, int p) {
    if (t[pos].l == t[pos].r) return t[pos].v;
    int mid = (t[pos].l + t[pos].r) >> 1;
    pushdown(pos);
    if (p <= mid)
      return query(lc(pos), p);
    else
      return query(rc(pos), p);
  }
} tr;
int mn[N], sc[N], b[N], bmx;
void build(int pos, int fa, int id, int mnv, int sec) {
  if (w[pos] <= mnv) {
    sec = mnv;
    mnv = w[pos];
    id = pos;
  } else if (w[pos] <= sec)
    sec = w[pos];
  mn[pos] = mnv;
  sc[pos] = sec;
  vv[id].push_back(pos);
  for (auto &i : v[pos])
    if (i != fa) build(i, pos, id, mnv, sec);
}
void modify(int num, int v) {
  int l = 1, r = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (b[mid] <= num)
      l = mid + 1;
    else
      r = mid - 1;
  }
  if (r) tr.modify(1, r, v);
}
int ans = INT_MAX;
void solve(int pos, int fa) {
  if (w[pos] < bmx && bmx - w[pos] < ans) {
    for (auto &i : vv[pos]) modify(mn[pos], -1), modify(min(sc[i], bmx), 1);
    if (tr.t[1].v >= 0) ans = bmx - w[pos];
    for (auto &i : vv[pos]) modify(mn[pos], 1), modify(min(sc[i], bmx), -1);
  }
  for (auto &i : v[pos])
    if (i != fa) solve(i, pos);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  int t1, t2;
  for (int i = 1; i < n; i++)
    cin >> t1 >> t2, v[t1].push_back(t2), v[t2].push_back(t1);
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  build(1, 0, 0, INT_MAX, INT_MAX);
  tr.build(1, 1, m);
  for (int i = 1; i <= n; i++) modify(mn[i], 1);
  for (int i = m; i > 0; --i)
    if (tr.query(1, i) < 0) {
      bmx = b[i];
      break;
    }
  if (bmx)
    solve(1, 0);
  else
    ans = 0;
  cout << (ans == INT_MAX ? -1 : ans) << endl;
  return 0;
}
