#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 6e5 + 10;
int n, m, q, k, head[N], tot, st[M], ed[M], ans[N];
char s[M];
struct node {
  int to, nxt;
  char c;
} e[N << 1];
void add(int x, int y, char c) {
  e[++k].to = y;
  e[k].nxt = head[x];
  head[x] = k;
  e[k].c = c;
}
namespace SA {
int sa[M], rnk[M], x[M], y[M], height[M], c[M], minn[M][20], getlog[M];
void work() {
  int m = 255;
  for (int i = 1; i <= tot; i++) c[x[i] = s[i]]++;
  for (int i = 1; i <= m; i++) c[i] += c[i - 1];
  for (int i = tot; i; i--) sa[c[x[i]]--] = i;
  for (int k = 1; k <= tot; k <<= 1) {
    int now = 0;
    for (int i = tot - k + 1; i <= tot; i++) y[++now] = i;
    for (int i = 1; i <= tot; i++)
      if (sa[i] > k) y[++now] = sa[i] - k;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= tot; i++) c[x[y[i]]]++;
    for (int i = 1; i <= m; i++) c[i] += c[i - 1];
    for (int i = tot; i; i--) sa[c[x[y[i]]]--] = y[i];
    swap(x, y);
    now = 1;
    x[sa[1]] = 1;
    for (int i = 2; i <= tot; i++)
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                     ? now
                     : ++now;
    if (now == tot) break;
    m = now;
  }
  for (int i = 1; i <= tot; i++) rnk[sa[i]] = i;
  int k = 0;
  for (int i = 1; i <= tot; i++) {
    if (rnk[i] == 1) continue;
    int j = sa[rnk[i] - 1];
    if (k) k--;
    while (i + k <= tot && j + k <= tot && s[i + k] == s[j + k]) k++;
    height[rnk[i]] = k;
  }
  for (int i = 2; i <= tot; i++) minn[i][0] = height[i];
  for (int j = 1; j <= 19; j++)
    for (int i = 2; i + (1 << j) - 1 <= tot; i++)
      minn[i][j] = min(minn[i][j - 1], minn[i + (1 << j - 1)][j - 1]);
  for (int i = 2; i <= tot; i++) getlog[i] = getlog[i >> 1] + 1;
}
int query(int x, int y) {
  if (x == y) return tot - x + 1;
  x = rnk[x];
  y = rnk[y];
  if (x > y) swap(x, y);
  x++;
  int k = getlog[y - x + 1];
  return min(minn[x][k], minn[y - (1 << k) + 1][k]);
}
}  // namespace SA
namespace TREE {
int sz[N], son[N], fa[N], dep[N];
char val[N];
void dfs1(int u, int lst, char c) {
  sz[u] = 1;
  dep[u] = dep[lst] + 1;
  fa[u] = lst;
  val[u] = c;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == lst) continue;
    dfs1(v, u, e[i].c);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}
int top[N], dfn[N], ord[N], cnt, pnt1[N], pnt2[N];
void dfs2(int u, int lst, int tp) {
  dfn[u] = ++cnt;
  ord[cnt] = u;
  top[u] = tp;
  if (son[u]) dfs2(son[u], u, tp);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == lst || v == son[u]) continue;
    dfs2(v, u, v);
  }
}
void merge() {
  for (int i = 1; i <= n; i++) s[++tot] = val[ord[i]], pnt1[ord[i]] = tot;
  s[++tot] = '#';
  for (int i = n; i; i--) s[++tot] = val[ord[i]], pnt2[ord[i]] = tot;
}
int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  return y;
}
vector<pair<int, int> > vec1, vec2, vec;
int comp(int mid) {
  int pos = SA::sa[mid];
  for (auto it : vec) {
    int lcp = SA::query(it.first, pos), len = it.second - it.first + 1;
    if (lcp >= len)
      pos += len;
    else {
      if (s[pos + lcp] < s[it.first + lcp]) return 0;
      return 1;
    }
  }
  return 2;
}
pair<int, int> work(int x, int y) {
  int z = lca(x, y);
  vec1.clear();
  vec2.clear();
  vec.clear();
  while (top[x] != top[z]) {
    vec1.push_back(make_pair(pnt2[x], pnt2[top[x]]));
    x = fa[top[x]];
  }
  if (x != z) vec1.push_back(make_pair(pnt2[x], pnt2[son[z]]));
  while (top[y] != top[z]) {
    vec2.push_back(make_pair(pnt1[top[y]], pnt1[y]));
    y = fa[top[y]];
  }
  if (y != z) vec2.push_back(make_pair(pnt1[son[z]], pnt1[y]));
  reverse(vec2.begin(), vec2.end());
  for (auto it : vec1) vec.push_back(it);
  for (auto it : vec2) vec.push_back(it);
  int l = 1, r = tot, mid, resl = tot + 1;
  while (l <= r) {
    mid = l + r >> 1;
    int tmp = comp(mid);
    if (tmp == 2)
      resl = min(resl, mid), r = mid - 1;
    else if (tmp == 1)
      r = mid - 1;
    else
      l = mid + 1;
  }
  l = 1;
  r = tot;
  int resr = 0;
  while (l <= r) {
    mid = l + r >> 1;
    int tmp = comp(mid);
    if (tmp == 2)
      resr = max(resr, mid), l = mid + 1;
    else if (tmp == 1)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return make_pair(resl, resr);
}
}  // namespace TREE
struct data {
  int ql, qr, ord, opt;
  data(int ql = 0, int qr = 0, int ord = 0, int opt = 0)
      : ql(ql), qr(qr), ord(ord), opt(opt) {}
};
vector<data> qry[M];
namespace BIT {
int tr[M];
void update(int x) {
  for (; x <= tot; x += x & (-x)) tr[x]++;
}
int query(int x) {
  int res = 0;
  for (; x; x -= x & (-x)) res += tr[x];
  return res;
}
void work() {
  for (int i = 1; i <= tot; i++) {
    update(SA::sa[i]);
    for (auto it : qry[i])
      ans[it.ord] += it.opt * (query(it.qr) - query(it.ql - 1));
  }
}
}  // namespace BIT
int main() {
  scanf("%d%d%d", &n, &m, &q);
  char tmp[M];
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d%s", &x, &y, tmp + 1), add(x, y, tmp[1]), add(y, x, tmp[1]);
  for (int i = 1; i <= m; i++) {
    scanf("%s", tmp + 1);
    int len = strlen(tmp + 1);
    st[i] = tot + 1;
    for (int j = 1; j <= len; j++) s[++tot] = tmp[j];
    ed[i] = tot;
    s[++tot] = '#';
  }
  TREE::dfs1(1, 1, '$');
  TREE::dfs2(1, 1, 1);
  TREE::merge();
  SA::work();
  for (int i = 1; i <= q; i++) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    pair<int, int> rge = TREE::work(u, v);
    if (rge.first > rge.second)
      ans[i] = 0;
    else {
      qry[rge.first - 1].push_back(data(st[l], ed[r], i, -1));
      qry[rge.second].push_back(data(st[l], ed[r], i, 1));
    }
  }
  BIT::work();
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
