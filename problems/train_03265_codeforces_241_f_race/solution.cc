#include <bits/stdc++.h>
using namespace std;
int n, m, k, pn;
char s[111][111];
int dxy[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
struct edge {
  int v, w, next;
  edge() {}
  edge(int _v, int _w, int _next) {
    v = _v;
    w = _w;
    next = _next;
  }
} e[200011];
int head[100011], sz;
void init() {
  memset(head, -1, sizeof(head));
  sz = 0;
}
void insert(int u, int v, int w) {
  e[++sz] = edge(v, w, head[u]);
  head[u] = sz;
}
struct node {
  int v, d;
  node() {}
  node(int _v, int _d) {
    v = _v;
    d = _d;
  }
  bool operator<(const node &a) const { return d > a.d; }
};
priority_queue<node> pq;
bool vis[100011];
int pos[31][2], rs, cs, re, ce, dis[31][100011], lst[31][100011], pth[10000011],
    tpth[10011];
char t[100011];
void dijkstra(int s, int *dis, int *lst) {
  for (int i = 1; i <= n * m; ++i) dis[i] = 0x3f3f3f3f;
  memset(vis, 0, sizeof(vis));
  pq.push(node(s, 0));
  dis[s] = 0;
  lst[s] = -1;
  while (!pq.empty()) {
    int p = pq.top().v;
    pq.pop();
    if (vis[p]) continue;
    vis[p] = 1;
    if (::s[(p - 1) / m + 1][(p - 1) % m + 1] <= 'z' &&
        ::s[(p - 1) / m + 1][(p - 1) % m + 1] >= 'a' && p != s)
      continue;
    for (int i = head[p]; ~i; i = e[i].next)
      if (dis[e[i].v] > dis[p] + e[i].w)
        dis[e[i].v] = dis[p] + e[i].w, lst[e[i].v] = p,
        pq.push(node(e[i].v, dis[e[i].v]));
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  init();
  for (int i = 0; i <= n; ++i) s[i][0] = s[i][m + 1] = '#';
  for (int i = 0; i <= m; ++i) s[0][i] = s[n + 1][i] = '#';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < 4; ++k)
        if (s[i + dxy[k][0]][j + dxy[k][1]] != '#')
          insert(((i - 1) * m + j), ((i + dxy[k][0] - 1) * m + j + dxy[k][1]),
                 s[i][j] >= '0' && s[i][j] <= '9' ? s[i][j] - '0' : 1);
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] >= 'a' && s[i][j] <= 'z')
        pos[s[i][j] - 'a' + 1][0] = i, pos[s[i][j] - 'a' + 1][1] = j;
  scanf("%d%d%s%d%d", &rs, &cs, t + 1, &re, &ce);
  pos[27][0] = rs;
  pos[27][1] = cs;
  pos[28][0] = re;
  pos[28][1] = ce;
  for (int i = 1; i <= 28; ++i)
    if (pos[i][0]) dijkstra(((pos[i][0] - 1) * m + pos[i][1]), dis[i], lst[i]);
  int q = strlen(t + 1);
  t[0] = 'a' + 26;
  t[++q] = 'a' + 27;
  for (int i = 1; i <= q; ++i) {
    int u = ((pos[t[i] - 'a' + 1][0] - 1) * m + pos[t[i] - 'a' + 1][1]), tn = 0;
    while (~u) {
      tpth[++tn] = u;
      u = lst[t[i - 1] - 'a' + 1][u];
    }
    for (int j = tn - 1; j; --j) pth[++pn] = tpth[j];
  }
  pth[0] = ((rs - 1) * m + cs);
  int cur = 0, ans = pn;
  for (int i = 0; i <= pn; ++i) {
    char c = s[(pth[i] - 1) / m + 1][(pth[i] - 1) % m + 1];
    cur += c >= '0' && c <= '9' ? c - '0' : 1;
    if (cur > k) {
      ans = i;
      break;
    }
  }
  printf("%d %d\n", (pth[ans] - 1) / m + 1, (pth[ans] - 1) % m + 1);
  return 0;
}
