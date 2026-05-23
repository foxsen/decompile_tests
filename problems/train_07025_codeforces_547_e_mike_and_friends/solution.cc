#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    res = (res << 3) + (res << 1) + ch - '0';
    ch = getchar();
  }
  return res * f;
}
namespace qiqi {
const int N = 1e6 + 5;
int n, Q, ch[N][26], fail[N], cnt = 1, pos[N], ans[N], fa[N], dfn[N], ecnt,
                              head[N], siz[N];
char s[N];
struct Qry {
  int k, p, v, id;
  inline bool friend operator<(Qry a, Qry b) { return a.p < b.p; }
} q[N];
struct Edge {
  int v, nxt;
} e[N << 1];
inline void add(int u, int v) {
  e[++ecnt] = (Edge){v, head[u]};
  head[u] = ecnt;
}
struct BIT {
  int a[N];
  inline int lbt(int x) { return x & (-x); }
  inline void upd(int x, int k) {
    while (x <= cnt) {
      a[x] += k;
      x += lbt(x);
    }
  }
  inline int qry(int x) {
    int res = 0;
    while (x) {
      res += a[x];
      x -= lbt(x);
    }
    return res;
  }
} bit;
inline void build() {
  queue<int> q;
  for (int i = (0); i <= (25); ++i)
    if (ch[1][i]) {
      fail[ch[1][i]] = 1;
      q.push(ch[1][i]);
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = (0); i <= (25); ++i) {
      if (ch[u][i]) {
        if (!(fail[ch[u][i]] = ch[fail[u]][i])) fail[ch[u][i]] = 1;
        q.push(ch[u][i]);
      } else
        ch[u][i] = ch[fail[u]][i];
    }
  }
  for (int i = (2); i <= (cnt); ++i) add(fail[i], i);
}
void dfs(int u) {
  dfn[u] = ++cnt;
  siz[u] = 1;
  for (int i = head[u], v = e[i].v; i; v = e[i = e[i].nxt].v) {
    dfs(v);
    siz[u] += siz[v];
  }
}
void main() {
  int x, l, r, p;
  n = read();
  Q = read();
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", s + 1);
    x = 1;
    l = strlen(s + 1);
    for (int j = (1); j <= (l); ++j) {
      if (!ch[x][s[j] - 'a']) fa[ch[x][s[j] - 'a'] = ++cnt] = x;
      x = ch[x][s[j] - 'a'];
    }
    pos[i] = x;
  }
  build();
  cnt = 0;
  dfs(1);
  for (int i = (1); i <= (Q); ++i) {
    l = read();
    r = read();
    x = read();
    q[(i << 1) - 1] = (Qry){x, l - 1, -1, i};
    q[i << 1] = (Qry){x, r, 1, i};
  }
  sort(q + 1, q + (Q << 1 | 1));
  p = 0;
  for (int i = (1); i <= (Q << 1); ++i) {
    while (p < q[i].p) {
      x = pos[++p];
      while (x) {
        bit.upd(dfn[x], 1);
        x = fa[x];
      }
    }
    x = pos[q[i].k];
    ans[q[i].id] +=
        q[i].v * (bit.qry(dfn[x] + siz[x] - 1) - bit.qry(dfn[x] - 1));
  }
  for (int i = (1); i <= (Q); ++i) printf("%d\n", ans[i]);
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
