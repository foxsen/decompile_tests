#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int n, m;
int f[maxn];
int diameter[maxn];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
vector<int> G[maxn];
int d1[maxn], d2[maxn];
int vis[maxn], t;
queue<int> q;
int bfs1(int u, int d[]) {
  t++;
  q.push(u);
  d[u] = 0;
  vis[u] = t;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (vis[v] == t) continue;
      q.push(v);
      d[v] = d[u] + 1;
      vis[v] = t;
    }
  }
  return u;
}
int bfs2(int u, int fa, int tag) {
  int ret = -1;
  t++;
  q.push(u);
  d2[u] = 0;
  vis[u] = t;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    f[u] = fa;
    if (d1[u] + d2[u] == tag) {
      if (d1[u] == tag / 2 || d2[u] == tag / 2) ret = u;
    }
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (vis[v] == t) continue;
      q.push(v);
      d2[v] = d2[u] + 1;
      vis[v] = t;
    }
  }
  return ret;
}
void bfs3(int u) {
  int fa = u;
  t++;
  q.push(u);
  vis[u] = t;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    f[u] = fa;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (vis[v] == t) continue;
      q.push(v);
      vis[v] = t;
    }
  }
}
int main() {
  int Q;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      int x = bfs1(i, d1);
      int y = bfs1(x, d1);
      int z = bfs2(y, y, d1[y]);
      diameter[z] = d1[z] + d2[z];
      bfs3(z);
    }
  for (int i = 0; i < Q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      x--;
      x = find(x);
      printf("%d\n", diameter[x]);
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      x--, y--;
      x = find(x), y = find(y);
      if (x != y) {
        if (diameter[x] > diameter[y]) {
          int t1 = diameter[x] / 2, t2 = diameter[x] - t1;
          int t3 = diameter[y] / 2, t4 = diameter[y] - t3;
          f[y] = x;
          diameter[x] = max(max(diameter[x], diameter[y]), t2 + t4 + 1);
        } else {
          int t1 = diameter[x] / 2, t2 = diameter[x] - t1;
          int t3 = diameter[y] / 2, t4 = diameter[y] - t3;
          f[x] = y;
          diameter[y] = max(max(diameter[x], diameter[y]), t2 + t4 + 1);
        }
      }
    }
  }
}
