#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T& N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T& x, T_&... y) {
  re(x), re(y...);
}
int m, n, t = 1, st, en;
template <class T>
struct MCMF {
  struct edge {
    int v;
    T cap, cost;
    edge() {}
    edge(int v = 0, T cap = 0, T cost = 0) : v(v), cap(cap), cost(cost) {}
  };
  int m, n, st, en;
  T cost, flow, inf = typeid(T) == typeid(int) ? 1e9 : 1e18;
  vector<edge> edges;
  vector<vector<int> > G;
  vector<int> fa, vis;
  vector<T> dis, lim;
  void init(int _n) {
    flow = cost = 0;
    G.assign(n + 1, vector<int>());
    dis.assign(n + 1, inf);
    lim.assign(n + 1, 0);
    fa.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    edges.clear();
    lim[st] = inf;
  }
  void build(int _n) {
    n = _n;
    st = n - 1;
    en = n;
    init(n);
  }
  void build(int _n, int _st, int _en) {
    n = _n;
    st = _st;
    en = _en;
    init(n);
  }
  void add(int u, int v, T cap, T cost) {
    if (u == v) return;
    edges.emplace_back(v, cap, cost);
    edges.emplace_back(u, 0, -cost);
    m = edges.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }
  int spfa() {
    fill(dis.begin(), dis.end(), inf);
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      vis[u] = 0;
      for (int i = 0; i < G[u].size(); i++) {
        edge& e = edges[G[u][i]];
        if (dis[e.v] > dis[u] + e.cost && e.cap) {
          dis[e.v] = dis[u] + e.cost;
          fa[e.v] = G[u][i];
          lim[e.v] = min(lim[u], e.cap);
          if (!vis[e.v]) q.push(e.v), vis[e.v] = 1;
        }
      }
    }
    return dis[en] != inf;
  }
  void find_path() {
    int u = en;
    T _flow = lim[en];
    while (u != st) {
      edge& e = edges[fa[u]];
      edge& _e = edges[fa[u] ^ 1];
      e.cap -= _flow;
      _e.cap += _flow;
      u = _e.v;
    }
    flow += _flow;
    cost += _flow * dis[en];
  }
  T get() {
    while (spfa()) find_path();
    return cost;
  }
};
int a[N << 1];
vector<pair<int, int> > bin[N << 1];
int main() {
  re(n, m);
  for (int i = 0; i < 1 << n; i++) re(a[i]);
  for (int i = 0; i < 1 << n; i++)
    if (__builtin_parity(i)) {
      for (int j = 0; j < n; j++) {
        int to = i ^ (1 << j);
        bin[a[i] + a[to]].push_back({i, to});
      }
    }
  int lef = (2 * n - 1) * (m - 1) + 1;
  vector<pair<int, int> > edges;
  vector<int> pnts;
  for (int i = 2e6; i >= 0 && lef; i--)
    for (auto j : bin[i]) {
      pnts.push_back(j.first);
      pnts.push_back(j.second);
      edges.push_back(j);
      if (!(--lef)) break;
    }
  sort(pnts.begin(), pnts.end());
  pnts.erase(unique(pnts.begin(), pnts.end()), pnts.end());
  MCMF<long long> f;
  f.build(pnts.size() + 10);
  f.add(f.st, f.st - 1, m, 0);
  for (int i : pnts) {
    int pos = lower_bound(pnts.begin(), pnts.end(), i) - pnts.begin() + 1;
    if (__builtin_parity(i))
      f.add(f.st - 1, pos, 1, 0);
    else
      f.add(pos, f.en, 1, 0);
  }
  for (pair<int, int> i : edges) {
    int posl =
        lower_bound(pnts.begin(), pnts.end(), i.first) - pnts.begin() + 1;
    int posr =
        lower_bound(pnts.begin(), pnts.end(), i.second) - pnts.begin() + 1;
    f.add(posl, posr, 1, -(a[i.first] + a[i.second]));
  }
  printf("%lld\n", -f.get());
}
