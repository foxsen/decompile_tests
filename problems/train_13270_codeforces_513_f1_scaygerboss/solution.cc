#include <bits/stdc++.h>
using namespace std;
template <class P, class Q>
inline void smin(P &a, Q b) {
  if (b < a) a = b;
}
template <class P, class Q>
inline void smax(P &a, Q b) {
  if (a < b) a = b;
}
const long long inf = 1LL << 20;
const int maxn = 22 + 2;
int n, m, males, females;
int N;
char s[maxn][maxn];
long long dis[maxn * maxn][maxn * maxn];
vector<int> e;
vector<pair<int, int> > p, q;
pair<int, int> read() {
  int r, c, t;
  cin >> r >> c >> t;
  r--, c--;
  return {r * m + c, t};
}
template <class FlowT>
struct MaxFlow {
  static const int maxn = 10000;
  static const int maxm = 2000000;
  static const FlowT FlowEPS = FlowT(1e-7);
  static const FlowT FlowINF = FlowT(1 << 29);
  int n, m;
  int to[2 * maxm], prv[2 * maxm], hed[maxn];
  FlowT cap[2 * maxm];
  int dis[maxn], pos[maxn];
  void init(int _n) {
    n = _n, m = 0;
    memset(hed, -1, n * sizeof hed[0]);
  }
  inline void add_edge(int x, int y, FlowT c) {
    to[m] = y, cap[m] = c, prv[m] = hed[x], hed[x] = m++;
    to[m] = x, cap[m] = 0, prv[m] = hed[y], hed[y] = m++;
  }
  bool bfs(int source, int sink) {
    static int que[maxn], head, tail;
    memset(dis, -1, n * sizeof dis[0]);
    head = tail = 0;
    dis[source] = 0;
    que[tail++] = source;
    while (head < tail) {
      int u = que[head++];
      for (int e = hed[u]; e != -1; e = prv[e])
        if (cap[e] > FlowEPS && dis[to[e]] == -1)
          dis[to[e]] = dis[u] + 1, que[tail++] = to[e];
      if (dis[sink] != -1) break;
    }
    return dis[sink] != -1;
  }
  FlowT dfs(int u, int sink, FlowT add = FlowINF) {
    if (u == sink) return add;
    FlowT res = 0;
    for (int &e = pos[u]; e != -1; e = prv[e])
      if (cap[e] > FlowEPS && dis[to[e]] == dis[u] + 1) {
        FlowT cur = dfs(to[e], sink, min(add, cap[e]));
        cap[e] -= cur, cap[e ^ 1] += cur, add -= cur, res += cur;
        if (add <= FlowEPS / 2) break;
      }
    return res;
  }
  FlowT getflow(int source, int sink) {
    FlowT flow = 0;
    while (bfs(source, sink)) {
      memcpy(pos, hed, n * sizeof hed[0]);
      flow += dfs(source, sink);
    }
    return flow;
  }
};
MaxFlow<int> g;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> males >> females;
  if (abs(males - females) != 1) {
    cout << -1 << endl;
    return 0;
  }
  int N = n * m;
  for (int i = 0, _n = (int)(n); i < _n; i++) cin >> s[i];
  for (int i = 0, _n = (int)(N); i < _n; i++)
    for (int j = 0, _n = (int)(N); j < _n; j++) dis[i][j] = inf;
  for (int i = 0, _n = (int)(N); i < _n; i++) dis[i][i] = 0;
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int j = 0, _n = (int)(m); j < _n; j++)
      if (s[i][j] == '.')
        for (int ii = 0, _n = (int)(n); ii < _n; ii++)
          for (int jj = 0, _n = (int)(m); jj < _n; jj++)
            if (s[ii][jj] == '.')
              if (abs(i - ii) + abs(j - jj) == 1)
                dis[i * m + j][ii * m + jj] = 1;
  for (int k = 0, _n = (int)(N); k < _n; k++)
    if (s[k / m][k % m] == '.')
      for (int i = 0, _n = (int)(N); i < _n; i++)
        for (int j = 0, _n = (int)(N); j < _n; j++)
          smin(dis[i][j], dis[i][k] + dis[k][j]);
  (males < females ? p : q).push_back(read());
  for (int i = 0, _n = (int)(males); i < _n; i++) p.push_back(read());
  for (int i = 0, _n = (int)(females); i < _n; i++) q.push_back(read());
  smax(males, females);
  smax(females, males);
  long long lo = -1, hi = (1LL << 30) * maxn * maxn;
  int add = 2 * N;
  int tot = 2 + add + males + females;
  int src = tot - 2;
  int snk = tot - 1;
  while (hi - lo > 1) {
    long long md = (lo + hi) / 2;
    g.init(tot);
    for (int i = 0, _n = (int)(males); i < _n; i++) g.add_edge(src, add + i, 1);
    for (int i = 0, _n = (int)(females); i < _n; i++)
      g.add_edge(add + males + i, snk, 1);
    for (int i = 0, _n = (int)(N); i < _n; i++)
      if (s[i / m][i % m] == '.') {
        g.add_edge(2 * i + 0, 2 * i + 1, 1);
        for (int j = 0, _n = (int)(males); j < _n; j++)
          if (dis[p[j].first][i] != inf &&
              dis[p[j].first][i] * p[j].second <= md)
            g.add_edge(add + j, 2 * i + 0, 1);
        for (int j = 0, _n = (int)(females); j < _n; j++)
          if (dis[q[j].first][i] != inf &&
              dis[q[j].first][i] * q[j].second <= md)
            g.add_edge(2 * i + 1, add + males + j, 1);
      }
    if (g.getflow(src, snk) == males)
      hi = md;
    else
      lo = md;
  }
  cout << (hi < (1LL << 30) * maxn * maxn ? hi : -1) << endl;
  return 0;
}
