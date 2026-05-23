#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 100007, __ = _ << 1;
const long long linf = 0x3f3f3f3f3f3f3f3f;
int to[__], ne[__], he[_] = {0}, ecnt = 1;
inline void adde(int a, int b) {
  to[++ecnt] = b, ne[ecnt] = he[a], he[a] = ecnt;
}
inline void addde(int a, int b) { adde(a, b), adde(b, a); }
int n, m, qn;
int fa[_] = {0}, dep[_] = {0}, sz[_] = {0}, mxch[_] = {0};
void dfs(int x, int ff) {
  fa[x] = ff, dep[x] = dep[ff] + 1, sz[x] = 1, mxch[x] = 0;
  for (int i = he[x]; i; i = ne[i]) {
    int b = to[i];
    if (b == ff) continue;
    dfs(b, x), sz[x] += sz[b];
    if (sz[mxch[x]] < sz[b]) mxch[x] = b;
  }
}
int dfn[_] = {0}, rdfn[_] = {0}, ndf[_] = {0}, top[_] = {0}, dcnt = 0;
void dfs2(int x, int tp) {
  dfn[x] = ++dcnt, rdfn[dcnt] = x, top[x] = tp;
  if (mxch[x]) dfs2(mxch[x], tp);
  for (int i = he[x]; i; i = ne[i]) {
    int b = to[i];
    if (b == fa[x] || b == mxch[x]) continue;
    dfs2(b, b);
  }
  ndf[x] = dcnt;
}
vector<int> hav[_];
struct cxk {
  int x;
  long long v;
  cxk(int x_ = 0, long long v_ = linf) { x = x_, v = v_; }
  friend bool operator<(cxk a, cxk b) {
    if (a.v != b.v) return a.v < b.v;
    return a.x < b.x;
  }
};
const int _t = _ << 2;
cxk t[_t];
long long tadd[_t];
void up(int x) { t[x] = min(t[(x << 1)], t[(x << 1 | 1)]); }
void putadd(int x, long long d) { t[x].v += d, tadd[x] += d; }
void dwn(int x) {
  if (tadd[x])
    putadd((x << 1), tadd[x]), putadd((x << 1 | 1), tadd[x]), tadd[x] = 0;
}
void plant(int x, int l, int r) {
  tadd[x] = 0;
  if (l == r) {
    t[x] = hav[l].empty() ? cxk() : cxk(l, hav[l].back());
    return;
  }
  plant((x << 1), l, ((l + r) >> 1)),
      plant((x << 1 | 1), ((l + r) >> 1) + 1, r), up(x);
}
void change(int x, int l, int r, int tl, int tr, long long dlt) {
  if (tl <= l && r <= tr) {
    putadd(x, dlt);
    return;
  }
  dwn(x);
  if (tl <= ((l + r) >> 1)) change((x << 1), l, ((l + r) >> 1), tl, tr, dlt);
  if (tr > ((l + r) >> 1))
    change((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr, dlt);
  up(x);
}
void dating(int x, int l, int r, int tar) {
  if (l == r) {
    if (!hav[l].empty()) hav[l].pop_back();
    t[x] = hav[l].empty() ? cxk() : cxk(l, hav[l].back() + tadd[x]);
    return;
  }
  dwn(x);
  if (tar <= ((l + r) >> 1))
    dating((x << 1), l, ((l + r) >> 1), tar);
  else
    dating((x << 1 | 1), ((l + r) >> 1) + 1, r, tar);
  up(x);
}
cxk finder(int x, int l, int r, int tl, int tr) {
  if (tl <= l && r <= tr) return t[x];
  dwn(x);
  if (tr <= ((l + r) >> 1)) return finder((x << 1), l, ((l + r) >> 1), tl, tr);
  if (tl > ((l + r) >> 1))
    return finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr);
  return min(finder((x << 1), l, ((l + r) >> 1), tl, tr),
             finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr));
}
cxk founder(int a, int b) {
  cxk ans;
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]]) swap(a, b);
    ans = min(ans, finder(1, 1, n, dfn[top[a]], dfn[a])), a = fa[top[a]];
  }
  if (dep[a] > dep[b]) swap(a, b);
  return min(ans, finder(1, 1, n, dfn[a], dfn[b]));
}
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty(), qn = ty();
  for (int i = 1, a, b; i < n; i++) a = ty(), b = ty(), addde(a, b);
  dfs(1, 0), dfs2(1, 1);
  for (int i = 1; i <= m; i++) hav[dfn[ty()]].emplace_back(i);
  for (int i = 1; i <= n; i++)
    sort(hav[i].begin(), hav[i].end(), greater<int>());
  plant(1, 1, n);
  for (int qq = 1; qq <= qn; qq++) {
    int op = ty();
    if (op == 1) {
      int a = ty(), b = ty(), lim = ty();
      vector<int> ans;
      while (lim--) {
        int ret = founder(a, b).x;
        if (ret <= 0) break;
        ans.emplace_back(hav[ret].back()), dating(1, 1, n, ret);
      }
      cout << ans.size();
      for (auto i : ans) cout << ' ' << i;
      cout << lf;
    }
    if (op == 2) {
      int a = ty(), b = ty();
      change(1, 1, n, dfn[a], ndf[a], b);
    }
  }
  return 0;
}
