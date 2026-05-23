#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct Edge { int to, cost; };

template<class T, class Edge> V<T> dijkstra(const VV<Edge>& g, int s = 0) {
  V<T> dist(g.size(), numeric_limits<T>::max());
  using P = pair<T, int>;
  priority_queue< P, V<P>, greater<P> > pque;
  pque.emplace(dist[s] = 0, s);
  while (!pque.empty()) {
    T d; int v;
    tie(d, v) = pque.top(); pque.pop();
    if (d > dist[v]) continue;
    for (const auto& e : g[v]) if (dist[v] + e.cost < dist[e.to]) {
      pque.emplace(dist[e.to] = dist[v] + e.cost, e.to);
    } 
  }
  return dist;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  while (true) {
    int w, h; cin >> w >> h;
    if (!w) break;
    VV<> s(h, V<>(w)); for (auto&& v : s) for (auto&& e : v) cin >> e;
    V<> c(4); for (auto&& e : c) cin >> e;
    V<> di{0, 1, 0, -1}, dj{1, 0, -1, 0};
    auto in = [&](int i, int j) -> bool { return 0 <= i and i < h and 0 <= j and j < w; };
    auto _ = [&](int i, int j) -> int { return i * w + j; };
    VV<Edge> g(4 * h * w);
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) for (int k = 0; k < 4; ++k) {
      for (int x = 0; x < 4; ++x) {
        int ni = i + di[k + x & 3], nj = j + dj[k + x & 3];
        if (!in(ni, nj)) continue;
        g[_(i, j) << 2 | k].emplace_back(Edge{_(ni, nj) << 2 | k + x & 3, x != s[i][j] ? c[x] : 0});
      }
    }
    auto d = dijkstra<int>(g, 0);
    int res = 1e9;
    for (int k = 0; k < 4; ++k) res = min(res, d[_(h - 1, w - 1) << 2 | k]);
    cout << res << '\n';
  }
}
