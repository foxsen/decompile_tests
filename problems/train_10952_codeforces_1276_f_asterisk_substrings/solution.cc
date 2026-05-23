#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m;
char ch[N];
struct SA {
  int sa[N], rk[N], h[N], x[N], y[N], c[N];
  void build_SA() {
    m = 128;
    for (int i = 0; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) c[x[i] = ch[i]]++;
    for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
    for (int i = n; i >= 1; --i) sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k *= 2) {
      int cnt = 0;
      for (int i = n - k + 1; i <= n; ++i) y[++cnt] = i;
      for (int i = 1; i <= n; ++i)
        if (sa[i] > k) y[++cnt] = sa[i] - k;
      for (int i = 0; i <= m; ++i) c[i] = 0;
      for (int i = 1; i <= n; ++i) c[x[i]]++;
      for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
      for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
      swap(x, y);
      x[sa[1]] = 1;
      cnt = 1;
      for (int i = 2; i <= n; ++i) {
        x[sa[i]] =
            (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                ? cnt
                : ++cnt;
      }
      if (cnt == n) break;
      m = cnt;
    }
    for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
    h[1] = 0;
    int lst = 0;
    for (int i = 1; i <= n; ++i) {
      int j = sa[rk[i] - 1];
      if (lst) --lst;
      while (ch[i + lst] == ch[j + lst]) ++lst;
      h[rk[i]] = lst;
    }
  }
  int st[N][21];
  int lg[N];
  inline void init() {
    for (int i = 1; i <= n; ++i) {
      st[i][0] = h[i];
    }
    for (int i = 1; i <= 20; ++i)
      for (int j = 1; j <= n - (1 << i) + 1; ++j)
        st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    lg[1] = 0;
    for (int i = 2; i <= N - 1; ++i) lg[i] = lg[i / 2] + 1;
  }
  inline int lcp(int x, int y) {
    int w1 = x, w2 = y;
    if (w1 > w2) swap(w1, w2);
    int G = lg[w2 - w1];
    return min(st[w1 + 1][G], st[w2 - (1 << G) + 1][G]);
  }
} a;
set<int> s1[N * 2];
int rt[N * 2];
long long val[N * 2];
inline int merge(int x, int y) {
  int w1 = x, w2 = y;
  if (w1 == w2) return w1;
  if (s1[w1].size() > s1[w2].size()) swap(w1, w2);
  for (set<int>::iterator i = s1[w1].begin(); i != s1[w1].end(); ++i) {
    int j = *i;
    set<int>::iterator nxt = s1[w2].upper_bound(j);
    int res = 0, p1, p2;
    p1 = p2 = 0;
    if (nxt != s1[w2].end()) {
      p1 = *nxt;
      res = max(res, a.lcp(p1, j));
    }
    if (nxt != s1[w2].begin()) {
      p2 = *(--nxt);
      res = max(res, a.lcp(p2, j));
    }
    if (p1 && p2) {
      assert(a.lcp(p1, p2) + res == a.lcp(j, p1) + a.lcp(p2, j));
    }
    val[w2] += n - a.sa[j] + 1 - res;
    s1[w2].insert(j);
  }
  s1[w1].clear();
  return w2;
}
long long ans;
struct SAM {
  int nxt[N * 2][26], l[N * 2], fa[N * 2], lst, cnt, pos[N * 2];
  inline void init() {
    lst = cnt = 1;
    memset(nxt[1], 0, sizeof nxt[1]);
    l[1] = fa[1] = 0;
  }
  inline void add(int x, int curp) {
    int np = ++cnt, p = lst;
    lst = np;
    pos[np] = curp;
    memset(nxt[np], 0, sizeof nxt[np]);
    l[np] = l[p] + 1;
    while (p && !nxt[p][x]) nxt[p][x] = np, p = fa[p];
    if (!p)
      fa[np] = 1;
    else {
      int q = nxt[p][x];
      if (l[q] == l[p] + 1)
        fa[np] = q;
      else {
        int nq = ++cnt;
        l[nq] = l[p] + 1;
        fa[nq] = fa[q];
        fa[q] = fa[np] = nq;
        memcpy(nxt[nq], nxt[q], sizeof nxt[q]);
        while (nxt[p][x] == q) nxt[p][x] = nq, p = fa[p];
      }
    }
  }
  int c[N * 2], z[N * 2];
  inline void solve() {
    for (int i = 0; i <= cnt; ++i) c[i] = 0;
    for (int i = 1; i <= cnt; ++i) c[l[i]]++;
    for (int i = 1; i <= cnt; ++i) c[i] += c[i - 1];
    for (int i = 1; i <= cnt; ++i) z[c[l[i]]--] = i;
    for (int i = 1; i <= cnt; ++i) {
      rt[i] = i;
      if (pos[i] && pos[i] <= n - 2) {
        s1[rt[i]].insert(a.rk[pos[i] + 2]);
        val[rt[i]] += n - pos[i] - 1;
      }
    }
    for (int i = cnt; i >= 2; --i) {
      int x = z[i];
      ans += 1LL * (l[x] - l[fa[x]]) * val[rt[x]];
      ans += (l[x] - l[fa[x]]);
      rt[fa[x]] = merge(rt[fa[x]], rt[x]);
    }
  }
  inline void solve_pure() {
    for (int i = 0; i <= cnt; ++i) c[i] = 0;
    for (int i = 1; i <= cnt; ++i) c[l[i]]++;
    for (int i = 1; i <= cnt; ++i) c[i] += c[i - 1];
    for (int i = 1; i <= cnt; ++i) z[c[l[i]]--] = i;
    for (int i = cnt; i >= 2; --i) {
      int x = z[i];
      ans += (l[x] - l[fa[x]]);
    }
  }
} s;
int main() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  a.build_SA();
  a.init();
  s.init();
  for (int i = 1; i <= n; ++i) s.add(ch[i] - 'a', i);
  s.solve();
  s.init();
  for (int i = 1; i <= n - 1; ++i) s.add(ch[i] - 'a', i);
  s.solve_pure();
  s.init();
  for (int i = 2; i <= n; ++i) s.add(ch[i] - 'a', i);
  s.solve_pure();
  ans += 2;
  printf("%lld\n", ans);
  return 0;
}
