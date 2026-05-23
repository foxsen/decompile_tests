#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
template <class T>
inline void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x / 10) write(x / 10);
  putchar('0' + x % 10);
}
const int N = 4e5 + 10;
int ch[N][26], pre[N], mxl[N], last = 1, cnt = 1, pos[N], dfn[N], tot, bel[N],
                               prt[N], sz[N], son[N], dep[N];
struct Edge {
  int b, nt;
} e[N];
int e_num, head[N];
inline void anode(int u, int v) {
  e[++e_num].b = v;
  e[e_num].nt = head[u];
  head[u] = e_num;
}
inline int Extend(int c) {
  int p = last, np = ++cnt;
  last = np;
  mxl[np] = mxl[p] + 1;
  for (; p && !ch[p][c]; p = pre[p]) ch[p][c] = np;
  if (!p) {
    pre[np] = 1;
    return np;
  }
  int q = ch[p][c], nq = ++cnt;
  if (mxl[q] == mxl[p] + 1) {
    pre[np] = q;
    --cnt;
    return np;
  }
  memcpy(ch[nq], ch[q], sizeof(ch[q]));
  mxl[nq] = mxl[p] + 1, pre[nq] = pre[q], pre[q] = pre[np] = nq;
  for (; ch[p][c] == q; p = pre[p]) ch[p][c] = nq;
  return np;
}
inline void dfs1(int u) {
  sz[u] = 1;
  for (int i = head[u]; i; i = e[i].nt) {
    int v = e[i].b;
    dep[v] = dep[u] + 1, prt[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
inline void dfs2(int u, int chain) {
  dfn[u] = ++tot;
  bel[u] = chain;
  if (son[u]) dfs2(son[u], chain);
  for (int i = head[u]; i; i = e[i].nt) {
    int v = e[i].b;
    if (v == son[u]) continue;
    dfs2(v, v);
  }
}
inline int LCA(int x, int y) {
  while (bel[x] != bel[y]) {
    if (dep[bel[x]] < dep[bel[y]]) swap(x, y);
    x = prt[bel[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  return y;
}
int numa[N], numb[N], sza[N], szb[N], stk[N], top, b[N], ntot;
inline bool cmp(const int &a, const int &b) { return dfn[a] < dfn[b]; }
vector<int> ve[N];
char s[N];
inline void vbuild(int x) {
  if (top == 1) {
    stk[++top] = x;
    return;
  }
  int lca = LCA(x, stk[top]);
  if (lca == stk[top]) {
    stk[++top] = x;
    return;
  }
  while (top > 1 && dfn[stk[top - 1]] >= dfn[lca])
    ve[stk[top - 1]].push_back(stk[top]), --top;
  if (stk[top] != lca) ve[lca].push_back(stk[top]), stk[top] = lca;
  stk[++top] = x;
}
inline void dfs3(int u) {
  sza[u] = numa[u], szb[u] = numb[u];
  for (int i = 0, siz = ve[u].size(); i < siz; i++) {
    int v = ve[u][i];
    dfs3(v);
    sza[u] += sza[v], szb[u] += szb[v];
  }
}
long long ans;
inline void dp(int u) {
  ans += 1ll * numb[u] * sza[u] * mxl[u];
  for (int i = 0, siz = ve[u].size(); i < siz; i++) {
    int v = ve[u][i];
    dp(v);
    ans += 1ll * szb[v] * (sza[u] - sza[v]) * mxl[u];
  }
  ve[u].clear();
}
int mem[N], mtot;
int main() {
  int n, Q;
  read(n), read(Q);
  scanf("%s", s + 1);
  for (int i = n; i >= 1; i--) pos[i] = Extend(s[i] - 'a');
  for (int i = 2; i <= cnt; i++) anode(pre[i], i);
  dfs1(1), dfs2(1, 1);
  while (Q--) {
    for (int i = 1; i <= mtot; i++) numa[mem[i]] = numb[mem[i]] = 0;
    ans = ntot = mtot = 0;
    int cnta, cntb;
    read(cnta), read(cntb);
    for (int i = 1; i <= cnta; i++) {
      int x;
      read(x);
      mem[++mtot] = pos[x];
      ++numa[pos[x]];
      b[++ntot] = pos[x];
    }
    for (int i = 1; i <= cntb; i++) {
      int x;
      read(x);
      mem[++mtot] = pos[x];
      ++numb[pos[x]];
      b[++ntot] = pos[x];
    }
    sort(b + 1, b + 1 + ntot, cmp);
    ntot = unique(b + 1, b + 1 + ntot) - b - 1;
    stk[top = 1] = 1;
    for (int i = 1; i <= ntot; i++) vbuild(b[i]);
    while (top > 1) ve[stk[top - 1]].push_back(stk[top]), --top;
    dfs3(1);
    dp(1);
    write(ans), putchar('\n'), putchar('\n');
  }
  return 0;
}
