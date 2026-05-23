#include <bits/stdc++.h>
const int MAXN = 22 + 5;
const int MAXM = 2e5 + 5;
int n, m;
char str[MAXN][MAXN];
inline int id(int i, int j) { return (i - 1) * m + j; }
int dis[MAXN * MAXN][MAXN * MAXN];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
inline void bfs(std::pair<int, int> v, int dis[]) {
  for (int i = 1; i <= n * m; ++i) dis[i] = 1e9 + 114514;
  dis[id(v.first, v.second)] = 0;
  std::queue<std::pair<int, int> > q;
  q.push(v);
  while (!q.empty()) {
    std::pair<int, int> v = q.front();
    q.pop();
    if (str[v.first][v.second] == '#') continue;
    for (int k = 0; k <= 3; ++k) {
      int xx = v.first + dx[k], yy = v.second + dy[k];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && str[xx][yy] != '#' &&
          dis[id(xx, yy)] > 1e9) {
        dis[id(xx, yy)] = dis[id(v.first, v.second)] + 1;
        q.push(std::make_pair(xx, yy));
      }
    }
  }
}
struct Node {
  int x, y, z;
  long long t;
  Node(int x = 0, int y = 0, int z = 0, long long t = 0)
      : x(x), y(y), z(z), t(t) {}
  inline bool operator<(const Node &_) const { return t < _.t; }
};
Node B[MAXM], G[MAXM];
int k;
namespace F {
struct Edge {
  int to, w, nxt;
} e[MAXM << 5];
int S, T, N;
int head[MAXM], cur[MAXM], cnt = 1, dep[MAXM];
int ans = 0;
inline void clear() {
  for (int i = 1; i <= N; ++i) head[i] = cur[i] = 0;
  cnt = 1;
  ans = 0;
}
inline void add(int u, int v, int w) {
  e[++cnt] = (Edge){v, w, head[u]};
  head[u] = cnt;
  e[++cnt] = (Edge){u, 0, head[v]};
  head[v] = cnt;
}
inline bool bfs() {
  for (int i = 0; i <= N; ++i) cur[i] = head[i], dep[i] = 0;
  std::queue<int> q;
  q.push(S);
  dep[S] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = head[v]; i; i = e[i].nxt) {
      if (e[i].w > 0 && !dep[e[i].to]) {
        dep[e[i].to] = dep[v] + 1;
        if (e[i].to == T) return 1;
        q.push(e[i].to);
      }
    }
  }
  return dep[T];
}
inline int dfs(int v, int flow = 1e9) {
  if (v == T) return flow;
  if (!flow) return 0;
  int ans = 0;
  for (int &i = cur[v]; i; i = e[i].nxt) {
    if (e[i].w > 0 && dep[e[i].to] == dep[v] + 1) {
      int t = dfs(e[i].to, std::min(e[i].w, flow));
      if (t > 0) {
        e[i].w -= t;
        e[i ^ 1].w += t;
        flow -= t;
        ans += t;
        if (!flow) return ans;
      }
    }
  }
  if (!ans) dep[v] = 0;
  return ans;
}
inline void Dinic() {
  int flow;
  while (bfs()) {
    while ((flow = dfs(S))) ans += flow;
  }
}
}  // namespace F
std::vector<Node> edge[MAXM], tmp;
int ts[MAXM];
std::mt19937 g32(114514);
inline bool chk(long long lim) {
  F::clear();
  F::N = 2 * n * m + 2 * k + 2;
  F::S = F::N - 1;
  F::T = F::N;
  for (int i = 1; i <= k; ++i)
    F::add(F::S, 2 * n * m + i, 1), F::add(2 * n * m + k + i, F::T, 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) F::add(id(i, j), n * m + id(i, j), 1);
  for (int i = 1; i <= k; ++i) {
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= m; ++y) {
        if (dis[id(B[i].x, B[i].y)][id(x, y)] > 1e9) continue;
        long long d = 1ll * dis[id(B[i].x, B[i].y)][id(x, y)] * B[i].z;
        if (d > lim) continue;
        F::add(n * m + id(x, y), 2 * n * m + k + i, 1);
      }
    }
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= m; ++y) {
        if (dis[id(G[i].x, G[i].y)][id(x, y)] > 1e9) continue;
        long long d = 1ll * dis[id(G[i].x, G[i].y)][id(x, y)] * G[i].z;
        if (d > lim) continue;
        F::add(2 * n * m + i, id(x, y), 1);
      }
    }
  }
  F::Dinic();
  return F::ans == k;
}
int main() {
  int b, g;
  scanf("%d%d%d%d", &n, &m, &b, &g);
  if (std::abs(b - g) != 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) scanf("%s", str[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) bfs(std::make_pair(i, j), dis[id(i, j)]);
  int _, __, ___;
  scanf("%d%d%d", &_, &__, &___);
  for (int i = 1; i <= b; ++i) scanf("%d%d%d", &B[i].x, &B[i].y, &B[i].z);
  for (int i = 1; i <= g; ++i) scanf("%d%d%d", &G[i].x, &G[i].y, &G[i].z);
  k = std::max(b, g);
  if (b < g)
    B[k] = Node(_, __, ___);
  else
    G[k] = Node(_, __, ___);
  long long l = 0, r = 1e18, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (chk(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
