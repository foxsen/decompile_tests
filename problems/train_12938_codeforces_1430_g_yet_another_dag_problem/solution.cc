#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const long long INF = 1e15;
int n, m;
int cnt = 1;
int s, t;
struct Edge {
  int to, nx;
  long long cap;
} edge[MAXN << 1];
int head[MAXN];
void _add(int from, int to, long long cap) {
  cnt++;
  edge[cnt].to = to;
  edge[cnt].cap = cap;
  edge[cnt].nx = head[from];
  head[from] = cnt;
}
void add(int from, int to, long long cap) {
  _add(from, to, cap);
  _add(to, from, 0);
}
int dis[MAXN];
bool bfs() {
  memset(dis, 0, sizeof(dis));
  queue<int> q;
  q.push(s);
  dis[s] = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = head[now]; i; i = edge[i].nx) {
      int to = edge[i].to;
      if (dis[to] || edge[i].cap == 0) continue;
      dis[to] = dis[now] + 1;
      q.push(to);
    }
  }
  return dis[t];
}
long long dfs(int now, long long flow) {
  if (now == t) return flow;
  long long ret = 0;
  for (int i = head[now]; i; i = edge[i].nx) {
    int to = edge[i].to;
    if (dis[to] != dis[now] + 1 || edge[i].cap == 0) continue;
    long long tmp = dfs(to, min(flow, edge[i].cap));
    if (tmp <= 0) continue;
    flow -= tmp;
    edge[i].cap -= tmp;
    edge[i ^ 1].cap += tmp;
    ret += tmp;
    if (flow <= 0) break;
  }
  return ret;
}
long long dinic() {
  long long ret = 0;
  while (bfs()) {
    ret += dfs(s, INF);
  }
  return ret;
}
bool vis[MAXN];
void min_cut(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = head[now]; i; i = edge[i].nx) {
      int to = edge[i].to;
      if (edge[i].cap && !vis[to]) {
        vis[to] = true;
        q.push(to);
      }
    }
  }
}
void solve() {
  long long ret = dinic();
  min_cut(s);
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (vis[i * (n + 1) + j + 1]) j++;
    printf("%d ", j);
  }
  printf("\n");
}
long long a[MAXN];
void init() {
  scanf("%d%d", &n, &m);
  s = n * (n + 1) + 5;
  t = s + 1;
  for (int i = 1, u, v, w; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    swap(u, v);
    u--;
    v--;
    a[u] -= w;
    a[v] += w;
    for (int j = 0; j < n; j++) {
      add(u * (n + 1) + j, v * (n + 1) + j + 1, INF);
    }
  }
  for (int i = 0; i < n; i++) {
    add(s, i * (n + 1), INF);
    add(i * (n + 1) + n, t, INF);
    for (int j = 0; j < n; j++) {
      add(i * (n + 1) + j, i * (n + 1) + j + 1, 2 * a[i] * j + 1e9);
    }
  }
}
int main() {
  int T = 1;
  while (T--) {
    init();
    solve();
  }
  return 0;
}
