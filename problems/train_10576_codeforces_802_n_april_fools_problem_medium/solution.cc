#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
struct MCMF {
  struct Edge {
    int u, v;
    int cap, cost;
    int prv;
    Edge(int u, int v, int cap, int cost, int prv)
        : u(u), v(v), cap(cap), cost(cost), prv(prv) {}
  };
  int src, snk;
  int par[(3000 + 99)];
  int flow;
  long long cost;
  int idxer;
  int last[(3000 + 99)];
  int n;
  vector<Edge> E;
  long long dist[(3000 + 99)];
  int state[(3000 + 99)];
  deque<int> Q;
  void init(int newN) {
    n = newN;
    memset(last, -1, sizeof last);
    E.clear();
    idxer = 0;
  }
  void add_edge(int u, int v, int cap, int cost) {
    Edge de = Edge(u, v, cap, cost, last[u]);
    Edge re = Edge(v, u, 0, -cost, last[v]);
    last[u] = idxer++;
    last[v] = idxer++;
    E.push_back(de);
    E.push_back(re);
  }
  bool SPFA(int st, int en) {
    static long long inf = 1e18 + 0.5;
    for (int i = 0; i < n; i++) dist[i] = inf, state[i] = 0;
    dist[st] = 0;
    state[st] = 1;
    Q.push_front(st);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop_front();
      state[u] = 2;
      for (int i = last[u]; i != -1; i = E[i].prv) {
        Edge e = E[i];
        if (e.cap == 0) continue;
        int v = e.v;
        int cost = e.cost;
        long long nw = dist[u] + cost;
        if (dist[v] > nw) {
          dist[v] = nw;
          par[v] = i;
          if (state[v] == 0) Q.push_back(v);
          if (state[v] == 2) Q.push_front(v);
          state[v] = 1;
        }
      }
    }
    return dist[en] < inf;
  }
  void augment(int v, int minEdge = INT_MAX) {
    if (v == src) {
      cost = 0;
      flow = minEdge;
      return;
    }
    int idx = par[v];
    augment(E[idx].u, min(minEdge, E[idx].cap));
    E[idx].cap -= flow;
    E[idx ^ 1].cap += flow;
    cost += 1LL * flow * E[idx].cost;
  }
  pair<long long, long long> mcmf() {
    long long mf = 0, mc = 0;
    while (SPFA(src, snk)) {
      augment(snk);
      mf += flow;
      mc += cost;
    }
    return make_pair(mf, mc);
  }
};
int n, K;
const int MAXN = 2200 + 99;
int A[MAXN], B[MAXN];
MCMF graph;
int main() {
  read_file();
  while (scanf("%d%d", &n, &K) != -1) {
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);
    graph.init(n + 3);
    int src = n, snk = n + 1, srcc = n + 2;
    graph.add_edge(srcc, src, K, 0);
    graph.src = srcc, graph.snk = snk;
    for (int i = 0; i < n; i++) {
      graph.add_edge(src, i, 1, A[i]);
      graph.add_edge(i, snk, 1, B[i]);
      if (i != n - 1) graph.add_edge(i, i + 1, K, 0);
    }
    long long ans = graph.mcmf().second;
    printf("%lld\n", ans);
  }
}
