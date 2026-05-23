#include <bits/stdc++.h>
using namespace std;
struct Dominator {
  struct min_DSU {
    vector<int> par, val;
    vector<int> const& semi;
    min_DSU(int N, vector<int> const& semi) : par(N, -1), val(N), semi(semi) {
      iota(val.begin(), val.end(), 0);
    }
    void comp(int x) {
      if (par[par[x]] != -1) {
        comp(par[x]);
        if (semi[val[par[x]]] < semi[val[x]]) val[x] = val[par[x]];
        par[x] = par[par[x]];
      }
    }
    int f(int x) {
      if (par[x] == -1) return x;
      comp(x);
      return val[x];
    }
    void link(int x, int p) { par[x] = p; }
  };
  int N;
  vector<vector<int>> G, rG;
  vector<int> idom, order;
  Dominator(int _N) : N(_N), G(N), rG(N) {}
  void add_edge(int a, int b) {
    G[a].emplace_back(b);
    rG[b].emplace_back(a);
  }
  vector<int> calc_dominators(int S) {
    idom.assign(N, -1);
    vector<int> par(N, -1), semi(N, -1);
    vector<vector<int>> bu(N);
    stack<int> s;
    s.emplace(S);
    while (!s.empty()) {
      int a = s.top();
      s.pop();
      if (semi[a] == -1) {
        semi[a] = order.size();
        order.emplace_back(a);
        for (int i = 0; i < (int)G[a].size(); ++i) {
          if (semi[G[a][i]] == -1) {
            par[G[a][i]] = a;
            s.push(G[a][i]);
          }
        }
      }
    }
    min_DSU uni(N, semi);
    for (int i = (int)order.size() - 1; i > 0; --i) {
      int w = order[i];
      for (int f : rG[w]) {
        int oval = semi[uni.f(f)];
        if (oval >= 0 && semi[w] > oval) semi[w] = oval;
      }
      bu[order[semi[w]]].push_back(w);
      uni.link(w, par[w]);
      while (!bu[par[w]].empty()) {
        int v = bu[par[w]].back();
        bu[par[w]].pop_back();
        int u = uni.f(v);
        idom[v] = semi[u] < semi[v] ? u : par[w];
      }
    }
    for (int i = 1; i < (int)order.size(); ++i) {
      int w = order[i];
      if (idom[w] != order[semi[w]]) idom[w] = idom[idom[w]];
    }
    idom[S] = -1;
    return idom;
  }
};
using ll = long long;
vector<ll> dijkstras(vector<vector<pair<int, ll>>> const& g, int s) {
  vector<ll> ret(g.size(), numeric_limits<ll>::max() / 2);
  ret[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.emplace(ret[s], s);
  while (!pq.empty()) {
    ll curd;
    int c;
    tie(curd, c) = pq.top();
    pq.pop();
    if (curd != ret[c]) continue;
    for (auto const& e : g[c]) {
      if (ret[e.first] > ret[c] + e.second) {
        ret[e.first] = ret[c] + e.second;
        pq.emplace(ret[e.first], e.first);
      }
    }
  }
  return ret;
}
namespace FIO {
char buf[32 * 1042 | 1];
int bc = 0, be = 0;
char gc() {
  if (bc >= be) {
    be = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[be] = bc = 0;
  }
  return buf[bc++];
}
void readint() {}
template <typename T, typename... S>
void readint(T& a, S&... b) {
  a = 0;
  int x = gc();
  while (x < '0' || x > '9') x = gc();
  while (x >= '0' && x <= '9') {
    a = a * 10 + x - '0';
    x = gc();
  }
  readint(b...);
}
}  // namespace FIO
using FIO::readint;
signed CF757F() {
  int n, m, S;
  readint(n, m, S);
  vector<vector<pair<int, ll>>> G(n + 1);
  while (m--) {
    int a, b, c;
    readint(a, b, c);
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }
  vector<ll> dist = dijkstras(G, S);
  Dominator D(n + 1);
  for (int i = 0; i <= n; ++i) {
    for (auto e : G[i]) {
      if (dist[e.first] == dist[i] + e.second) {
        D.add_edge(i, e.first);
      }
    }
  }
  vector<int> id = D.calc_dominators(S);
  vector<int> hit(n + 1, 0);
  for (int i = (int)D.order.size() - 1; i > 0; --i) {
    int e = D.order[i];
    hit[id[e]] += ++hit[e];
  }
  hit[S] = 0;
  int ans = *max_element(hit.begin(), hit.end());
  printf("%d\n", ans);
  return 0;
}
int main() {
  return CF757F();
  cerr << "go\n";
  int N, M, a, b;
  while (cin >> N >> M && N) {
    vector<pair<int, int>> ed;
    Dominator D(N);
    while (M--) {
      cin >> a >> b;
      D.add_edge(a, b);
      ed.emplace_back(a, b);
    }
    vector<int> id = D.calc_dominators(0);
    copy(id.begin(), id.end(), ostream_iterator<int>(cerr, " "));
    cerr << "\n";
  }
}
