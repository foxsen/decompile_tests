#include <bits/stdc++.h>
struct t3 {
  int s, d;
  long long w;
} E[100001], bed[25];
std::vector<std::pair<int, long long> > G[100001];
std::vector<std::pair<int, long long> > T[100001];
long long xd[100001], dist[25][100001];
int arr[100001], rank[100001], lvl[100001], par[100001];
int P[100001][20];
bool vis[100001];
class dsu {
 public:
  int root(int x);
  bool find_union(int x, int y);
};
int dsu::root(int x) { return ((x == arr[x]) ? x : (arr[x] = root(arr[x]))); }
bool dsu::find_union(int x, int y) {
  int rx = root(x);
  int ry = root(y);
  if (rx == ry) return 0;
  if (rank[rx] < rank[ry]) {
    int tmp = rx;
    rx = ry;
    ry = tmp;
  }
  arr[ry] = rx;
  if (rank[rx] == rank[ry]) rank[rx]++;
  return 1;
}
bool cmpx(t3 X, t3 Y) { return (X.w < Y.w); }
void dfs_visit(int s, int p) {
  par[s] = 0;
  lvl[s] = 0;
  if (p != -1) {
    par[s] = p;
    lvl[s] += (1 + lvl[p]);
  }
  for (int i = 0, j = (int)T[s].size(); i < j; i++) {
    if (T[s][i].first != p) {
      xd[T[s][i].first] = (T[s][i].second + xd[s]);
      dfs_visit(T[s][i].first, s);
    }
  }
  return;
}
void ST_build(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; (1 << j) <= n; j++) P[i][j] = -1;
  }
  for (int i = 1; i <= n; i++) P[i][0] = par[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (P[i][j - 1] != -1) P[i][j] = P[P[i][j - 1]][j - 1];
    }
  }
  return;
}
int LCA_find(int p, int q) {
  if (lvl[p] < lvl[q]) {
    int tmp = p;
    p = q;
    q = tmp;
  }
  int l2 = 0;
  for (l2 = 1; (1 << l2) <= lvl[p]; l2++)
    ;
  l2--;
  for (int i = l2; i >= 0; i--) {
    if ((lvl[p] - (1 << i)) >= lvl[q]) p = P[p][i];
  }
  if (p == q) return p;
  for (int i = l2; i >= 0; i--) {
    if ((P[p][i] != -1) && (P[p][i] != P[q][i])) {
      p = P[p][i];
      q = P[q][i];
    }
  }
  return par[p];
}
void dijkstra_find(int px, int s, int n) {
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int> >,
                      std::greater<std::pair<long long, int> > >
      Q;
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
    dist[px][i] = 1000000000000LL;
  }
  dist[px][s] = 0;
  Q.push(std::make_pair(0, s));
  while (!Q.empty()) {
    std::pair<long long, int> p = Q.top();
    Q.pop();
    int u = p.second;
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto v : G[u]) {
      if (!vis[v.first] && (dist[px][v.first] > dist[px][u] + v.second)) {
        dist[px][v.first] = dist[px][u] + v.second;
        Q.push(std::make_pair(dist[px][v.first], v.first));
      }
    }
  }
  return;
}
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int s, d;
    long long w;
    std::cin >> s >> d >> w;
    G[s].push_back(std::make_pair(d, w));
    G[d].push_back(std::make_pair(s, w));
    E[i] = {s, d, w};
  }
  for (int i = 1; i <= n; i++) {
    arr[i] = i;
    rank[i] = 0;
  }
  std::sort(E, E + m, cmpx);
  dsu V;
  int cx = 0;
  for (int i = 0; i < m; i++) {
    if (V.find_union(E[i].s, E[i].d)) {
      T[E[i].s].push_back(std::make_pair(E[i].d, E[i].w));
      T[E[i].d].push_back(std::make_pair(E[i].s, E[i].w));
    } else
      bed[cx++] = {E[i].s, E[i].d, E[i].w};
  }
  dfs_visit(1, -1);
  ST_build(n);
  for (int i = 0; i < cx; i++) dijkstra_find(i, bed[i].s, n);
  int q;
  std::cin >> q;
  while (q--) {
    int s, d;
    std::cin >> s >> d;
    long long ans = 1000000000000LL;
    int lc = LCA_find(s, d);
    ans = std::min(ans, xd[s] + xd[d] - 2 * xd[lc]);
    for (int i = 0; i < cx; i++) ans = std::min(ans, dist[i][s] + dist[i][d]);
    std::cout << ans << "\n";
  }
  return 0;
}
